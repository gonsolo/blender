/* SPDX-FileCopyrightText: 2023 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup editor/io
 */

#pragma once

struct wmOperatorType;

void WM_OT_ply_export(wmOperatorType *ot);
void WM_OT_ply_import(wmOperatorType *ot);

namespace blender::ed::io {
void ply_file_handler_add();
}
