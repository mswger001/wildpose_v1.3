// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wildpose_interfaces:msg/FrameBrightness.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__BUILDER_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__BUILDER_HPP_

#include "wildpose_interfaces/msg/detail/frame_brightness__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace wildpose_interfaces
{

namespace msg
{

namespace builder
{

class Init_FrameBrightness_brightness
{
public:
  explicit Init_FrameBrightness_brightness(::wildpose_interfaces::msg::FrameBrightness & msg)
  : msg_(msg)
  {}
  ::wildpose_interfaces::msg::FrameBrightness brightness(::wildpose_interfaces::msg::FrameBrightness::_brightness_type arg)
  {
    msg_.brightness = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wildpose_interfaces::msg::FrameBrightness msg_;
};

class Init_FrameBrightness_header
{
public:
  Init_FrameBrightness_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_FrameBrightness_brightness header(::wildpose_interfaces::msg::FrameBrightness::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_FrameBrightness_brightness(msg_);
  }

private:
  ::wildpose_interfaces::msg::FrameBrightness msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wildpose_interfaces::msg::FrameBrightness>()
{
  return wildpose_interfaces::msg::builder::Init_FrameBrightness_header();
}

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__BUILDER_HPP_
