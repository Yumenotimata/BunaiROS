# generated from ament/cmake/core/templates/nameConfig.cmake.in

# prevent multiple inclusion
if(_Controller_CONFIG_INCLUDED)
  # ensure to keep the found flag the same
  if(NOT DEFINED Controller_FOUND)
    # explicitly set it to FALSE, otherwise CMake will set it to TRUE
    set(Controller_FOUND FALSE)
  elseif(NOT Controller_FOUND)
    # use separate condition to avoid uninitialized variable warning
    set(Controller_FOUND FALSE)
  endif()
  return()
endif()
set(_Controller_CONFIG_INCLUDED TRUE)

# output package information
if(NOT Controller_FIND_QUIETLY)
  message(STATUS "Found Controller: 0.0.0 (${Controller_DIR})")
endif()

# warn when using a deprecated package
if(NOT "" STREQUAL "")
  set(_msg "Package 'Controller' is deprecated")
  # append custom deprecation text if available
  if(NOT "" STREQUAL "TRUE")
    set(_msg "${_msg} ()")
  endif()
  # optionally quiet the deprecation message
  if(NOT ${Controller_DEPRECATED_QUIET})
    message(DEPRECATION "${_msg}")
  endif()
endif()

# flag package as ament-based to distinguish it after being find_package()-ed
set(Controller_FOUND_AMENT_PACKAGE TRUE)

# include all config extra files
set(_extras "")
foreach(_extra ${_extras})
  include("${Controller_DIR}/${_extra}")
endforeach()
