#include <iostream>

int main() {
  std::cout << "Joe\n";

#if 0 // Change 0 to 1: allow compile
  std::cout << "Bob\n";
  std::cout << "Steve\n";
#endif

  return 0;
}
