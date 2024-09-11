#include <cassert>
#include <cmath>
#include <cstdint>
#include <iostream>

class FixedPoint2 {
private:
  std::int16_t m_base{};
  std::int8_t m_decimal{};

public:
  FixedPoint2(int a, int b)
      : m_base{static_cast<std::int16_t>(a)},
        m_decimal{static_cast<std::int8_t>(b)} {
    resolveSign();
    resolveRound();
  };
  FixedPoint2(double x) {
    m_base = static_cast<std::int16_t>(x * 10) / 10;
    m_decimal = static_cast<std::int8_t>(std::round((x - m_base) * 100));
    resolveSign();
    resolveRound();
  }
  void resolveSign() {
    if (m_base < 0 || m_decimal < 0) {
      // Make sure base is negative
      if (m_base > 0)
        m_base = -m_base;
      // Make sure decimal is negative
      if (m_decimal > 0)
        m_decimal = -m_decimal;
    }
  }
  void resolveRound() {
    m_base += m_decimal / 100;
    m_decimal = m_decimal % 100;
  }
  int getBase() const { return m_base; };
  int getDecimal() const { return m_decimal; };
  explicit operator double() const {
    return m_base + (static_cast<double>(m_decimal) / 100);
  }
  friend bool testDecimal(const FixedPoint2 &fp);
  FixedPoint2 &operator-() {
    m_base = -m_base;
    m_decimal = -m_decimal;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, FixedPoint2 &x) {
  out << x.getBase() << '.' << x.getDecimal();
  return out;
}

std::istream &operator>>(std::istream &in, FixedPoint2 &x) {
  double y;
  in >> y;
  x = FixedPoint2{y};
  return in;
}

bool testDecimal(const FixedPoint2 &fp) {
  if (fp.m_base >= 0)
    return fp.m_decimal >= 0 && fp.m_decimal < 100;
  else
    return fp.m_decimal <= 0 && fp.m_decimal > -100;
}

bool operator==(const FixedPoint2 &a, const FixedPoint2 &b) {
  return (a.getBase() == b.getBase()) && (a.getDecimal() == b.getDecimal());
}

FixedPoint2 operator+(const FixedPoint2 &a, const FixedPoint2 &b) {
  
  return FixedPoint2{static_cast<double>(a) + static_cast<double>(b)};
}

int main() {
  assert(FixedPoint2{0.75} == FixedPoint2{0.75});    // Test equality true
  assert(!(FixedPoint2{0.75} == FixedPoint2{0.76})); // Test equality false

  // Test additional cases -- h/t to reader Sharjeel Safdar for these test cases
  assert(FixedPoint2{0.75} + FixedPoint2{1.23} ==
         FixedPoint2{1.98}); // both positive, no decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{1.50} ==
         FixedPoint2{2.25}); // both positive, with decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{-1.23} ==
         FixedPoint2{-1.98}); // both negative, no decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{-1.50} ==
         FixedPoint2{-2.25}); // both negative, with decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{-1.23} ==
         FixedPoint2{-0.48}); // second negative, no decimal overflow
  assert(FixedPoint2{0.75} + FixedPoint2{-1.50} ==
         FixedPoint2{-0.75}); // second negative, possible decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{1.23} ==
         FixedPoint2{0.48}); // first negative, no decimal overflow
  assert(FixedPoint2{-0.75} + FixedPoint2{1.50} ==
         FixedPoint2{0.75}); // first negative, possible decimal overflow

  FixedPoint2 a{-0.48};
  assert(static_cast<double>(a) == -0.48);
  assert(static_cast<double>(-a) == 0.48);

  std::cout << "Enter a number: "; // enter 5.678
  std::cin >> a;
  std::cout << "You entered: " << a << '\n';
  assert(static_cast<double>(a) == 5.68);

  // FixedPoint2 a{0.01};
  // assert(static_cast<double>(a) == 0.01);

  // FixedPoint2 b{-0.01};
  // assert(static_cast<double>(b) == -0.01);

  // FixedPoint2 c{1.9}; // make sure we handle single digit decimal
  // assert(static_cast<double>(c) == 1.9);

  // FixedPoint2 d{5.01}; // stored as 5.0099999... so we'll need to round this
  // assert(static_cast<double>(d) == 5.01);

  // FixedPoint2 e{-5.01}; // stored as -5.0099999... so we'll need to round
  // this assert(static_cast<double>(e) == -5.01);

  // // Handle case where the argument's decimal rounds to 100 (need to increase
  // // base by 1)
  // FixedPoint2 f{106.9978}; // should be stored with base 107 and decimal 0
  // assert(static_cast<double>(f) == 107.0);

  // // Handle case where the argument's decimal rounds to -100 (need to
  // decrease
  // // base by 1)
  // FixedPoint2 g{-106.9978}; // should be stored with base -107 and decimal 0
  // assert(static_cast<double>(g) == -107.0);

  // FixedPoint2 a{1, 104};
  // std::cout << a << '\n';
  // std::cout << static_cast<double>(a) << '\n';
  // assert(static_cast<double>(a) == 2.04);
  // assert(testDecimal(a));

  // FixedPoint2 b{1, -104};
  // assert(static_cast<double>(b) == -2.04);
  // assert(testDecimal(b));

  // FixedPoint2 c{-1, 104};
  // assert(static_cast<double>(c) == -2.04);
  // assert(testDecimal(c));

  // FixedPoint2 d{-1, -104};
  // assert(static_cast<double>(d) == -2.04);
  // assert(testDecimal(d));
  // FixedPoint2 a{34, 56};
  // std::cout << a << '\n';
  // std::cout << static_cast<double>(a) << '\n';
  // assert(static_cast<double>(a) == 34.56);

  // FixedPoint2 b{-2, 8};
  // assert(static_cast<double>(b) == -2.08);

  // FixedPoint2 c{2, -8};
  // assert(static_cast<double>(c) == -2.08);

  // FixedPoint2 d{-2, -8};
  // assert(static_cast<double>(d) == -2.08);

  // FixedPoint2 e{0, -5};
  // assert(static_cast<double>(e) == -0.05);

  // FixedPoint2 f{0, 10};
  // assert(static_cast<double>(f) == 0.1)
  ;

  return 0;
}
