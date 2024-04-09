// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wildpose_interfaces:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_

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
# define DEPRECATED__wildpose_interfaces__msg__MotorStatus __attribute__((deprecated))
#else
# define DEPRECATED__wildpose_interfaces__msg__MotorStatus __declspec(deprecated)
#endif

namespace wildpose_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorStatus_
{
  using Type = MotorStatus_<ContainerAllocator>;

  explicit MotorStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pulse_count = 0l;
      this->revolution = 0.0f;
    }
  }

  explicit MotorStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pulse_count = 0l;
      this->revolution = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pulse_count_type =
    int32_t;
  _pulse_count_type pulse_count;
  using _revolution_type =
    float;
  _revolution_type revolution;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pulse_count(
    const int32_t & _arg)
  {
    this->pulse_count = _arg;
    return *this;
  }
  Type & set__revolution(
    const float & _arg)
  {
    this->revolution = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wildpose_interfaces__msg__MotorStatus
    std::shared_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wildpose_interfaces__msg__MotorStatus
    std::shared_ptr<wildpose_interfaces::msg::MotorStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pulse_count != other.pulse_count) {
      return false;
    }
    if (this->revolution != other.revolution) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorStatus_

// alias to use template instance with default allocator
using MotorStatus =
  wildpose_interfaces::msg::MotorStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_HPP_
