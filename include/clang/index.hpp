#pragma once

#include <clang-c/Index.h>
#include <memory>

namespace color_coded
{
  namespace clang
  {
    class index_ptr : public std::shared_ptr<void>
    {
    public:
      index_ptr(CXIndex index)
          : std::shared_ptr<void>{index, clang_disposeIndex}
      {
        std::shared_ptr<void> tmp{index, clang_disposeIndex};
      }
    };
  } // namespace clang
} // namespace color_coded
