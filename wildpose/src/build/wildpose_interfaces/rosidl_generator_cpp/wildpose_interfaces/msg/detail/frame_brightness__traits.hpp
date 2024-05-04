// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from wildpose_interfaces:msg/FrameBrightness.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__TRAITS_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__TRAITS_HPP_

#include "wildpose_interfaces/msg/detail/frame_brightness__struct.hpp"
#include <rosidl_runtime_cpp/traits.hpp>
#include <stdint.h>
#include <type_traits>

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<wildpose_interfaces::msg::FrameBrightness>()
{
  return "wildpose_interfaces::msg::FrameBrightness";
}

template<>
inline const char * name<wildpose_interfaces::msg::FrameBrightness>()
{
  return "wildpose_interfaces/msg/FrameBrightness";
}

template<>
struct has_fixed_size<wildpose_interfaces::msg::FrameBrightness>
  : std::integral_constant<bool, has_fixed_size<std_msgs::msg::Header>::value> {};

template<>
struct has_bounded_size<wildpose_interfaces::msg::FrameBrightness>
  : std::integral_constant<bool, has_bounded_size<std_msgs::msg::Header>::value> {};

template<>
struct is_message<wildpose_interfaces::msg::FrameBrightness>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__TRAITS_HPP_
