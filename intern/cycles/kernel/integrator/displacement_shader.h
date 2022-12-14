/* SPDX-License-Identifier: Apache-2.0
 * Copyright 2011-2022 Blender Foundation */

/* Functions to evaluate displacement shader. */

#pragma once

#ifdef __SVM__
#  include "kernel/svm/svm.h"
#endif
#ifdef __OSL__
#  include "kernel/osl/osl.h"
#endif

CCL_NAMESPACE_BEGIN

template<typename ConstIntegratorGenericState>
ccl_device void displacement_shader_eval(KernelGlobals kg,
                                         ConstIntegratorGenericState state,
                                         ccl_private ShaderData *sd,
                                         ccl_private ShaderClosures *closures)
{
  closures->tiny.num_closure = 0;
  closures->tiny.num_closure_left = 0;

  /* this will modify sd->P */
#ifdef __OSL__
  if (kg->osl) {
    OSLShader::eval_displacement(kg, state, sd);
  }
  else
#endif
  {
#ifdef __SVM__
    svm_eval_nodes<KERNEL_FEATURE_NODE_MASK_DISPLACEMENT, SHADER_TYPE_DISPLACEMENT>(
        kg, state, sd, closures, NULL, 0);
#endif
  }
}

CCL_NAMESPACE_END
