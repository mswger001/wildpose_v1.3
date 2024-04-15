// generated from rosidl_typesupport_cpp/resource/idl__type_support.cpp.em
// with input from wildpose_interfaces:msg/MotorPositions.idl
// generated code does not contain a copyright notice

#include "cstddef"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "wildpose_interfaces/msg/detail/motor_positions__struct.hpp"
#include "rosidl_typesupport_cpp/identifier.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_c/type_support_map.h"
#include "rosidl_typesupport_cpp/message_type_support_dispatch.hpp"
#include "rosidl_typesupport_cpp/visibility_control.h"
#include "rosidl_typesupport_interface/macros.h"

namespace wildpose_interfaces
{

namespace msg
{

namespace rosidl_typesupport_cpp
{

typedef struct _MotorPositions_type_support_ids_t
{
  const char * typesupport_identifier[2];
} _MotorPositions_type_support_ids_t;

static const _MotorPositions_type_support_ids_t _MotorPositions_message_typesupport_ids = {
  {
    "rosidl_typesupport_fastrtps_cpp",  // ::rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
    "rosidl_typesupport_introspection_cpp",  // ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  }
};

typedef struct _MotorPositions_type_support_symbol_names_t
{
  const char * symbol_name[2];
} _MotorPositions_type_support_symbol_names_t;

#define STRINGIFY_(s) #s
#define STRINGIFY(s) STRINGIFY_(s)

static const _MotorPositions_type_support_symbol_names_t _MotorPositions_message_typesupport_symbol_names = {
  {
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wildpose_interfaces, msg, MotorPositions)),
    STRINGIFY(ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, wildpose_interfaces, msg, MotorPositions)),
  }
};

typedef struct _MotorPositions_type_support_data_t
{
  void * data[2];
} _MotorPositions_type_support_data_t;

static _MotorPositions_type_support_data_t _MotorPositions_message_typesupport_data = {
  {
    0,  // will store the shared library later
    0,  // will store the shared library later
  }
};

static const type_support_map_t _MotorPositions_message_typesupport_map = {
  2,
  "wildpose_interfaces",
  &_MotorPositions_message_typesupport_ids.typesupport_identifier[0],
  &_MotorPositions_message_typesupport_symbol_names.symbol_name[0],
  &_MotorPositions_message_typesupport_data.data[0],
};

static const rosidl_message_type_support_t MotorPositions_message_type_support_handle = {
  ::rosidl_typesupport_cpp::typesupport_identifier,
  reinterpret_cast<const type_support_map_t *>(&_MotorPositions_message_typesupport_map),
  ::rosidl_typesupport_cpp::get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_cpp

}  // namespace msg

}  // namespace wildpose_interfaces

namespace rosidl_typesupport_cpp
{

template<>
ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<wildpose_interfaces::msg::MotorPositions>()
{
  return &::wildpose_interfaces::msg::rosidl_typesupport_cpp::MotorPositions_message_type_support_handle;
}

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_cpp, wildpose_interfaces, msg, MotorPositions)() {
  return get_message_type_support_handle<wildpose_interfaces::msg::MotorPositions>();
}

#ifdef __cplusplus
}
#endif
}  // namespace rosidl_typesupport_cpp
