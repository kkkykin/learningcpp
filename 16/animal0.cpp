#include <iostream>
#include <vector>
#include <cassert>

namespace Animals {
enum Animal {
  chicken,
  dog,
  cat,
  elephant,
  duck,
  snake,
  maxSize,
};
}

int main() {
  const std::vector<int> lags{2, 4, 4, 4, 2, 0};
  assert(Animals::maxSize == std::ssize(lags));
  std::cout << lags[Animals::elephant];
  return 0;
}
