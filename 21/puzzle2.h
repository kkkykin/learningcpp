#ifndef PUZZLE2_H
#define PUZZLE2_H

#include "puzzle1.h"
#include "puzzle5.h"

#include <array>

// Increase amount of new lines if your board isn't
// at the very bottom of the console

constexpr int g_consoleLines{25};

class Board {
private:
  static constexpr int s_dimension{4};

  using Tile2d = std::array<std::array<Tile, s_dimension>, s_dimension>;
  Tile2d m_board{
      {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}, {13, 14, 15, 0}}};

  Point curPos{3, 3};

public:
  Tile &operator()(int i, int j) {
    return m_board[static_cast<std::size_t>(i)][static_cast<std::size_t>(j)];
  }

  Tile &operator()(const Point &p) {
    return m_board[static_cast<std::size_t>(p.getX())]
                  [static_cast<std::size_t>(p.getY())];
  }

  Board &moveTile(const Direction &d);

  void shuffleBoard();

  void locatePos();

  bool checkWin();
};

std::ostream &operator<<(std::ostream &out, Board &b);

#endif
