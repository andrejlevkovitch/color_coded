#pragma once

#include "conf/args_view.hpp"
#include "diagnostic.hpp"
#include "index.hpp"
#include "string.hpp"
#include "token_pack.hpp"
#include "translation_unit.hpp"
#include <clang-c/Index.h>
#include <sstream>
#include <string>

namespace color_coded
{
  namespace core
  {
    std::string const &last_error(std::string const &e);
    void               reset_last_error();
  } // namespace core

  namespace clang
  {
    struct compilation_error : std::runtime_error {
      using std::runtime_error::runtime_error;
    };

    translation_unit compile(const conf::args_view &args,
                             std::string const &    filename)
    {
      index_ptr              index{clang_createIndex(false, false)};
      translation_unit const trans_unit{args, index, filename};
      auto &                 tu(trans_unit.impl);

      std::size_t const diags{clang_getNumDiagnostics(tu)};
      if (diags) {
        std::stringstream ss;
        for (std::size_t i{}; i != diags; ++i) {
          diagnostic const diag{clang_getDiagnostic(tu, i)};
          if (clang_getDiagnosticSeverity(diag.get()) >= CXDiagnostic_Error) {
            string const str{clang_formatDiagnostic(
                diag.get(), clang_defaultDiagnosticDisplayOptions())};
            ss << str.c_str() << '\n';
          }
        }
        auto const str(ss.str());
        if (!str.empty()) {
          core::last_error(str);
          if (!tu) {
            throw compilation_error{str};
          }
        } else {
          core::reset_last_error();
        }
      } else {
        core::reset_last_error();
      }

      return trans_unit;
    }
  } // namespace clang
} // namespace color_coded
