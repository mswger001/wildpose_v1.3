// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from wildpose_interfaces:msg/LensAperture.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "wildpose_interfaces/msg/detail/lens_aperture__rosidl_typesupport_introspection_c.h"
#include "wildpose_interfaces/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "wildpose_interfaces/msg/detail/lens_aperture__functions.h"
#include "wildpose_interfaces/msg/detail/lens_aperture__struct.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/header.h"
// Member `header`
#include "std_msgs/msg/detail/header__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void LensAperture__rosidl_typesupport_introspection_c__LensAperture_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  wildpose_interfaces__msg__LensAperture__init(message_memory);
}

void LensAperture__rosidl_typesupport_introspection_c__LensAperture_fini_function(void * message_memory)
{
  wildpose_interfaces__msg__LensAperture__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_member_array[2] = {
  {
    "header",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wildpose_interfaces__msg__LensAperture, header),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(wildpose_interfaces__msg__LensAperture, position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_members = {
  "wildpose_interfaces__msg",  // message namespace
  "LensAperture",  // message name
  2,  // number of fields
  sizeof(wildpose_interfaces__msg__LensAperture),
  LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_member_array,  // message members
  LensAperture__rosidl_typesupport_introspection_c__LensAperture_init_function,  // function to initialize message memory (memory has to be allocated)
  LensAperture__rosidl_typesupport_introspection_c__LensAperture_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_type_support_handle = {
  0,
  &LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_wildpose_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, wildpose_interfaces, msg, LensAperture)() {
  LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_member_array[0].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, std_msgs, msg, Header)();
  if (!LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_type_support_handle.typesupport_identifier) {
    LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &LensAperture__rosidl_typesupport_introspection_c__LensAperture_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
