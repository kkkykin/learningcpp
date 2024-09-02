#include <iostream>

// write your mult function template here
template <typename T> constexpr T mult(T a, int b) {
  return a * b;
}

int main()
{
	std::cout << mult(2, 3) << '\n';
	std::cout << mult(1.2, 3) << '\n';

	return 0;
}
