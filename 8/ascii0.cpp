#include <iostream>

int main() {
  char a{'a'};
  while (a <= 'z') {
    std::cout << a << '\t' << static_cast<int>(a) << '\n';
    a++;
  }
  
  return 0;
}
