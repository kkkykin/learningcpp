#include <iostream>

int sum(int x) {
  if (x / 10 == 0) {
    return x % 10;
  } else {
    return (x % 10) + sum(x / 10);
  }
}

int main() {
  std::cout << sum(93427);
  return 0;
}
