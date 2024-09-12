#include "puzzle3.h"

#include <algorithm>
#include <array>
#include <iostream>

char UserInput::inputChar() {
  constexpr static std::array<char, 5> validChar{'w', 'a', 's', 'd', 'q'};
  char c{};
  while (true) {
    std::cin >> c;
    const auto &found{std::find(std::begin(validChar), std::end(validChar), c)};
    if (found != std::end(validChar))
      return *found;
  }
}

Direction UserInput::handleInput() {
  using std::cout;

  using enum Direction::Type;
  char c{inputChar()};
  switch (c) {
  case 'q':
    cout << "\n\nBye!\n\n";
    return Direction(maxDirections);
  case 'w': return Direction(up);
  case 'a': return Direction(left);
  case 's': return Direction(down);
  case 'd': return Direction(right);
  }
  return true;
}
