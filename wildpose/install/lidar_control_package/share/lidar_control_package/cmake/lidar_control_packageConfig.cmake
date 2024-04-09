# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_lidar_control_package_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED lidar_control_package_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(lidar_control_package_FOUND FALSE)
  elseif(NOT lidar_control_package_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(lidar_control_package_FOUND FALSE)
  endif()
  return()
endif()
set(_lidar_control_package_CONFIG_INCLUDED TRUE)

# output package information
if(NOT lidar_control_package_FIND_QUIETLY)
  message(STATUS "Found lidar_control_package: 0.0.0 (${lidar_control_package_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'lidar_control_package' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${lidar_control_package_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(lidar_control_package_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${lidar_control_package_DIR}/${_extra}")
endforeach()