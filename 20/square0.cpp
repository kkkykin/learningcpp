#include "../8/random.h"

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

bool play(auto &v, auto m) {

  while (std::size(v) > 0) {
    std::cout << "> ";
    int z{};
    std::cin >> z;

    auto found{std::find(v.begin(), v.end(), z)};
    if (found != std::end(v)) {
      std::cout << "Nice! " << sqrt(static_cast<double>(z / m))
                << " number(s) left.\n";
      v.erase(found);
    } else {
      auto near{
          std::min_element(std::begin(v), std::end(v), [&](auto a, auto b) {
            return abs(z - a) < abs(z - b);
          })};
      std::cout << z << " is wrong! Try " << *near << " next time.";
      return false;
    }
  }
  return true;
}

int inputInt() {
  int x{};
  std::cin >> x;
  return x;
}

int main() {
  std::cout << "Start where? ";
  int x{inputInt()};
  std::cout << "How many? ";
  int y{inputInt()};
  int mult{Random::get(2, 4)};
  std::cout << "I generated " << y
            << " square numbers. Do you know what each number is after "
               "multiplying it by "
            << mult << "?\n";

  std::vector<int> myVector(static_cast<std::size_t>(y));
  for (int i{}; i < y; ++i) {
    myVector[static_cast<std::size_t>(i)] = (x + i) * (x + i) * mult;
  }
  if (play(myVector, mult))
    std::cout << "Nice! You found all numbers, good job!";
}
