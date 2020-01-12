#pragma once

#include <clang-c/Index.h>
#include <memory>

namespace color_coded
{
  namespace clang
  {
    class diagnostic final : public std::shared_ptr<void>
    {
    public:
      diagnostic(CXDiagnostic diag)
          : std::shared_ptr<void>{diag, clang_disposeDiagnostic}
      {}
    };
  } // namespace clang
} // namespace color_coded
