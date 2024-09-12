#ifndef PUZZLE5_H
#define PUZZLE5_H

#include "puzzle4.h"

class Point {
private:
  int m_x{};
  int m_y{};

public:
  Point(int x, int y) : m_x{x}, m_y{y} {};

  const Point getAdjacentPoint(const Direction &d) const;

  int getX() const { return m_x; }
  int getY() const { return m_y; }
};

bool operator==(const Point &a, const Point &b);
bool operator!=(const Point &a, const Point &b);

#endif
