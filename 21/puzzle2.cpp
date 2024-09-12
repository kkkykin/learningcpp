#include "puzzle2.h"

std::ostream &operator<<(std::ostream &out, Board &b) {
  for (int i{}; i < g_consoleLines; ++i)
    out << '\n';

  for (int i{}; i < 4; ++i) {
    for (int j{}; j < 4; ++j) {
      out << b(i, j);
    }
    out << '\n';
  }
  return out;
}

void Board::locatePos() {
  for (int i{}; i < s_dimension; ++i) {
    for (int j{}; j < s_dimension; ++j) {
      if ((*this)(i, j).getNum() == 0) {
        curPos = {i, j};
      }
    }
  }
}

Board &Board::moveTile(const Direction &d) {
  Point tPoint{curPos.getAdjacentPoint(d.getDir())};
  Tile& tTile{(*this)(tPoint)};
  int tmp{tTile.getNum()};
  tTile.setNum(0);
  (*this)(curPos).setNum(tmp);
  curPos = tPoint;
  return *this;
}

void Board::shuffleBoard() {
  for (int i{}; i < 100; ++i) {
    moveTile(randDirection());
  }
}

bool Board::checkWin() {
  int flag{};
  for (int i{}; i < s_dimension; ++i) {
    for (int j{}; j < s_dimension; ++j) {
      if ((i * 4 + j + 1 == (*this)(i, j).getNum()))
        flag += 1;
    }
  }
  return (flag == s_dimension * s_dimension - 1);
}
