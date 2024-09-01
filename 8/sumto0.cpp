#include <iostream>

constexpr int sumTo(int a) {
  int sum{0};
  for (; a > 0; a--) {
    sum+=a;
  }
  return sum;
}

int main() {
  std::cout << sumTo(5);
}
