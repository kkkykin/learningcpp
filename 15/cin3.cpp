#include <iostream>

int main() {
  [[maybe_unused]] int a{}, b{}, c{};

  std::cout << "Enter three numbers: ";
  std::cin >> a >> b >> c;
  std::cout << "You entered " << a << ", " << b << ", and " << c << ".\n";

  return 0;
  
}
