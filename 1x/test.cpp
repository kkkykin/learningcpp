#include <iostream>

int main() {
  std::cout << "Enter an integer: ";

  int a {}, b {};
  std::cin >> a;

  std::cout << "Enter another integer: ";
  std::cin >> b;

  std::cout << a << " + " << b << " is " << a + b << ".\n";
  std::cout << a << " - " << b << " is " << a - b << ".\n";

}
