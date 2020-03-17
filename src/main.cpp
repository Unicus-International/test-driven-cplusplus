#include <iostream>

#include <algorithm>
#include <functional>
#include <string>
#include <vector>

#include "movement_01.hpp"

const std::vector<std::pair<std::string,std::reference_wrapper<const std::vector<lest::test>>>> tests {
  { "movement 01 basic task", movement_01::basic_tests },
  { "movement 01 extra task", movement_01::extra_tests },
};

int main(int argc, char **argv) {
  for (const auto &pair : tests) {
    if (lest::run(pair.second, argc, argv)) {
      std::cout << "It seems you still have work to do on the " << pair.first << "!" << std::endl;
      std::cout << "See if you can fix the errors listed, and try again!" << std::endl;
      return 0;
    }
  }
}
