// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from livox_interfaces:msg/CustomMsg.idl
// generated code does not contain a copyright notice

#ifndef LIVOX_INTERFACES__MSG__DETAIL__CUSTOM_MSG__STRUCT_H_
#define LIVOX_INTERFACES__MSG__DETAIL__CUSTOM_MSG__STRUCT_H_

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
// Member 'points'
#include "livox_interfaces/msg/detail/custom_point__struct.h"

// Struct defined in msg/CustomMsg in the package livox_interfaces.
typedef struct livox_interfaces__msg__CustomMsg
{
  std_msgs__msg__Header header;
  uint64_t timebase;
  uint32_t point_num;
  uint8_t lidar_id;
  uint8_t rsvd[3];
  livox_interfaces__msg__CustomPoint__Sequence points;
} livox_interfaces__msg__CustomMsg;

// Struct for a sequence of livox_interfaces__msg__CustomMsg.
typedef struct livox_interfaces__msg__CustomMsg__Sequence
{
  livox_interfaces__msg__CustomMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} livox_interfaces__msg__CustomMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // LIVOX_INTERFACES__MSG__DETAIL__CUSTOM_MSG__STRUCT_H_
