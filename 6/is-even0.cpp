#include <iostream>

int getInput() {
  int a{};
  std::cin >> a;
  return a;
}

constexpr bool isEven(int a) {
  return (a % 2 == 0);
}

int main() {
  const int a{getInput()};
  std::cout << a << " is " << (isEven(a) ? "even" : "odd") << '\n';
  return 0;
}
