# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_ximea_ros2_cam_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED ximea_ros2_cam_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(ximea_ros2_cam_FOUND FALSE)
  elseif(NOT ximea_ros2_cam_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(ximea_ros2_cam_FOUND FALSE)
  endif()
  return()
endif()
set(_ximea_ros2_cam_CONFIG_INCLUDED TRUE)

# output package information
if(NOT ximea_ros2_cam_FIND_QUIETLY)
  message(STATUS "Found ximea_ros2_cam: 0.0.0 (${ximea_ros2_cam_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'ximea_ros2_cam' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${ximea_ros2_cam_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(ximea_ros2_cam_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${ximea_ros2_cam_DIR}/${_extra}")
endforeach()
