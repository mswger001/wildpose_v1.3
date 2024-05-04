// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wildpose_interfaces:msg/FrameBrightness.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__STRUCT_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__wildpose_interfaces__msg__FrameBrightness __attribute__((deprecated))
#else
# define DEPRECATED__wildpose_interfaces__msg__FrameBrightness __declspec(deprecated)
#endif

namespace wildpose_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrameBrightness_
{
  using Type = FrameBrightness_<ContainerAllocator>;

  explicit FrameBrightness_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->brightness = 0.0f;
    }
  }

  explicit FrameBrightness_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->brightness = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _brightness_type =
    float;
  _brightness_type brightness;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__brightness(
    const float & _arg)
  {
    this->brightness = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> *;
  using ConstRawPtr =
    const wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wildpose_interfaces__msg__FrameBrightness
    std::shared_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wildpose_interfaces__msg__FrameBrightness
    std::shared_ptr<wildpose_interfaces::msg::FrameBrightness_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameBrightness_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->brightness != other.brightness) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameBrightness_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameBrightness_

// alias to use template instance with default allocator
using FrameBrightness =
  wildpose_interfaces::msg::FrameBrightness_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__STRUCT_HPP_
