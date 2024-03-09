/* SPDX-FileCopyrightText: 2011 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

#include "COM_AlphaOverPremultiplyOperation.h"

namespace blender::compositor {

AlphaOverPremultiplyOperation::AlphaOverPremultiplyOperation()
{
  flags_.can_be_constant = true;
}

void AlphaOverPremultiplyOperation::update_memory_buffer_row(PixelCursor &p)
{
  for (; p.out < p.row_end; p.next()) {
    const float *color1 = p.color1;
    const float *over_color = p.color2;
    const float value = *p.value;

    /* Zero alpha values should still permit an add of RGB data. */
    if (over_color[3] < 0.0f) {
      copy_v4_v4(p.out, color1);
    }
    else if (value == 1.0f && over_color[3] >= 1.0f) {
      copy_v4_v4(p.out, over_color);
    }
    else {
      const float mul = 1.0f - value * over_color[3];

      p.out[0] = (mul * color1[0]) + value * over_color[0];
      p.out[1] = (mul * color1[1]) + value * over_color[1];
      p.out[2] = (mul * color1[2]) + value * over_color[2];
      p.out[3] = (mul * color1[3]) + value * over_color[3];
    }
  }
}

}  // namespace blender::compositor
