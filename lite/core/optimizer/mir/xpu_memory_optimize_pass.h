// Copyright (c) 2019 PaddlePaddle Authors. All Rights Reserved.
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

#include <algorithm>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "lite/core/kernel.h"
#include "lite/core/optimizer/mir/pass.h"

namespace paddle {
namespace lite {
namespace mir {

class XPUMemoryOptimizePass : public ProgramPass {
 public:
  using lifecycle_t = std::pair<int, int>;
  using lifecycle_map_t = std::map<std::string, lifecycle_t>;
  void Apply(const std::unique_ptr<SSAGraph>& graph) override;

 private:
  void CollectLifeCycleByDevice(
      std::map<std::string, lifecycle_map_t>* lifecycles,
      SSAGraph*,
      std::map<std::string, std::string>* inplaceop_input2output,
      std::map<std::string, std::string>* inplaceop_output2input);
  void MakeReusePlan(
      const lifecycle_map_t& lifecycles,
      std::map<std::string, std::string>* node2cluster,
      std::map<std::string, std::string>* inplaceop_input2output,
      std::map<std::string, std::string>* inplaceop_output2input);
  void PerformReusePlan(SSAGraph* graph,
                        const std::map<std::string, std::string>& reuse_table);

 private:
  int max_lifecycle_{-1};
};

}  // namespace mir
}  // namespace lite
}  // namespace paddle
