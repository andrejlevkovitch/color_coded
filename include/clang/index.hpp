#pragma once

#include "resource.hpp"
#include <memory>

namespace color_coded
{
  namespace clang
  {
    namespace detail
    {
      template <>
      struct resource_impl<CXIndex> {
        static void deleter(CXIndex &index)
        {
          clang_disposeIndex(index);
        }
      };
    } // namespace detail

    using index     = resource<CXIndex>;
    using index_ptr = std::shared_ptr<index const>;
  } // namespace clang
} // namespace color_coded
