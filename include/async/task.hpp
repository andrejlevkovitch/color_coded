#pragma once

#include "vim/highlight.hpp"
#include <string>
#include <vector>

namespace color_coded
{
  namespace async
  {
    struct task {
      std::string name;
      std::string filetype;
      std::string code;
    };

    struct result {
      std::string          name;
      vim::highlight_group group;
    };
  } // namespace async
} // namespace color_coded
