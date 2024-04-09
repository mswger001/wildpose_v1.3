// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wildpose_interfaces:msg/DjiRsStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__BUILDER_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__BUILDER_HPP_

#include "wildpose_interfaces/msg/detail/dji_rs_status__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace wildpose_interfaces
{

namespace msg
{

namespace builder
{

class Init_DjiRsStatus_roll
{
public:
  explicit Init_DjiRsStatus_roll(::wildpose_interfaces::msg::DjiRsStatus & msg)
  : msg_(msg)
  {}
  ::wildpose_interfaces::msg::DjiRsStatus roll(::wildpose_interfaces::msg::DjiRsStatus::_roll_type arg)
  {
    msg_.roll = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wildpose_interfaces::msg::DjiRsStatus msg_;
};

class Init_DjiRsStatus_pitch
{
public:
  explicit Init_DjiRsStatus_pitch(::wildpose_interfaces::msg::DjiRsStatus & msg)
  : msg_(msg)
  {}
  Init_DjiRsStatus_roll pitch(::wildpose_interfaces::msg::DjiRsStatus::_pitch_type arg)
  {
    msg_.pitch = std::move(arg);
    return Init_DjiRsStatus_roll(msg_);
  }

private:
  ::wildpose_interfaces::msg::DjiRsStatus msg_;
};

class Init_DjiRsStatus_yaw
{
public:
  explicit Init_DjiRsStatus_yaw(::wildpose_interfaces::msg::DjiRsStatus & msg)
  : msg_(msg)
  {}
  Init_DjiRsStatus_pitch yaw(::wildpose_interfaces::msg::DjiRsStatus::_yaw_type arg)
  {
    msg_.yaw = std::move(arg);
    return Init_DjiRsStatus_pitch(msg_);
  }

private:
  ::wildpose_interfaces::msg::DjiRsStatus msg_;
};

class Init_DjiRsStatus_header
{
public:
  Init_DjiRsStatus_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_DjiRsStatus_yaw header(::wildpose_interfaces::msg::DjiRsStatus::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_DjiRsStatus_yaw(msg_);
  }

private:
  ::wildpose_interfaces::msg::DjiRsStatus msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wildpose_interfaces::msg::DjiRsStatus>()
{
  return wildpose_interfaces::msg::builder::Init_DjiRsStatus_header();
}

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__BUILDER_HPP_
