#include <iostream>
#include <vector>
#include <string_view>

void startGame(int min, const int max) {
  using std::cout;
  const std::vector<int> divisors {
    3, 5, 7, 11, 13, 17, 19
  };
  const std::vector<std::string_view> fizz {
    "fizz", "buzz", "pop", "bang", "jazz", "pow",
        "boom"
  };
  const std::size_t length{std::size(divisors)};
  bool flag{true};
  for (; min <= max; ++min) {
    flag = true;
    for (std::size_t i{0}; i < length; ++i) {
      if (min % divisors[i] == 0) {
        cout << fizz[i];
        flag = false;
      }
    }
    if (flag)
      cout << min;
    cout << '\n';
  }
}

int main() {
  startGame(1, 150);
  return 0;
}
