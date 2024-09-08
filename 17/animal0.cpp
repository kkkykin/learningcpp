#include <iostream>
#include <array>
#include <string_view>
#include <string>

namespace Animal {
enum Type {
  chicken,
  dog,
  cat,
  elephant,
  duck,
  snake,
};
struct Data {
  std::string_view name{};
  int legs{};
  std::string_view sound{};
};
using namespace std::string_view_literals;
constexpr std::array<Data, 6> animals {
  {
    {"chicken"sv, 2, "c"sv}, {"dog"sv, 4, "d"sv}, {"cat"sv, 4, "cc"sv},
        {"elephant"sv, 4, "e"sv}, {"duck"sv, 2, "d"sv},
        {"snake"sv, 0, "s"sv} 
  }};
}

void printData(const std::string_view name, const bool match) {
  for (const auto &i : Animal::animals) {
    if ((match && name == i.name) || (!match && name != i.name)) {
      std::cout << "A " << i.name << " has " << i.legs << " legs and says "
                << i.sound << ".\n";
    }
  }
}

int main() {
  std::string name;
  std::getline(std::cin >> std::ws, name);
  printData(name, 1);
  std::cout << "\n";
  printData(name, 0);
}
