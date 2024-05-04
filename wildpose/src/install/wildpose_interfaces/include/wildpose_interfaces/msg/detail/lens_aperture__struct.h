// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from wildpose_interfaces:msg/LensAperture.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__STRUCT_H_
#define WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__STRUCT_H_

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

// Struct defined in msg/LensAperture in the package wildpose_interfaces.
typedef struct wildpose_interfaces__msg__LensAperture
{
  std_msgs__msg__Header header;
  int32_t position;
} wildpose_interfaces__msg__LensAperture;

// Struct for a sequence of wildpose_interfaces__msg__LensAperture.
typedef struct wildpose_interfaces__msg__LensAperture__Sequence
{
  wildpose_interfaces__msg__LensAperture * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} wildpose_interfaces__msg__LensAperture__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__LENS_APERTURE__STRUCT_H_
