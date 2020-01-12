#pragma once

namespace color_coded
{
  template <>
  struct environment<env::tag>
  {
    static char constexpr const * const pwd{ "${CMAKE_CURRENT_SOURCE_DIR}" };
    static char constexpr const * const clang_include
    { "-isystem${LLVM_DIR}/include" };
    static char constexpr const * const clang_include_cpp
    { "-isystem${LLVM_DIR}/include/c++/v1" };
    static char constexpr const * const clang_include_lib
    { "-isystem${LLVM_DIR}/lib/clang/${CLANG_VERSION}/include" };
    static char constexpr const * const clang_resource_dir
    { "-resource-dir=${LLVM_DIR}/lib/clang/${CLANG_VERSION}" };
  };
}
