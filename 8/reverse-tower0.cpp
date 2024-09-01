#include <iostream>

void minusPrint(unsigned int a) {
  while (a > 0) {
    std::cout << a << ((a > 1) ? ' ' : '\n');
    --a;
  }
}

int main() {
  unsigned int a{5};
  while (a > 0) {
    minusPrint(a--);
  }
  return 0;
}
