#include "puzzle5.h"

const Point Point::getAdjacentPoint(const Direction &d) const {
  using enum Direction::Type;
  switch (d.getDir()) {
  case left: return Point(m_x, (m_y - 1 < 0 ? m_y : m_y - 1));
  case right: return Point(m_x, (m_y + 1 >= maxDirections ? m_y : m_y + 1));
  case up: return Point((m_x - 1 < 0 ? m_x : m_x - 1), m_y);
  case down: return Point((m_x + 1 >= maxDirections ? m_x : m_x + 1), m_y);
  default: return *this;
  }
}

bool operator==(const Point &a, const Point &b) {
  return (a.getX() == b.getX()) && (a.getY() == b.getY());
}

bool operator!=(const Point &a, const Point &b) {
  return !(a == b);
}
