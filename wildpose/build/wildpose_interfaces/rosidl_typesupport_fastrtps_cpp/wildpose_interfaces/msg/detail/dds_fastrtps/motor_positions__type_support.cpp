// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from wildpose_interfaces:msg/MotorPositions.idl
// generated code does not contain a copyright notice
#include "wildpose_interfaces/msg/detail/motor_positions__rosidl_typesupport_fastrtps_cpp.hpp"
#include "wildpose_interfaces/msg/detail/motor_positions__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace std_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const std_msgs::msg::Header &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  std_msgs::msg::Header &);
size_t get_serialized_size(
  const std_msgs::msg::Header &,
  size_t current_alignment);
size_t
max_serialized_size_Header(
  bool & full_bounded,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace std_msgs


namespace wildpose_interfaces
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wildpose_interfaces
cdr_serialize(
  const wildpose_interfaces::msg::MotorPositions & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.header,
    cdr);
  // Member: zoom
  cdr << ros_message.zoom;
  // Member: focus
  cdr << ros_message.focus;
  // Member: aperture
  cdr << ros_message.aperture;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wildpose_interfaces
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  wildpose_interfaces::msg::MotorPositions & ros_message)
{
  // Member: header
  std_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.header);

  // Member: zoom
  cdr >> ros_message.zoom;

  // Member: focus
  cdr >> ros_message.focus;

  // Member: aperture
  cdr >> ros_message.aperture;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wildpose_interfaces
get_serialized_size(
  const wildpose_interfaces::msg::MotorPositions & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: header

  current_alignment +=
    std_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.header, current_alignment);
  // Member: zoom
  {
    size_t item_size = sizeof(ros_message.zoom);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: focus
  {
    size_t item_size = sizeof(ros_message.focus);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: aperture
  {
    size_t item_size = sizeof(ros_message.aperture);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_wildpose_interfaces
max_serialized_size_MotorPositions(
  bool & full_bounded,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;
  (void)full_bounded;


  // Member: header
  {
    size_t array_size = 1;


    for (size_t index = 0; index < array_size; ++index) {
      current_alignment +=
        std_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Header(
        full_bounded, current_alignment);
    }
  }

  // Member: zoom
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: focus
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  // Member: aperture
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint32_t) +
      eprosima::fastcdr::Cdr::alignment(current_alignment, sizeof(uint32_t));
  }

  return current_alignment - initial_alignment;
}

static bool _MotorPositions__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const wildpose_interfaces::msg::MotorPositions *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _MotorPositions__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<wildpose_interfaces::msg::MotorPositions *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _MotorPositions__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const wildpose_interfaces::msg::MotorPositions *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _MotorPositions__max_serialized_size(bool & full_bounded)
{
  return max_serialized_size_MotorPositions(full_bounded, 0);
}

static message_type_support_callbacks_t _MotorPositions__callbacks = {
  "wildpose_interfaces::msg",
  "MotorPositions",
  _MotorPositions__cdr_serialize,
  _MotorPositions__cdr_deserialize,
  _MotorPositions__get_serialized_size,
  _MotorPositions__max_serialized_size
};

static rosidl_message_type_support_t _MotorPositions__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_MotorPositions__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace wildpose_interfaces

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_wildpose_interfaces
const rosidl_message_type_support_t *
get_message_type_support_handle<wildpose_interfaces::msg::MotorPositions>()
{
  return &wildpose_interfaces::msg::typesupport_fastrtps_cpp::_MotorPositions__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, wildpose_interfaces, msg, MotorPositions)() {
  return &wildpose_interfaces::msg::typesupport_fastrtps_cpp::_MotorPositions__handle;
}

#ifdef __cplusplus
}
#endif
