#include <iostream>
#include <numeric>

class Fraction {
private:
  int m_numerator{};
  int m_denominator{0};

public:
  Fraction() {};
  explicit Fraction(int a, int b) : m_numerator{a}, m_denominator{b} {
    if (a == 0) {
      m_denominator = 1;
    } else {
      int gcd{std::gcd(a, b)};
      m_numerator = a / gcd;
      m_denominator = b / gcd;
    }
  };
  void print() const {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }
  int getNumerator() const {
    return m_numerator;
  }
  int getDenominator() const {
    return m_denominator;
  }
  friend Fraction operator*(const Fraction &a, const Fraction &b);
  friend Fraction operator*(const Fraction &a, int b);
  friend Fraction operator*(int a, const Fraction &b);
};

Fraction operator*(const Fraction &a, const Fraction &b) {
  return Fraction{a.m_numerator * b.m_numerator,
                  a.m_denominator * b.m_denominator};
};
Fraction operator*(const Fraction &a, int b) {
  return Fraction{a.m_numerator * b, a.m_denominator};
};
Fraction operator*(int a, const Fraction &b) {
  return Fraction(a * b.m_numerator, b.m_denominator);
};

std::istream &operator>>(std::istream &in, Fraction &f) {
  int i{};
  char c{};
  int j{};
  in >> i >> c >> j;
  if (in) {
    f = Fraction{i, j};
  }
  return in;
}

std::ostream &operator<<(std::ostream &out, const Fraction &f) {
  out << f.getNumerator() << '/' << f.getDenominator();
  return out;
}

int main() {

  Fraction f1{};
  std::cout << "Enter fraction 1: ";
  std::cin >> f1;

  Fraction f2{};
  std::cout << "Enter fraction 2: ";
  std::cin >> f2;

  std::cout << f1 << " * " << f2 << " is " << f1 * f2
            << '\n'; // note: The result of f1 * f2 is an r-value

  // Fraction f1{2, 5};
  // f1.print();

  // Fraction f2{3, 8};
  // f2.print();

  // Fraction f3{f1 * f2};
  // f3.print();

  // Fraction f4{f1 * 2};
  // f4.print();

  // Fraction f5{2 * f2};
  // f5.print();

  // Fraction f6{Fraction{1, 2} * Fraction{2, 3} * Fraction{3, 4}};
  // f6.print();

  // Fraction f7{0, 6};
  // f7.print();

  return 0;
}
