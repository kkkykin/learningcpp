#include <iostream>

void printBinary(int x) {
  using std::cout;
  cout << (x / 128 % 2);
  cout << (x / 64 % 2);
  cout << (x / 32 % 2);
  cout << (x / 16 % 2);
  cout << (x / 8 % 2);
  cout << (x / 4 % 2);
  cout << (x / 2 % 2);
  cout << (x / 1 % 2);
}

int main() {
  int x{};
  std::cin >> x;
  printBinary(x);
}
