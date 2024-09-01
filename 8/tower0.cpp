#include <iostream>

void spaceFillPrint(unsigned int a) {
  unsigned int i{5};
  while (i > 0) {
    if (i <= a) {
      std::cout << i << ' ';
    } else {
      std::cout << "  ";
    }
    --i;
  }
  std::cout << std::endl;
}

int main() {
  unsigned int a{1};
  while (a < 6) {
    spaceFillPrint(a++);
  }
  return 0;
}
