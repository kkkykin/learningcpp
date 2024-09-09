#include <iostream>

int main() {
  int array[]{6, 3, 2, 9, 7, 1, 5, 4, 8};
  std::size_t length{std::size(array)};

  for (std::size_t i{}; i < length - 1; ++i) {
    int sorted{true};
    for (std::size_t j{}; j < length -i - 1; j++)
      if (array[j] > array[j + 1]) {
        std::swap(array[j], array[j + 1]);
        sorted = false;
      }
    if (sorted) {
      std::cout << i << '\n';
      break;
    }
  }

  for (const auto &x : array) {
    std::cout << x << ' ';
  }
  return 0;
}
