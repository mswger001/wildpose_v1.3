// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from wildpose_interfaces:msg/DjiRsStatus.idl
// generated code does not contain a copyright notice
#include "wildpose_interfaces/msg/detail/dji_rs_status__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"

bool
wildpose_interfaces__msg__DjiRsStatus__init(wildpose_interfaces__msg__DjiRsStatus * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    wildpose_interfaces__msg__DjiRsStatus__fini(msg);
    return false;
  }
  // yaw
  // pitch
  // roll
  return true;
}

void
wildpose_interfaces__msg__DjiRsStatus__fini(wildpose_interfaces__msg__DjiRsStatus * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // yaw
  // pitch
  // roll
}

bool
wildpose_interfaces__msg__DjiRsStatus__are_equal(const wildpose_interfaces__msg__DjiRsStatus * lhs, const wildpose_interfaces__msg__DjiRsStatus * rhs)
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
  // yaw
  if (lhs->yaw != rhs->yaw) {
    return false;
  }
  // pitch
  if (lhs->pitch != rhs->pitch) {
    return false;
  }
  // roll
  if (lhs->roll != rhs->roll) {
    return false;
  }
  return true;
}

bool
wildpose_interfaces__msg__DjiRsStatus__copy(
  const wildpose_interfaces__msg__DjiRsStatus * input,
  wildpose_interfaces__msg__DjiRsStatus * output)
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
  // yaw
  output->yaw = input->yaw;
  // pitch
  output->pitch = input->pitch;
  // roll
  output->roll = input->roll;
  return true;
}

wildpose_interfaces__msg__DjiRsStatus *
wildpose_interfaces__msg__DjiRsStatus__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__DjiRsStatus * msg = (wildpose_interfaces__msg__DjiRsStatus *)allocator.allocate(sizeof(wildpose_interfaces__msg__DjiRsStatus), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(wildpose_interfaces__msg__DjiRsStatus));
  bool success = wildpose_interfaces__msg__DjiRsStatus__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
wildpose_interfaces__msg__DjiRsStatus__destroy(wildpose_interfaces__msg__DjiRsStatus * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    wildpose_interfaces__msg__DjiRsStatus__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
wildpose_interfaces__msg__DjiRsStatus__Sequence__init(wildpose_interfaces__msg__DjiRsStatus__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__DjiRsStatus * data = NULL;

  if (size) {
    data = (wildpose_interfaces__msg__DjiRsStatus *)allocator.zero_allocate(size, sizeof(wildpose_interfaces__msg__DjiRsStatus), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = wildpose_interfaces__msg__DjiRsStatus__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        wildpose_interfaces__msg__DjiRsStatus__fini(&data[i - 1]);
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
wildpose_interfaces__msg__DjiRsStatus__Sequence__fini(wildpose_interfaces__msg__DjiRsStatus__Sequence * array)
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
      wildpose_interfaces__msg__DjiRsStatus__fini(&array->data[i]);
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

wildpose_interfaces__msg__DjiRsStatus__Sequence *
wildpose_interfaces__msg__DjiRsStatus__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  wildpose_interfaces__msg__DjiRsStatus__Sequence * array = (wildpose_interfaces__msg__DjiRsStatus__Sequence *)allocator.allocate(sizeof(wildpose_interfaces__msg__DjiRsStatus__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = wildpose_interfaces__msg__DjiRsStatus__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
wildpose_interfaces__msg__DjiRsStatus__Sequence__destroy(wildpose_interfaces__msg__DjiRsStatus__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    wildpose_interfaces__msg__DjiRsStatus__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
wildpose_interfaces__msg__DjiRsStatus__Sequence__are_equal(const wildpose_interfaces__msg__DjiRsStatus__Sequence * lhs, const wildpose_interfaces__msg__DjiRsStatus__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!wildpose_interfaces__msg__DjiRsStatus__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
wildpose_interfaces__msg__DjiRsStatus__Sequence__copy(
  const wildpose_interfaces__msg__DjiRsStatus__Sequence * input,
  wildpose_interfaces__msg__DjiRsStatus__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(wildpose_interfaces__msg__DjiRsStatus);
    wildpose_interfaces__msg__DjiRsStatus * data =
      (wildpose_interfaces__msg__DjiRsStatus *)realloc(output->data, allocation_size);
    if (!data) {
      return false;
    }
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!wildpose_interfaces__msg__DjiRsStatus__init(&data[i])) {
        /* free currently allocated and return false */
        for (; i-- > output->capacity; ) {
          wildpose_interfaces__msg__DjiRsStatus__fini(&data[i]);
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
    if (!wildpose_interfaces__msg__DjiRsStatus__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
