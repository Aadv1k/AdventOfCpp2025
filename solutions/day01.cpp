#include <iostream>
#include <sstream>

extern "C" void part_a(std::string input) {
  char direction;
  auto starting_pos = 50, 
       amount = 0,
       times_zeroed = 0;
  std::string line;

  std::istringstream iss(input);

  while (std::getline(iss, line)) {
    sscanf(line.c_str(), "%c%d", &direction, &amount);

    if (direction == 'L') {
        auto diff = starting_pos - amount;
        starting_pos = (diff + 100) % 100;
    } else {
        auto sum = starting_pos + amount;
        starting_pos = (sum + 100) % 100;
    }

    if (starting_pos == 0)
      times_zeroed++;

  }

  std::cout << "Times zeroed: " << times_zeroed << "\n";
}
