#include <iostream>

void fizzbuzz(int a) {
  using std::cout;
  for (int i{1}; i <= a; ++i) {
    if (!((i % 3) || (i % 5) )) {
      cout << "fizzbuzz";
    } else if (!(i % 3)) {
      cout << "fizz";
    } else if (!(i % 5)) {
      cout << "buzz";
    } else {
      cout << i;
    }
    cout << '\n';
  }
}

int main() {
  fizzbuzz(15);
  return 0;
}
