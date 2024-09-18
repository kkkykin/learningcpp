#include <iostream>
#include <vector>

class Point {
private:
  int m_x{};
  int m_y{};

public:
  Point(int x, int y) : m_x{x}, m_y{y} {}

  friend std::ostream &operator<<(std::ostream &out, const Point &p) {
    return out << "Point(" << p.m_x << ", " << p.m_y << ')';
  }
};

class Shape {
public:
  friend std::ostream &operator<<(std::ostream &out, const Shape &s) {
    return s.print(out);
  }
  virtual std::ostream &print(std::ostream &out) const = 0;

  virtual ~Shape() = default;
};

class Triangle : public Shape {
private:
  Point m_one{1, 2};
  Point m_two{3, 4};
  Point m_three{5, 6};

public:
  Triangle(const Point &one, const Point &two, const Point &three)
      : m_one{one}, m_two{two}, m_three{three} {}
  std::ostream &print(std::ostream &out) const override {
    out << "Triangle(" << m_one << ", " << m_two << ", " << m_three << ')';
    return out;
  }
};

class Circle : public Shape {
private:
  Point m_point{1, 2};
  int m_radius{};

public:
  Circle(const Point &p, int r) : m_point{p}, m_radius{r} {}
  std::ostream &print(std::ostream &out) const override {
    out << "Circle(" << m_point << ", radius " << m_radius << ')';
    return out;
  }

  int getRadius() const { return m_radius; }
};

int getLargestRadius(const auto v) {
  int max{0};
  for (const auto *x : v) {
    if (auto *c{dynamic_cast<const Circle *>(x)})
      max = std::max(max, c->getRadius());
  }
  return max;
}

int main() {
  std::vector<Shape *> v{new Circle{Point{1, 2}, 7},
                         new Triangle{Point{1, 2}, Point{3, 4}, Point{5, 6}},
                         new Circle{Point{7, 8}, 3}};

  // print each shape in vector v on its own line here
  for (const auto *x : v) {
    std::cout << *x << '\n';
  }

  std::cout << "The largest radius is: " << getLargestRadius(v)
            << '\n'; // write this function

  // delete each element in the vector here
  for (const auto *x : v)
    delete x;

  return 0;
}

// int main()
// {
//     Circle c{ Point{ 1, 2 }, 7 };
//     std::cout << c << '\n';

//     Triangle t{Point{ 1, 2 }, Point{ 3, 4 }, Point{ 5, 6 }};
//     std::cout << t << '\n';

//     return 0;
// }
