#include <iostream>
#include <string>

int getInt() {
  int a{};
  std::cin >> a;
  return a;
}

char getOpt() {
  char a{};
  std::cin >> a;
  return a;
}

constexpr std::string calc(int a, int b, char c) {
  int o{0};
  switch (c) {
  case '+':
    o = a + b;
    break;
  case '-':
    o = a - b;
    break;
  case '*':
    o = a * b;
    break;
  case '/':
    o = a / b;
    break;
  case '%':
    o = a % b;
    break;
  default:
    return "Error";
  }
  return std::to_string(o);
}

int main() {
  const int a{getInt()};
  const int b{getInt()};
  const char c{getOpt()};
  std::cout << calc(a, b, c);
  return 0;
}
