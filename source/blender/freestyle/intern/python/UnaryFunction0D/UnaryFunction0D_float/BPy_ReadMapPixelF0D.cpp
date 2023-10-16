/* SPDX-FileCopyrightText: 2004-2022 Blender Authors
 *
 * SPDX-License-Identifier: GPL-2.0-or-later */

/** \file
 * \ingroup freestyle
 */

#include "BPy_ReadMapPixelF0D.h"

#include "../../../stroke/AdvancedFunctions0D.h"

#ifdef __cplusplus
extern "C" {
#endif

using namespace Freestyle;

///////////////////////////////////////////////////////////////////////////////////////////

//------------------------INSTANCE METHODS ----------------------------------

static char ReadMapPixelF0D___doc__[] =
    "Class hierarchy: :class:`freestyle.types.UnaryFunction0D` > "
    ":class:`freestyle.types.UnaryFunction0DFloat` > :class:`ReadMapPixelF0D`\n"
    "\n"
    ".. method:: __init__(map_name, level)\n"
    "\n"
    "   Builds a ReadMapPixelF0D object.\n"
    "\n"
    "   :arg map_name: The name of the map to be read.\n"
    "   :type map_name: str\n"
    "   :arg level: The level of the pyramid from which the pixel must be\n"
    "      read.\n"
    "   :type level: int\n"
    "\n"
    ".. method:: __call__(it)\n"
    "\n"
    "   Reads a pixel in a map.\n"
    "\n"
    "   :arg it: An Interface0DIterator object.\n"
    "   :type it: :class:`freestyle.types.Interface0DIterator`\n"
    "   :return: A pixel in a map.\n"
    "   :rtype: float\n";

static int ReadMapPixelF0D___init__(BPy_ReadMapPixelF0D *self, PyObject *args, PyObject *kwds)
{
  static const char *kwlist[] = {"map_name", "level", nullptr};
  const char *s;
  int i;

  if (!PyArg_ParseTupleAndKeywords(args, kwds, "si", (char **)kwlist, &s, &i)) {
    return -1;
  }
  self->py_uf0D_float.uf0D_float = new Functions0D::ReadMapPixelF0D(s, i);
  self->py_uf0D_float.uf0D_float->py_uf0D = (PyObject *)self;
  return 0;
}

/*-----------------------BPy_ReadMapPixelF0D type definition ------------------------------*/

PyTypeObject ReadMapPixelF0D_Type = {
    /*ob_base*/ PyVarObject_HEAD_INIT(nullptr, 0)
    /*tp_name*/ "ReadMapPixelF0D",
    /*tp_basicsize*/ sizeof(BPy_ReadMapPixelF0D),
    /*tp_itemsize*/ 0,
    /*tp_dealloc*/ nullptr,
    /*tp_vectorcall_offset*/ 0,
    /*tp_getattr*/ nullptr,
    /*tp_setattr*/ nullptr,
    /*tp_as_async*/ nullptr,
    /*tp_repr*/ nullptr,
    /*tp_as_number*/ nullptr,
    /*tp_as_sequence*/ nullptr,
    /*tp_as_mapping*/ nullptr,
    /*tp_hash*/ nullptr,
    /*tp_call*/ nullptr,
    /*tp_str*/ nullptr,
    /*tp_getattro*/ nullptr,
    /*tp_setattro*/ nullptr,
    /*tp_as_buffer*/ nullptr,
    /*tp_flags*/ Py_TPFLAGS_DEFAULT | Py_TPFLAGS_BASETYPE,
    /*tp_doc*/ ReadMapPixelF0D___doc__,
    /*tp_traverse*/ nullptr,
    /*tp_clear*/ nullptr,
    /*tp_richcompare*/ nullptr,
    /*tp_weaklistoffset*/ 0,
    /*tp_iter*/ nullptr,
    /*tp_iternext*/ nullptr,
    /*tp_methods*/ nullptr,
    /*tp_members*/ nullptr,
    /*tp_getset*/ nullptr,
    /*tp_base*/ &UnaryFunction0DFloat_Type,
    /*tp_dict*/ nullptr,
    /*tp_descr_get*/ nullptr,
    /*tp_descr_set*/ nullptr,
    /*tp_dictoffset*/ 0,
    /*tp_init*/ (initproc)ReadMapPixelF0D___init__,
    /*tp_alloc*/ nullptr,
    /*tp_new*/ nullptr,
};

///////////////////////////////////////////////////////////////////////////////////////////

#ifdef __cplusplus
}
#endif
