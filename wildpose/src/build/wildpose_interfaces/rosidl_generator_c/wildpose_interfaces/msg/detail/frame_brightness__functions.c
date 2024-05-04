// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wildpose_interfaces:msg/FrameBrightness.idl
// generated code does not contain a copyright notice
#include "wildpose_interfaces/msg/detail/frame_brightness__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
wildpose_interfaces__msg__FrameBrightness__init(wildpose_interfaces__msg__FrameBrightness * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wildpose_interfaces__msg__FrameBrightness__fini(msg);
    return false;
  }
  // brightness
  return true;
}

void
wildpose_interfaces__msg__FrameBrightness__fini(wildpose_interfaces__msg__FrameBrightness * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // brightness
}

bool
wildpose_interfaces__msg__FrameBrightness__are_equal(const wildpose_interfaces__msg__FrameBrightness * lhs, const wildpose_interfaces__msg__FrameBrightness * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // brightness
  if (lhs->brightness != rhs->brightness) {
    return false;
  }
  return true;
}

bool
wildpose_interfaces__msg__FrameBrightness__copy(
  const wildpose_interfaces__msg__FrameBrightness * input,
  wildpose_interfaces__msg__FrameBrightness * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // brightness
  output->brightness = input->brightness;
  return true;
}

wildpose_interfaces__msg__FrameBrightness *
wildpose_interfaces__msg__FrameBrightness__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__FrameBrightness * msg = (wildpose_interfaces__msg__FrameBrightness *)allocator.allocate(sizeof(wildpose_interfaces__msg__FrameBrightness), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wildpose_interfaces__msg__FrameBrightness));
  bool success = wildpose_interfaces__msg__FrameBrightness__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wildpose_interfaces__msg__FrameBrightness__destroy(wildpose_interfaces__msg__FrameBrightness * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wildpose_interfaces__msg__FrameBrightness__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wildpose_interfaces__msg__FrameBrightness__Sequence__init(wildpose_interfaces__msg__FrameBrightness__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__FrameBrightness * data = NULL;

  if (size) {
    data = (wildpose_interfaces__msg__FrameBrightness *)allocator.zero_allocate(size, sizeof(wildpose_interfaces__msg__FrameBrightness), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wildpose_interfaces__msg__FrameBrightness__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wildpose_interfaces__msg__FrameBrightness__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
wildpose_interfaces__msg__FrameBrightness__Sequence__fini(wildpose_interfaces__msg__FrameBrightness__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      wildpose_interfaces__msg__FrameBrightness__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

wildpose_interfaces__msg__FrameBrightness__Sequence *
wildpose_interfaces__msg__FrameBrightness__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__FrameBrightness__Sequence * array = (wildpose_interfaces__msg__FrameBrightness__Sequence *)allocator.allocate(sizeof(wildpose_interfaces__msg__FrameBrightness__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wildpose_interfaces__msg__FrameBrightness__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wildpose_interfaces__msg__FrameBrightness__Sequence__destroy(wildpose_interfaces__msg__FrameBrightness__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wildpose_interfaces__msg__FrameBrightness__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wildpose_interfaces__msg__FrameBrightness__Sequence__are_equal(const wildpose_interfaces__msg__FrameBrightness__Sequence * lhs, const wildpose_interfaces__msg__FrameBrightness__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wildpose_interfaces__msg__FrameBrightness__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wildpose_interfaces__msg__FrameBrightness__Sequence__copy(
  const wildpose_interfaces__msg__FrameBrightness__Sequence * input,
  wildpose_interfaces__msg__FrameBrightness__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wildpose_interfaces__msg__FrameBrightness);
    wildpose_interfaces__msg__FrameBrightness * data =
      (wildpose_interfaces__msg__FrameBrightness *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wildpose_interfaces__msg__FrameBrightness__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          wildpose_interfaces__msg__FrameBrightness__fini(&data[i]);
        }
        free(data);
        return false;
      }
    }
    output->data = data;
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!wildpose_interfaces__msg__FrameBrightness__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
