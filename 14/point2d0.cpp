#include <iostream>
#include <cmath>

class Point2d {
private:
  static constexpr double default_x{0.0};
  static constexpr double default_y{0.0};

  double m_x{default_x};
  double m_y{default_y};

public:
  explicit constexpr Point2d() = default;
  explicit constexpr Point2d(double a, double b) : m_x{a}, m_y{b} {};
  void print() const {
    std::cout << "Point2d(" << m_x << ", " << m_y << ")\n";
  }
  constexpr double distanceTo(const Point2d &a) const {
    return std::sqrt((m_x - a.m_x)*(m_x - a.m_x) + (m_y - a.m_y)*(m_y - a.m_y));
  }
};

int main()
{
    Point2d first{};
    Point2d second{ 3.0, 4.0 };

    // Point2d third{ 4.0 }; // should error if uncommented

    first.print();
    second.print();

    std::cout << "Distance between two points: " << first.distanceTo(second) << '\n';

    return 0;
}
