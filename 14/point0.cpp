#include <iostream>

class Point3d {
private:
  int m_a{};
  int m_b{};
  int m_c{};

public:
  void setValues(int x, int y, int z) {
    m_a = x;
    m_b = y;
    m_c = z;
  }

  void print() const {
    std::cout << '<' << m_a << ", " << m_b << ", " << m_c << ">\n";
  }

  constexpr bool isEqual(const Point3d &a) const {
    return (m_a == a.m_a) && (m_b == a.m_b) && (m_c == a.m_c);
  }
};

int main()
{
    Point3d point1;
    point1.setValues(1, 2, 3);

    point1.print();
    std::cout << '\n';

    Point3d point2{};
	point2.setValues(1, 2, 3);

	std::cout << "point 1 and point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

	Point3d point3{};
	point3.setValues(3, 4, 5);

	std::cout << "point 1 and point 3 are" << (point1.isEqual(point3) ? "" : " not") << " equal\n";

    return 0;
}
