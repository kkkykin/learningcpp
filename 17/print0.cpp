#include <iostream>
#include <cstring>

void printCString(const char a[]) {
  while (*a != '\0') {
    std::cout << *a;
    ++a;
  }
}

void reversePrint(const char a[]) {
  for (auto i{strlen(a)}; i > 0; --i) {
    std::cout << *(a + i - 1);
  }
}

int main() {
  constexpr char a[]{"Hello, World!."};
  printCString(a);
  std::cout << '\n';
  reversePrint(a);
  // for (std::size_t i{0}; i < strlen(a); ++i) {
  //   std::cout << *(a+i);
  // }
  return 0;
}
