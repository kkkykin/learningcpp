#include <iostream>
#include <string>

template <typename T0, typename T1, typename T2> class Triad {
private:
  T0 a;
  T1 b;
  T2 c;

public:
  Triad(T0 x, T1 y, T2 z) : a{x}, b{y}, c{z} {};
  auto &first() { return a; };
  auto &getB() { return b; };
  auto &getC() { return c; };
  void print() const;
};

template <typename T0, typename T1, typename T2>
void Triad<T0, T1, T2>::print() const {
  std::cout << "[" << a << ", " << b << ", " << c << "]\n";
}

int main()
{
  Triad<int, int, int> t1{ 1, 2, 3 };
  t1.print();
  std::cout << '\n';
  std::cout << t1.first() << '\n';

  using namespace std::literals::string_literals;
  const Triad t2{ 1, 2.3, "Hello"s };
  t2.print();
  std::cout << '\n';

  return 0;
}
