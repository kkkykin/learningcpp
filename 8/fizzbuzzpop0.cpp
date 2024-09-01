#include <iostream>

void fizzbuzz(int a) {
  using std::cout;
  for (int i{1}; i <= a; ++i) {
    if (!(i % 3)) {
      cout << "fizz";
    }
    if (!(i % 5)) {
      cout << "buzz";
    }
    if (!(i % 7)) {
      cout << "pop";
    }
    if ((i % 7) && (i % 5) && (i % 3)) {
      cout << i;
    }
    cout << '\n';
  }
}

int main() {
  fizzbuzz(150);
  return 0;
}
