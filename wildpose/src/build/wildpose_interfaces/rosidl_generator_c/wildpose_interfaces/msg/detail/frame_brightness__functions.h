// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from wildpose_interfaces:msg/FrameBrightness.idl
// generated code does not contain a copyright notice

#ifndef WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__FUNCTIONS_H_
#define WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "wildpose_interfaces/msg/rosidl_generator_c__visibility_control.h"

#include "wildpose_interfaces/msg/detail/frame_brightness__struct.h"

/// Initialize msg/FrameBrightness message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * wildpose_interfaces__msg__FrameBrightness
 * )) before or use
 * wildpose_interfaces__msg__FrameBrightness__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__init(wildpose_interfaces__msg__FrameBrightness * msg);

/// Finalize msg/FrameBrightness message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
void
wildpose_interfaces__msg__FrameBrightness__fini(wildpose_interfaces__msg__FrameBrightness * msg);

/// Create msg/FrameBrightness message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * wildpose_interfaces__msg__FrameBrightness__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
wildpose_interfaces__msg__FrameBrightness *
wildpose_interfaces__msg__FrameBrightness__create();

/// Destroy msg/FrameBrightness message.
/**
 * It calls
 * wildpose_interfaces__msg__FrameBrightness__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
void
wildpose_interfaces__msg__FrameBrightness__destroy(wildpose_interfaces__msg__FrameBrightness * msg);

/// Check for msg/FrameBrightness message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__are_equal(const wildpose_interfaces__msg__FrameBrightness * lhs, const wildpose_interfaces__msg__FrameBrightness * rhs);

/// Copy a msg/FrameBrightness message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__copy(
  const wildpose_interfaces__msg__FrameBrightness * input,
  wildpose_interfaces__msg__FrameBrightness * output);

/// Initialize array of msg/FrameBrightness messages.
/**
 * It allocates the memory for the number of elements and calls
 * wildpose_interfaces__msg__FrameBrightness__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__Sequence__init(wildpose_interfaces__msg__FrameBrightness__Sequence * array, size_t size);

/// Finalize array of msg/FrameBrightness messages.
/**
 * It calls
 * wildpose_interfaces__msg__FrameBrightness__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
void
wildpose_interfaces__msg__FrameBrightness__Sequence__fini(wildpose_interfaces__msg__FrameBrightness__Sequence * array);

/// Create array of msg/FrameBrightness messages.
/**
 * It allocates the memory for the array and calls
 * wildpose_interfaces__msg__FrameBrightness__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
wildpose_interfaces__msg__FrameBrightness__Sequence *
wildpose_interfaces__msg__FrameBrightness__Sequence__create(size_t size);

/// Destroy array of msg/FrameBrightness messages.
/**
 * It calls
 * wildpose_interfaces__msg__FrameBrightness__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
void
wildpose_interfaces__msg__FrameBrightness__Sequence__destroy(wildpose_interfaces__msg__FrameBrightness__Sequence * array);

/// Check for msg/FrameBrightness message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__Sequence__are_equal(const wildpose_interfaces__msg__FrameBrightness__Sequence * lhs, const wildpose_interfaces__msg__FrameBrightness__Sequence * rhs);

/// Copy an array of msg/FrameBrightness messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_wildpose_interfaces
bool
wildpose_interfaces__msg__FrameBrightness__Sequence__copy(
  const wildpose_interfaces__msg__FrameBrightness__Sequence * input,
  wildpose_interfaces__msg__FrameBrightness__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // WILDPOSE_INTERFACES__MSG__DETAIL__FRAME_BRIGHTNESS__FUNCTIONS_H_
