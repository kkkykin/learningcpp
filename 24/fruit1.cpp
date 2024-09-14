#include "apple1.h"

std::ostream &operator<<(std::ostream &out, const Fruit &f) {
  out << f.getName() << ", " << f.getColor();
  return out;
}

std::ostream &operator<<(std::ostream &out, const Apple &a) {
  out << "Apple(" << static_cast<Fruit>(a) << ", " << a.getFiber() << ')';
  return out;
}

std::ostream &operator<<(std::ostream &out, const Banana &b) {
  out << "Banana(" << static_cast<Fruit>(b) << ')';
  return out;
}
