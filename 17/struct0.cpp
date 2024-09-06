#include <iostream>
#include <array>
#include <string_view>

struct Item {
  std::string_view name;
  int gold;
};

void printArray(const auto &a) {
  for (const auto &i : a) {
    std::cout << "A " << i.name << " costs " << i.gold << " gold.\n";
  }
}

int main() {
  std::array<Item, 4> a{};
  a[0] = {"sword", 5};
  a[1] = {"dagger", 3};
  a[2] = {"club", 2};
  a[3] = {"spear", 7};
  printArray(a);

  constexpr std::array<Item, 4> b {
    {
      {"sword", 5},
      {"dagger", 3},
      {"club", 2},
      {"spear", 7},
    }};
  printArray(b);
  return 0;
}
