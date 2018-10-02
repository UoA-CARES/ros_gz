// Copyright 2018 Open Source Robotics Foundation, Inc.
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

#include <memory>
#include <string>

// include builtin interfaces
#include "ros1_ign_bridge/builtin_interfaces_factories.hpp"
#include "ros1_ign_bridge/convert_builtin_interfaces.hpp"

namespace ros1_ign_bridge
{

std::shared_ptr<FactoryInterface>
get_factory_builtin_interfaces(
  const std::string & ros1_type_name,
  const std::string & ign_type_name)
{
  // mapping from string to specialized template
  if (
    (ros1_type_name == "std_msgs/String" || ros1_type_name == "") &&
     ign_type_name == "ignition::msgs::StringMsg")
  {
    return std::make_shared<
      Factory<
        std_msgs::String,
        ignition::msgs::StringMsg
      >
    >("std_msgs/String", ign_type_name);
  }
  return std::shared_ptr<FactoryInterface>();
}

// conversion functions for available interfaces
template<>
void
Factory<
  std_msgs::String,
  ignition::msgs::StringMsg
>::convert_1_to_ros(
  const std_msgs::String & ros1_msg,
  ignition::msgs::StringMSg & ign_msg)
{
  ros1_ign_bridge::convert_1_to_2(ros1_msg.data, ign_msg);
}

template<>
void
Factory<
  std_msgs::String,
  ignition::msgs::StringMsg
>::convert_ign_to_1(
  const ignition::msgs::StringMsg & ign_msg,
  std_msgs::String & ros1_msg)
{
  ros1_ign_bridge::convert_ign_to_1(ign_msg, ros1_msg.data);
}

}  // namespace ros1_ign_bridge