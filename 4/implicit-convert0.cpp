#include <iostream>

int main() {
  std::cout << "Enter a single character: ";
  char x{};
  std::cin >> x;
  int y{x};
  std::cout << "You entered '" << x << "', which has ASCII code "
            << y << ".\n";
  return 0;
}
