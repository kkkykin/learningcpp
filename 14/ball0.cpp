#include <iostream>
#include <string_view>

class Ball {
private:
  std::string_view color{};
  double radius{};

public:
  Ball(const std::string_view &a, const double b) : color{a}, radius{b} {}
  const std::string_view &getColor() const { return color; }
  const double &getRadius() const { return radius; }
};

void print(const Ball &a) {
  std::cout << "Ball(" << a.getColor() << ", " << a.getRadius() << ")\n";
}

int main()
{
  Ball blue{ "blue", 10.0 };
  print(blue);

  Ball red{ "red", 12.0 };
  print(red);

  return 0;
}
