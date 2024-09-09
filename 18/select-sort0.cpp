#include <iostream>
#include <array>

int main() {
  std::array x{30, 60, 20, 50, 40, 10};
  constexpr std::size_t length{std::size(x)};

  for (std::size_t i{}, tmp{}; i < length - 1; ++i) {
    tmp = i;
    for (std::size_t j{i + 1}; j < length; ++j) {
      if (x[j] > x[tmp])
        tmp = j;
    }
    if (tmp > i)
      std::swap(x[i], x[tmp]);
  }

  for (const auto &y : x) {
    std::cout << y << ' ';
  }
  return 0;
}
