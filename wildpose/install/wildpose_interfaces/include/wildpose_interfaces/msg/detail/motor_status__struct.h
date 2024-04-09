// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wildpose_interfaces:msg/MotorStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
#define WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"

// Struct defined in msg/MotorStatus in the package wildpose_interfaces.
typedef struct wildpose_interfaces__msg__MotorStatus
{
  std_msgs__msg__Header header;
  int32_t pulse_count;
  float revolution;
} wildpose_interfaces__msg__MotorStatus;

// Struct for a sequence of wildpose_interfaces__msg__MotorStatus.
typedef struct wildpose_interfaces__msg__MotorStatus__Sequence
{
  wildpose_interfaces__msg__MotorStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wildpose_interfaces__msg__MotorStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__MOTOR_STATUS__STRUCT_H_
