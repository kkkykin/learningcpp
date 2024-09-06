#include <iostream>
#include <vector>
#include <cassert>
#include <string_view>

namespace Player {
enum Items {
  healthPotion,
  torch,
  arrow,
  maxItem,
};

static std::vector inventory{1, 5, 10};
}

std::string_view getItemName(int a) {
  using enum Player::Items;
  using namespace std::string_view_literals;
  switch (a) {
  case healthPotion:
    return "health potion"sv;
  case torch:
    return "torch"sv;
  case arrow:
    return "arrow"sv;
  default:
    return "???"sv;
  }
}

int countTotalItems(const std::vector<int> &a) {
  int sum{0};
  for (const auto &b : a) {
    sum += b;
  }
  return sum;
}

void printPerItems(const std::vector<int> &a) {
  for (std::size_t i{0}; i < std::size(a); ++i) {
    std::cout << "You have " << a[i] << ' ' << getItemName(static_cast<int>(i))
              << ((a[i] > 1) ? "s" : "") << '\n';
  }
}

void printItems(const std::vector<int> &a) {
  assert(Player::maxItem == std::size(a));
  printPerItems(a);
  std::cout << "You have " << countTotalItems(a) << " total items\n";
}

int main() {
  printItems(Player::inventory);
  return 0;
}
