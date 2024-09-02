#include <iostream>

// write your sub function template here
constexpr auto sub(auto a, auto b) {
  return a - b;
}

int main()
{
	std::cout << sub(3, 2) << '\n';
	std::cout << sub(3.5, 2) << '\n';
	std::cout << sub(4, 1.5) << '\n';

	return 0;
}
