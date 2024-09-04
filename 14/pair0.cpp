#include <iostream>

// Provide the definition for IntPair and the print() member function here
struct IntPair {
  int a{0};
  int b{0};

  void print() {
    std::cout << "Pair(" << a << ", " << b << ")\n";
  }

  constexpr bool isEqual(const IntPair &aa) {
    return (a == aa.a && b == aa.b);
  }
};

int main()
{
	IntPair p1 {1, 2};
	IntPair p2 {3, 4};

	std::cout << "p1: ";
	p1.print();

	std::cout << "p2: ";
	p2.print();

    std::cout << "p1 and p1 " << (p1.isEqual(p1) ? "are equal\n" : "are not equal\n");
	std::cout << "p1 and p2 " << (p1.isEqual(p2) ? "are equal\n" : "are not equal\n");

	return 0;
}
