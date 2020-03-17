#include "tdcpp.hpp"

#include <cstdint>

namespace movement_01 {

  // Basic task

  constexpr std::uint64_t fibonacci_number(std::uint64_t n);

  // Extra tasks

  constexpr std::uint64_t lucas_number(std::uint64_t n);

  // Tests

  extern const std::vector<lest::test> basic_tests;
  extern const std::vector<lest::test> extra_tests;

}
