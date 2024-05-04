// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wildpose_interfaces:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_

#include "wildpose_interfaces/msg/detail/motor_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace wildpose_interfaces
{

namespace msg
{

namespace builder
{

class Init_MotorStatus_revolution
{
public:
  explicit Init_MotorStatus_revolution(::wildpose_interfaces::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  ::wildpose_interfaces::msg::MotorStatus revolution(::wildpose_interfaces::msg::MotorStatus::_revolution_type arg)
  {
    msg_.revolution = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorStatus msg_;
};

class Init_MotorStatus_pulse_count
{
public:
  explicit Init_MotorStatus_pulse_count(::wildpose_interfaces::msg::MotorStatus & msg)
  : msg_(msg)
  {}
  Init_MotorStatus_revolution pulse_count(::wildpose_interfaces::msg::MotorStatus::_pulse_count_type arg)
  {
    msg_.pulse_count = std::move(arg);
    return Init_MotorStatus_revolution(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorStatus msg_;
};

class Init_MotorStatus_header
{
public:
  Init_MotorStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MotorStatus_pulse_count header(::wildpose_interfaces::msg::MotorStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MotorStatus_pulse_count(msg_);
  }

private:
  ::wildpose_interfaces::msg::MotorStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wildpose_interfaces::msg::MotorStatus>()
{
  return wildpose_interfaces::msg::builder::Init_MotorStatus_header();
}

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__BUILDER_HPP_
