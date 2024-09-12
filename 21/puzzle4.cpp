#include "puzzle4.h"

#include "../8/random.h"

Direction Direction::operator-() {
  switch (m_dir) {
  case down: return Direction{up};
  case left: return Direction{right};
  case right: return Direction{left};
  case up: return Direction{down};
  default: break;
  }
  return Direction{down};
}

std::ostream &operator<<(std::ostream &out, const Direction &d) {
  using std::cout;
  using enum Direction::Type;
  cout << "You entered direction: ";
  switch (d.getDir()) {
  case up: cout << "up"; break;
  case down: cout << "down"; break;
  case left: cout << "left"; break;
  case right: cout << "right"; break;
  default: break;
  }
  return out;
}

Direction randDirection() {
  return Direction(Random::get(0, 3));
}

