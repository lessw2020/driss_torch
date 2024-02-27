#include <c10/core/DispatchKey.h>
#include <torch/library.h>

// Custom up headers
#include "add.h"
#include "saturated_cast.h"

TORCH_LIBRARY(DrissTorch, m) {
  m.def("add_one(Tensor input) -> Tensor");
  m.impl("add_one", c10::DispatchKey::CUDA, TORCH_FN(driss_torch::add_one));
  //   Saturated cast func from bf16 to fp8 types
  m.def("saturated_cast(Tensor input, Tensor scale, ScalarType dtype, bool transpose) -> Tensor");
  m.impl("saturated_cast", c10::DispatchKey::CUDA, TORCH_FN(driss_torch::saturated_cast));
  m.impl("saturated_cast", c10::DispatchKey::Meta, TORCH_FN(driss_torch::saturated_cast_meta));
}
