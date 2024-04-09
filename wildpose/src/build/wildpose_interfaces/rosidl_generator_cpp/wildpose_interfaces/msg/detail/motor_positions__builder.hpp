// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wildpose_interfaces:msg/MotorPositions.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__BUILDER_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__BUILDER_HPP_

#include "wildpose_interfaces/msg/detail/motor_positions__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace wildpose_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorPositions_aperture
{
public:
  explicit Init_MotorPositions_aperture(::wildpose_interfaces::msg::MotorPositions & msg)
  : msg_(msg)
  {}
  ::wildpose_interfaces::msg::MotorPositions aperture(::wildpose_interfaces::msg::MotorPositions::_aperture_type arg)
  {
    msg_.aperture = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorPositions msg_;
};

class Init_MotorPositions_focus
{
public:
  explicit Init_MotorPositions_focus(::wildpose_interfaces::msg::MotorPositions & msg)
  : msg_(msg)
  {}
  Init_MotorPositions_aperture focus(::wildpose_interfaces::msg::MotorPositions::_focus_type arg)
  {
    msg_.focus = std::move(arg);
    return Init_MotorPositions_aperture(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorPositions msg_;
};

class Init_MotorPositions_zoom
{
public:
  explicit Init_MotorPositions_zoom(::wildpose_interfaces::msg::MotorPositions & msg)
  : msg_(msg)
  {}
  Init_MotorPositions_focus zoom(::wildpose_interfaces::msg::MotorPositions::_zoom_type arg)
  {
    msg_.zoom = std::move(arg);
    return Init_MotorPositions_focus(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorPositions msg_;
};

class Init_MotorPositions_header
{
public:
  Init_MotorPositions_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorPositions_zoom header(::wildpose_interfaces::msg::MotorPositions::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorPositions_zoom(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorPositions msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wildpose_interfaces::msg::MotorPositions>()
{
  return wildpose_interfaces::msg::builder::Init_MotorPositions_header();
}

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__BUILDER_HPP_
