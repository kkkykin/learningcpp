#ifndef PUZZLE1_H
#define PUZZLE1_H

#include <iostream>

class Tile {
private:
  static constexpr int m_empty{0};
  int m_num{};

public:
  Tile(int n) : m_num{n} {};

  int getNum() const { return m_num; }
  void setNum(int x) { m_num = x; }

  bool isEmpty() const { return m_num == m_empty; }
};

std::ostream &operator<<(std::ostream &out, Tile &t);

#endif
