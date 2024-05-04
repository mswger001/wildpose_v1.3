// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from wildpose_interfaces:msg/LensAperture.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__BUILDER_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__BUILDER_HPP_

#include "wildpose_interfaces/msg/detail/lens_aperture__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace wildpose_interfaces
{

namespace msg
{

namespace builder
{

class Init_LensAperture_position
{
public:
  explicit Init_LensAperture_position(::wildpose_interfaces::msg::LensAperture & msg)
  : msg_(msg)
  {}
  ::wildpose_interfaces::msg::LensAperture position(::wildpose_interfaces::msg::LensAperture::_position_type arg)
  {
    msg_.position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::wildpose_interfaces::msg::LensAperture msg_;
};

class Init_LensAperture_header
{
public:
  Init_LensAperture_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_LensAperture_position header(::wildpose_interfaces::msg::LensAperture::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_LensAperture_position(msg_);
  }

private:
  ::wildpose_interfaces::msg::LensAperture msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::wildpose_interfaces::msg::LensAperture>()
{
  return wildpose_interfaces::msg::builder::Init_LensAperture_header();
}

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__BUILDER_HPP_
