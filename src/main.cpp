#include <iostream>

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include "movement_01.hpp"
#include "movement_02.hpp"

using test_vector = std::vector<std::pair<std::string,std::reference_wrapper<const std::vector<lest::test>>>>;
using result_vector = std::vector<std::pair<std::string,bool>>;

const test_vector tests {
  { "movement 01 basic task", movement_01::basic_tests },
  { "movement 01 extra task", movement_01::extra_tests },
  { "movement 02 basic task", movement_02::basic_tests },
  { "movement 02 extra task", movement_02::extra_tests },
};

int main(int argc, char **argv) {
  result_vector results;
  for (const auto &pair : tests) {
    results.emplace_back(pair.first, lest::run(pair.second, argc, argv) == 0);
  }

  std::cout << "Your results so far:" << std::endl;
  for (const auto &result : results) {
    std::cout << result.first << ": " << (result.second ? u8"✅" : u8"❌") << std::endl;
  }
}
