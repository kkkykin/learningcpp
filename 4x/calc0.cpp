#include <iostream>

double getNumber() {
  std::cout << "Enter a double value: ";
  double a{};
  std::cin >> a;
  return a;
}

char getOpt() {
  std::cout << "Enter +, -, *, or /: ";
  char a{};
  std::cin >> a;
  return a;
}

double calcResult(double a, double b, char c) {
  switch (c) {
  case '+':
    return a + b;
  case '-':
    return a - b;
  case '*':
    return a * b;
  case '/':
    return a / b;
  default: return 0;
  }
}

int main() {
  double a{getNumber()}, b{getNumber()};
  char opt{getOpt()};
  std::cout << calcResult(a, b, opt);
  return 0;
}
