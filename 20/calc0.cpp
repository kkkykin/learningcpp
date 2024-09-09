#include <iostream>
#include <functional>

int add(int a, int b) {
  return a + b;
}

int subtract(int a, int b) {
  return a - b;
}

int multiply(int a, int b) {
  return a * b;
}

int divide(int a, int b) {
  return a / b;
}

int inputInt() {
  int x{};
  std::cin >> x;
  return x;
}

auto getOpt() {
  char x{};
  while (true) {
    std::cin >> x;
    switch (x) {
    case '+': return &add;
    case '-': return &subtract;
    case '*': return &multiply;
    case '/': return &divide;
    default: continue;
    }
  }
}

int getResult(int a, int b, std::function<int(int, int)> o) {
  return o(a, b);
}

int main() {
  int a{inputInt()};
  int b{inputInt()};
  std::cout << getResult(a, b, getOpt());
}
