#include <iostream>

int main() {
  int a{};
  std::cin >> a;
  int b{};
  std::cin >> b;
  if (a > b) {
    const int c{a};
    a = b;
    b = c;
  }
  std::cout << "The smaller value is " << a << '\n';
  std::cout << "The larger value is " << b << '\n';
  return 0;
}
