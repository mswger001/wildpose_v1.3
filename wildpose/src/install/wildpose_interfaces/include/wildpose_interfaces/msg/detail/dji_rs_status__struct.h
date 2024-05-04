// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wildpose_interfaces:msg/DjiRsStatus.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_H_
#define WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_H_

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

// Struct defined in msg/DjiRsStatus in the package wildpose_interfaces.
typedef struct wildpose_interfaces__msg__DjiRsStatus
{
  std_msgs__msg__Header header;
  float yaw;
  float pitch;
  float roll;
} wildpose_interfaces__msg__DjiRsStatus;

// Struct for a sequence of wildpose_interfaces__msg__DjiRsStatus.
typedef struct wildpose_interfaces__msg__DjiRsStatus__Sequence
{
  wildpose_interfaces__msg__DjiRsStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wildpose_interfaces__msg__DjiRsStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__DJI_RS_STATUS__STRUCT_H_
