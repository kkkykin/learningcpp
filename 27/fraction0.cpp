#include <iostream>
#include <stdexcept>

class Fraction {
private:
  int m_numerator{};
  int m_denominator{};

public:
  Fraction(int a, int b) : m_numerator{a}, m_denominator{b} {
    if (b == 0)
      throw std::runtime_error{"abort"};
  }
};

int getInput() {
  int x{};
  std::cin >> x;
  return x;
}

int main() {
  try {
    Fraction frac{getInput(), getInput()};
  } catch (const std::exception &ex) {
    std::cout << "Catched.";
  }
}
