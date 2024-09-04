#include "io1.h"
#include <iostream>

int readNumber() {
  int x {};
  std::cin >> x;
  return x;
}

void writeAnswer(int x) {
  std::cout << x;
}
