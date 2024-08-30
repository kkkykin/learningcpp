#include <iostream>

int main() {
  std::cout << "Enter a single character: ";
  char x{};
  std::cin >> x;
  std::cout << "You entered '" << x << "', which has ASCII code "
            << static_cast<int>(x) << ".\n";
  return 0;
}
