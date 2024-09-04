#include <iostream>

int doublenumber(int a) {
  return a * 2;
}

int main() {
  int b{};
  std::cin >> b;
  std::cout << doublenumber(b);
  return 0;
}
