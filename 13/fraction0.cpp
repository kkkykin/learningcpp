#include <iostream>

struct Fraction {
  int numerator{0};
  int denominator{1};
};

Fraction readIn() {
  using std::cin;
  Fraction a{};
  cin >> a.numerator;
  cin >> a.denominator;
  return a;
}

constexpr Fraction mult(const Fraction &a, const Fraction &b) {
  return {
    .numerator{a.numerator * b.numerator},
    .denominator{a.denominator * b.denominator},
  };
}

void printFraction(const Fraction &a) { std::cout << a.numerator << '/' << a.denominator; }

int main() {
  const Fraction a{readIn()};
  const Fraction b{readIn()};
  printFraction(mult(a, b));
}
