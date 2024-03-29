/* SPDX-FileCopyrightText: 2021 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#include "COM_ConvertColorSpaceOperation.h"

#include "BLI_string.h"

namespace blender::compositor {

ConvertColorSpaceOperation::ConvertColorSpaceOperation()
{
  this->add_input_socket(DataType::Color);
  this->add_output_socket(DataType::Color);
  color_processor_ = nullptr;
}

void ConvertColorSpaceOperation::set_settings(NodeConvertColorSpace *node_color_space)
{
  this->settings_ = node_color_space;
}

void ConvertColorSpaceOperation::init_execution()
{
  if (BLI_strnlen(settings_->from_color_space, sizeof(settings_->from_color_space)) == 0 ||
      BLI_strnlen(settings_->to_color_space, sizeof(settings_->to_color_space)) == 0)
  {
    return;
  }

  int in_colorspace_index = IMB_colormanagement_colorspace_get_named_index(
      settings_->from_color_space);
  int out_colorspace_index = IMB_colormanagement_colorspace_get_named_index(
      settings_->to_color_space);

  if (in_colorspace_index == 0 || out_colorspace_index == 0) {
    return;
  }

  color_processor_ = IMB_colormanagement_colorspace_processor_new(settings_->from_color_space,
                                                                  settings_->to_color_space);
}

void ConvertColorSpaceOperation::update_memory_buffer_partial(MemoryBuffer *output,
                                                              const rcti &area,
                                                              Span<MemoryBuffer *> inputs)
{
  for (BuffersIterator<float> it = output->iterate_with(inputs, area); !it.is_end(); ++it) {
    copy_v4_v4(it.out, it.in(0));
  }

  if (color_processor_ != nullptr) {
    output->apply_processor(*color_processor_, area);
  }
}

void ConvertColorSpaceOperation::deinit_execution()
{
  if (color_processor_ != nullptr) {
    IMB_colormanagement_processor_free(color_processor_);
  }
  this->color_processor_ = nullptr;
}

}  // namespace blender::compositor
