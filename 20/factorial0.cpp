#include <iostream>

int factorial(int x) {
  switch (x) {
  case 0:
    return 0;
  case 1:
    return 1;
  default:
    return x * factorial(x - 1);
  }
}

int main() {
  int x{7};
  for (int i{}; i < x; ++i) {
    std::cout << factorial(i) << ' ';
  }
  return 0;
}
