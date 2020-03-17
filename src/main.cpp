#include <iostream>

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include "movement_01.hpp"

using test_vector = std::vector<std::pair<std::string,std::reference_wrapper<const std::vector<lest::test>>>>;

const test_vector basic_tests {
  { "movement 01 basic task", movement_01::basic_tests },
};

const test_vector extra_tests {
  { "movement 01 extra task", movement_01::extra_tests },
};

inline int run_tests(const test_vector &vector, int argc, char **argv) {
  for (const auto &pair : vector) {
    if (lest::run(pair.second, argc, argv)) {
      std::cout << "It seems you still have work to do on the " << pair.first << "!" << std::endl;
      std::cout << "See if you can fix the errors listed, and try again!" << std::endl;
      return 0;
    }
  }

  return 1;
}

int main(int argc, char **argv) {
  if (run_tests(basic_tests, argc, argv) && run_tests(extra_tests, argc, argv)) {
    std::cout << R"(You have completed the tutorial!
Congratulations!)" << std::endl;
  }
}
