#pragma once

#include "resource.hpp"
#include <algorithm>
#include <clang-c/CXString.h>

namespace color_coded
{
  namespace clang
  {
    namespace detail
    {
      template <>
      struct resource_impl<CXString> {
        char const *c_str() const
        {
          auto const &self(static_cast<resource<CXString> const &>(*this));
          return clang_getCString(self.get());
        }

        static void deleter(CXString &str)
        {
          clang_disposeString(str);
        }
      };
    } // namespace detail

    using string = resource<CXString>;
  } // namespace clang
} // namespace color_coded
