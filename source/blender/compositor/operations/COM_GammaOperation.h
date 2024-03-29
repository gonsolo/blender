/* SPDX-FileCopyrightText: 2011 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#pragma once

#include "COM_MultiThreadedRowOperation.h"

namespace blender::compositor {

class GammaOperation : public MultiThreadedRowOperation {
 public:
  GammaOperation();

  void update_memory_buffer_row(PixelCursor &p) override;
};

}  // namespace blender::compositor
