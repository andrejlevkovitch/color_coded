#include "config.hpp"
#include <jest/jest.hpp>

int main()
{
  jest::worker const j{};
  return j();
}
