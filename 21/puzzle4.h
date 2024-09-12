#ifndef PUZZLE4_H
#define PUZZLE4_H

#include <iostream>

class Direction {
public:
  enum Type {
    up,
    down,
    left,
    right,
    maxDirections,
  };

private:
  Type m_dir{};

public:
  Direction(Type x) : m_dir{x} {};
  Direction(int x) : m_dir{static_cast<Type>(x)} {};

  Direction operator-();

  Type getDir() const { return m_dir; }
};

std::ostream &operator<<(std::ostream &out, const Direction &d);

Direction randDirection();

#endif
