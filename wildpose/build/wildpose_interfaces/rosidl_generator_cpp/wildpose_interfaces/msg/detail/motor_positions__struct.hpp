// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from wildpose_interfaces:msg/MotorPositions.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__STRUCT_HPP_
#define WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__STRUCT_HPP_

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
# define DEPRECATED__wildpose_interfaces__msg__MotorPositions __attribute__((deprecated))
#else
# define DEPRECATED__wildpose_interfaces__msg__MotorPositions __declspec(deprecated)
#endif

namespace wildpose_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MotorPositions_
{
  using Type = MotorPositions_<ContainerAllocator>;

  explicit MotorPositions_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->zoom = 0l;
      this->focus = 0l;
      this->aperture = 0l;
    }
  }

  explicit MotorPositions_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->zoom = 0l;
      this->focus = 0l;
      this->aperture = 0l;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _zoom_type =
    int32_t;
  _zoom_type zoom;
  using _focus_type =
    int32_t;
  _focus_type focus;
  using _aperture_type =
    int32_t;
  _aperture_type aperture;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__zoom(
    const int32_t & _arg)
  {
    this->zoom = _arg;
    return *this;
  }
  Type & set__focus(
    const int32_t & _arg)
  {
    this->focus = _arg;
    return *this;
  }
  Type & set__aperture(
    const int32_t & _arg)
  {
    this->aperture = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> *;
  using ConstRawPtr =
    const wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__wildpose_interfaces__msg__MotorPositions
    std::shared_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__wildpose_interfaces__msg__MotorPositions
    std::shared_ptr<wildpose_interfaces::msg::MotorPositions_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MotorPositions_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->zoom != other.zoom) {
      return false;
    }
    if (this->focus != other.focus) {
      return false;
    }
    if (this->aperture != other.aperture) {
      return false;
    }
    return true;
  }
  bool operator!=(const MotorPositions_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MotorPositions_

// alias to use template instance with default allocator
using MotorPositions =
  wildpose_interfaces::msg::MotorPositions_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace wildpose_interfaces

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_POSITIONS__STRUCT_HPP_
