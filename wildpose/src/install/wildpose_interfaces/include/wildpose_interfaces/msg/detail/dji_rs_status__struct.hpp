// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wildpose_interfaces:msg/DjiRsStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_HPP_

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
# define DEPRECATED__wildpose_interfaces__msg__DjiRsStatus __attribute__((deprecated))
#else
# define DEPRECATED__wildpose_interfaces__msg__DjiRsStatus __declspec(deprecated)
#endif

namespace wildpose_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct DjiRsStatus_
{
  using Type = DjiRsStatus_<ContainerAllocator>;

  explicit DjiRsStatus_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->roll = 0.0f;
    }
  }

  explicit DjiRsStatus_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->yaw = 0.0f;
      this->pitch = 0.0f;
      this->roll = 0.0f;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _yaw_type =
    float;
  _yaw_type yaw;
  using _pitch_type =
    float;
  _pitch_type pitch;
  using _roll_type =
    float;
  _roll_type roll;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__yaw(
    const float & _arg)
  {
    this->yaw = _arg;
    return *this;
  }
  Type & set__pitch(
    const float & _arg)
  {
    this->pitch = _arg;
    return *this;
  }
  Type & set__roll(
    const float & _arg)
  {
    this->roll = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> *;
  using ConstRawPtr =
    const wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wildpose_interfaces__msg__DjiRsStatus
    std::shared_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wildpose_interfaces__msg__DjiRsStatus
    std::shared_ptr<wildpose_interfaces::msg::DjiRsStatus_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const DjiRsStatus_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->yaw != other.yaw) {
      return false;
    }
    if (this->pitch != other.pitch) {
      return false;
    }
    if (this->roll != other.roll) {
      return false;
    }
    return true;
  }
  bool operator!=(const DjiRsStatus_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct DjiRsStatus_

// alias to use template instance with default allocator
using DjiRsStatus =
  wildpose_interfaces::msg::DjiRsStatus_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_HPP_
