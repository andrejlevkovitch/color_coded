message(STATUS "Generating sources")
if("${CLANG_VERSION}" STREQUAL "")
  message(FATAL_ERROR "CLANG_VERSION is empty, so, if you want to compile color_coded with native clang you must set current version of clang manually (for example: -DCLANG_VERSION=\"9.0.1\")")
endif()

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/env/impl.cmake.hpp ${CMAKE_CURRENT_BINARY_DIR}/env/impl.hpp)
