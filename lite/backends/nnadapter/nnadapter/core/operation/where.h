// Copyright (c) 2021 PaddlePaddle Authors. All Rights Reserved.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <vector>

namespace nnadapter {
namespace operation {

#define WHERE_OPERATION_EXTRACT_INPUTS_OUTPUTS                              \
  auto& input_operands = operation->input_operands;                         \
  auto& output_operands = operation->output_operands;                       \
  auto input_count = input_operands.size();                                 \
  auto output_count = output_operands.size();                               \
  NNADAPTER_CHECK_EQ(input_count, 3);                                       \
  NNADAPTER_CHECK_EQ(output_count, 1);                                      \
  /* Condition */                                                           \
  auto condition_operand = input_operands[0];                               \
  NNADAPTER_VLOG(5) << "condition: " << OperandToString(condition_operand); \
  /* Input0 */                                                              \
  auto input0_operand = input_operands[1];                                  \
  NNADAPTER_VLOG(5) << "input0: " << OperandToString(input0_operand);       \
  /* Input1 */                                                              \
  auto input1_operand = input_operands[2];                                  \
  NNADAPTER_VLOG(5) << "input1: " << OperandToString(input1_operand);       \
  /* Output */                                                              \
  auto output_operand = output_operands[0];                                 \
  NNADAPTER_VLOG(5) << "output: " << OperandToString(output_operand);

}  // namespace operation
}  // namespace nnadapter
