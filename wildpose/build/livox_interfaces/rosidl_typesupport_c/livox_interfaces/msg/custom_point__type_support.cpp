// generated from rosidl_typesupport_c/resource/idl__type_support.cpp.em
// with input from livox_interfaces:msg/CustomPoint.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "livox_interfaces/msg/rosidl_typesupport_c__visibility_control.h"
#include "livox_interfaces/msg/detail/custom_point__struct.h"
#include "rosidl_typesupport_c/identifier.h"
#include "rosidl_typesupport_c/message_type_support_dispatch.h"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_c/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace livox_interfaces
{

namespace msg
{

namespace rosidl_typesupport_c
{

typedef struct _CustomPoint_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _CustomPoint_type_support_ids_t;

static const _CustomPoint_type_support_ids_t _CustomPoint_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_c",  // ::rosidl_typesupport_fastrtps_c::typesupport_identifier,
    "rosidl_typesupport_introspection_c",  // ::rosidl_typesupport_introspection_c::typesupport_identifier,
  }
};

typedef struct _CustomPoint_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _CustomPoint_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _CustomPoint_type_support_symbol_names_t _CustomPoint_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_c, livox_interfaces, msg, CustomPoint)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, livox_interfaces, msg, CustomPoint)),
  }
};

typedef struct _CustomPoint_type_support_data_t
{
  void * data[2];
} _CustomPoint_type_support_data_t;

static _CustomPoint_type_support_data_t _CustomPoint_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _CustomPoint_message_typesupport_map = {
  2,
  "livox_interfaces",
  &_CustomPoint_message_typesupport_ids.typesupport_identifier[0],
  &_CustomPoint_message_typesupport_symbol_names.symbol_name[0],
  &_CustomPoint_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t CustomPoint_message_type_support_handle = {
  rosidl_typesupport_c__typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_CustomPoint_message_typesupport_map),
  rosidl_typesupport_c__get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_c

}  // namespace msg

}  // namespace livox_interfaces

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_C_EXPORT_livox_interfaces
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_c, livox_interfaces, msg, CustomPoint)() {
  return &::livox_interfaces::msg::rosidl_typesupport_c::CustomPoint_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
