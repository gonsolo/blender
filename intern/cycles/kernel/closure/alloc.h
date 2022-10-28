/* SPDX-License-Identifier: Apache-2.0
 * Copyright 2011-2022 Blender Foundation */

#pragma once

CCL_NAMESPACE_BEGIN

template<typename GenericShaderClosures>
ccl_device ccl_private ShaderClosure *closure_alloc(ccl_private GenericShaderClosures *closures,
                                                    int size,
                                                    ClosureType type,
                                                    Spectrum weight)
{
  kernel_assert(size <= sizeof(ShaderClosure));

  if (closures->num_closure_left == 0)
    return NULL;

  ccl_private ShaderClosure *sc = &closures->closure[closures->num_closure];

  sc->type = type;
  sc->weight = weight;

  closures->num_closure++;
  closures->num_closure_left--;

  return sc;
}

template<>
ccl_device ccl_private ShaderClosure *closure_alloc(ccl_private ShaderClosuresTiny *closures,
                                                    int size,
                                                    ClosureType type,
                                                    Spectrum weight)
{
  return NULL;
}

ccl_device ccl_private void *closure_alloc_extra(ccl_private ShaderClosures *closures, int size)
{
  /* Allocate extra space for closure that need more parameters. We allocate
   * in chunks of sizeof(ShaderClosure) starting from the end of the closure
   * array.
   *
   * This lets us keep the same fast array iteration over closures, as we
   * found linked list iteration and iteration with skipping to be slower. */
  int num_extra = ((size + sizeof(ShaderClosure) - 1) / sizeof(ShaderClosure));

  if (num_extra > closures->num_closure_left) {
    /* Remove previous closure if it was allocated. */
    closures->num_closure--;
    closures->num_closure_left++;
    return NULL;
  }

  closures->num_closure_left -= num_extra;
  return (ccl_private void *)(closures->closure + closures->num_closure + closures->num_closure_left);
}

ccl_device_inline ccl_private ShaderClosure *bsdf_alloc(ccl_private ShaderClosures *closures,
                                                        int size,
                                                        Spectrum weight)
{
  kernel_assert(isfinite_safe(weight));

  /* No negative weights allowed. */
  weight = max(weight, zero_float3());

  const float sample_weight = fabsf(average(weight));

  /* Use comparison this way to help dealing with non-finite weight: if the average is not finite
   * we will not allocate new closure. */
  if (sample_weight >= CLOSURE_WEIGHT_CUTOFF) {
    ccl_private ShaderClosure *sc = closure_alloc(closures, size, CLOSURE_NONE_ID, weight);
    if (!sc) {
      return NULL;
    }

    sc->sample_weight = sample_weight;

    return sc;
  }

  return NULL;
}

CCL_NAMESPACE_END
