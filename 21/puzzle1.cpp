#include "puzzle1.h"

std::ostream &operator<<(std::ostream &out, Tile &t) {
  out << '\t';
  int x{t.getNum()};
  if(x != 0)
    out << x;
  return out;
}
