#include <iostream>
#include <numeric> // for std::gcd

class Fraction {
private:
  int m_numerator{};
  int m_denominator{};

public:
  Fraction(int numerator = 0, int denominator = 1)
      : m_numerator{numerator}, m_denominator{denominator} {
    // We put reduce() in the constructor to ensure any new fractions we make
    // get reduced! Any fractions that are overwritten will need to be
    // re-reduced
    reduce();
  }

  void reduce() {
    int gcd{std::gcd(m_numerator, m_denominator)};
    if (gcd) {
      m_numerator /= gcd;
      m_denominator /= gcd;
    }
  }

  friend std::ostream &operator<<(std::ostream &out, const Fraction &f1);
  int getN() const { return m_numerator; };
  int getD() const { return m_denominator; };
};

std::ostream &operator<<(std::ostream &out, const Fraction &f1) {
  out << f1.m_numerator << '/' << f1.m_denominator;
  return out;
}

int operator<=>(const Fraction &a, const Fraction &b) {
  return a.getN() * b.getD() - b.getN() * a.getD();
}

bool operator==(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) == 0;
}

bool operator!=(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) != 0;
}

bool operator<(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) < 0;
}

bool operator>(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) > 0;
}

bool operator<=(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) <= 0;
}

bool operator>=(const Fraction &a, const Fraction &b) {
  return operator<=>(a, b) >= 0;
}

int main() {
  Fraction f1{3, 2};
  Fraction f2{5, 8};

  std::cout << f1 << ((f1 == f2) ? " == " : " not == ") << f2 << '\n';
  std::cout << f1 << ((f1 != f2) ? " != " : " not != ") << f2 << '\n';
  std::cout << f1 << ((f1 < f2) ? " < " : " not < ") << f2 << '\n';
  std::cout << f1 << ((f1 > f2) ? " > " : " not > ") << f2 << '\n';
  std::cout << f1 << ((f1 <= f2) ? " <= " : " not <= ") << f2 << '\n';
  std::cout << f1 << ((f1 >= f2) ? " >= " : " not >= ") << f2 << '\n';
  return 0;
}
