#pragma once

#include <algorithm>
#include <clang-c/CXString.h>
#include <memory>

namespace color_coded
{
  namespace clang
  {
    class string final : public std::shared_ptr<CXString>
    {
      static void destroyer(CXString *str)
      {
        clang_disposeString(*str);
        delete str;
      }

    public:
      string()
          : std::shared_ptr<CXString>{new CXString, destroyer}
      {}

      string(CXString imp)
          : std::shared_ptr<CXString>{new CXString{imp}, destroyer}
      {}

      const char *c_str() const
      {
        return reinterpret_cast<const char *>(this->get()->data);
      }
    };
  } // namespace clang
} // namespace color_coded
