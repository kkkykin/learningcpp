#include <iostream>

class Fraction {
private:
  int m_numerator{ 0 };
  int m_denominator{ 1 };

public:
  Fraction() = default;
  explicit Fraction(int a, int b) : m_numerator{a}, m_denominator{b}{};
  void getFraction()
  {
    std::cout << "Enter a value for numerator: ";
    std::cin >> m_numerator;
    std::cout << "Enter a value for denominator: ";
    std::cin >> m_denominator;
    std::cout << '\n';
  }

  Fraction multiply(const Fraction &a) const {
    return Fraction{ m_numerator * a.m_numerator, m_denominator * a.m_denominator };
  }

  void printFraction() const
  {
    std::cout << m_numerator << '/' << m_denominator << '\n';
  }

};


int main()
{
  Fraction f1{ };
  f1.getFraction();
  Fraction f2{  };
  f2.getFraction();

  std::cout << "Your fractions multiplied together: ";

  f1.multiply(f2).printFraction();

  return 0;
}
