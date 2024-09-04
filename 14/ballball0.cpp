#include <iostream>
#include <string_view>

class Ball {
public:
  Ball(const double radius) : Ball(default_color, radius){};
  Ball(const std::string_view color = default_color,
       const double radius = default_radius)
      : m_color{color}, m_radius{radius} {
    std::cout << "Ball(" << m_color << ", " << m_radius << ")\n";
  };

  const std::string_view getColor() const { return m_color; }
  double getRadius() const { return m_radius; };

private:
  static constexpr std::string_view default_color{"black"};
  static constexpr double default_radius{10.0};

  std::string_view m_color{default_color};
  double m_radius{default_radius};
};

int main()
{
    Ball def{};
    Ball blue{ "blue" };
    Ball twenty{ 20.0 };
    Ball blueTwenty{ "blue", 20.0 };

    return 0;
}
