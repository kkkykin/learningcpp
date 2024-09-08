#include <iostream>

int main() {
  constexpr int square[]{0, 1, 4, 9};
  while (true) {
    int i{};
    std::cin >> i;
    if (i == -1) {
      std::cout << "Bye";
      return 0;
    } else {
      bool perfect{false};
      for (const auto &y : square) {
        if (i == y) {
          std::cout << "Yes\n";
          perfect = true;
          break;
        }
      }
      if (!perfect) {
        std::cout << "No\n";
      }
    }
  }
}
