/* SPDX-FileCopyrightText: 2011-2022 Blender Foundation
 *
 * SPDX-License-Identifier: Apache-2.0 */

#ifndef SHADER_NODE_TYPE
#  define SHADER_NODE_TYPE(name)
#endif

/* NOTE: for best OpenCL performance, item definition in the enum must
 * match the switch case order in `svm.h`. */

SHADER_NODE_TYPE(NODE_END)
SHADER_NODE_TYPE(NODE_SHADER_JUMP)
SHADER_NODE_TYPE(NODE_CLOSURE_BSDF)
SHADER_NODE_TYPE(NODE_CLOSURE_EMISSION)
SHADER_NODE_TYPE(NODE_CLOSURE_BACKGROUND)
SHADER_NODE_TYPE(NODE_CLOSURE_SET_WEIGHT)
SHADER_NODE_TYPE(NODE_CLOSURE_WEIGHT)
SHADER_NODE_TYPE(NODE_EMISSION_WEIGHT)
SHADER_NODE_TYPE(NODE_MIX_CLOSURE)
SHADER_NODE_TYPE(NODE_JUMP_IF_ZERO)
SHADER_NODE_TYPE(NODE_JUMP_IF_ONE)
SHADER_NODE_TYPE(NODE_GEOMETRY)
SHADER_NODE_TYPE(NODE_CONVERT)
SHADER_NODE_TYPE(NODE_TEX_COORD)
SHADER_NODE_TYPE(NODE_VALUE_F)
SHADER_NODE_TYPE(NODE_VALUE_V)
SHADER_NODE_TYPE(NODE_ATTR)
SHADER_NODE_TYPE(NODE_VERTEX_COLOR)
SHADER_NODE_TYPE(NODE_GEOMETRY_BUMP_DX)
SHADER_NODE_TYPE(NODE_GEOMETRY_BUMP_DY)
SHADER_NODE_TYPE(NODE_SET_DISPLACEMENT)
SHADER_NODE_TYPE(NODE_DISPLACEMENT)
SHADER_NODE_TYPE(NODE_VECTOR_DISPLACEMENT)
SHADER_NODE_TYPE(NODE_TEX_IMAGE)
SHADER_NODE_TYPE(NODE_TEX_IMAGE_BOX)
SHADER_NODE_TYPE(NODE_TEX_NOISE)
SHADER_NODE_TYPE(NODE_SET_BUMP)
SHADER_NODE_TYPE(NODE_ATTR_BUMP_DX)
SHADER_NODE_TYPE(NODE_ATTR_BUMP_DY)
SHADER_NODE_TYPE(NODE_VERTEX_COLOR_BUMP_DX)
SHADER_NODE_TYPE(NODE_VERTEX_COLOR_BUMP_DY)
SHADER_NODE_TYPE(NODE_TEX_COORD_BUMP_DX)
SHADER_NODE_TYPE(NODE_TEX_COORD_BUMP_DY)
SHADER_NODE_TYPE(NODE_CLOSURE_SET_NORMAL)
SHADER_NODE_TYPE(NODE_ENTER_BUMP_EVAL)
SHADER_NODE_TYPE(NODE_LEAVE_BUMP_EVAL)
SHADER_NODE_TYPE(NODE_HSV)
SHADER_NODE_TYPE(NODE_CLOSURE_HOLDOUT)
SHADER_NODE_TYPE(NODE_FRESNEL)
SHADER_NODE_TYPE(NODE_LAYER_WEIGHT)
SHADER_NODE_TYPE(NODE_CLOSURE_VOLUME)
SHADER_NODE_TYPE(NODE_PRINCIPLED_VOLUME)
SHADER_NODE_TYPE(NODE_MATH)
SHADER_NODE_TYPE(NODE_VECTOR_MATH)
SHADER_NODE_TYPE(NODE_RGB_RAMP)
SHADER_NODE_TYPE(NODE_GAMMA)
SHADER_NODE_TYPE(NODE_BRIGHTCONTRAST)
SHADER_NODE_TYPE(NODE_LIGHT_PATH)
SHADER_NODE_TYPE(NODE_OBJECT_INFO)
SHADER_NODE_TYPE(NODE_PARTICLE_INFO)
SHADER_NODE_TYPE(NODE_HAIR_INFO)
SHADER_NODE_TYPE(NODE_POINT_INFO)
SHADER_NODE_TYPE(NODE_TEXTURE_MAPPING)
SHADER_NODE_TYPE(NODE_MAPPING)
SHADER_NODE_TYPE(NODE_MIN_MAX)
SHADER_NODE_TYPE(NODE_CAMERA)
SHADER_NODE_TYPE(NODE_TEX_ENVIRONMENT)
SHADER_NODE_TYPE(NODE_TEX_SKY)
SHADER_NODE_TYPE(NODE_TEX_GRADIENT)
SHADER_NODE_TYPE(NODE_TEX_VORONOI)
SHADER_NODE_TYPE(NODE_TEX_WAVE)
SHADER_NODE_TYPE(NODE_TEX_MAGIC)
SHADER_NODE_TYPE(NODE_TEX_CHECKER)
SHADER_NODE_TYPE(NODE_TEX_BRICK)
SHADER_NODE_TYPE(NODE_TEX_WHITE_NOISE)
SHADER_NODE_TYPE(NODE_NORMAL)
SHADER_NODE_TYPE(NODE_LIGHT_FALLOFF)
SHADER_NODE_TYPE(NODE_IES)
SHADER_NODE_TYPE(NODE_CURVES)
SHADER_NODE_TYPE(NODE_TANGENT)
SHADER_NODE_TYPE(NODE_NORMAL_MAP)
SHADER_NODE_TYPE(NODE_INVERT)
SHADER_NODE_TYPE(NODE_MIX)
SHADER_NODE_TYPE(NODE_SEPARATE_COLOR)
SHADER_NODE_TYPE(NODE_COMBINE_COLOR)
SHADER_NODE_TYPE(NODE_SEPARATE_VECTOR)
SHADER_NODE_TYPE(NODE_COMBINE_VECTOR)
SHADER_NODE_TYPE(NODE_SEPARATE_HSV)
SHADER_NODE_TYPE(NODE_COMBINE_HSV)
SHADER_NODE_TYPE(NODE_VECTOR_ROTATE)
SHADER_NODE_TYPE(NODE_VECTOR_TRANSFORM)
SHADER_NODE_TYPE(NODE_WIREFRAME)
SHADER_NODE_TYPE(NODE_WAVELENGTH)
SHADER_NODE_TYPE(NODE_BLACKBODY)
SHADER_NODE_TYPE(NODE_MAP_RANGE)
SHADER_NODE_TYPE(NODE_VECTOR_MAP_RANGE)
SHADER_NODE_TYPE(NODE_CLAMP)
SHADER_NODE_TYPE(NODE_BEVEL)
SHADER_NODE_TYPE(NODE_AMBIENT_OCCLUSION)
SHADER_NODE_TYPE(NODE_TEX_VOXEL)
SHADER_NODE_TYPE(NODE_AOV_START)
SHADER_NODE_TYPE(NODE_AOV_COLOR)
SHADER_NODE_TYPE(NODE_AOV_VALUE)
SHADER_NODE_TYPE(NODE_FLOAT_CURVE)
SHADER_NODE_TYPE(NODE_MIX_COLOR)
SHADER_NODE_TYPE(NODE_MIX_FLOAT)
SHADER_NODE_TYPE(NODE_MIX_VECTOR)
SHADER_NODE_TYPE(NODE_MIX_VECTOR_NON_UNIFORM)

/* Padding for struct alignment. */
SHADER_NODE_TYPE(NODE_PAD1)
SHADER_NODE_TYPE(NODE_PAD2)

#undef SHADER_NODE_TYPE
