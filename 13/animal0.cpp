#include <string_view>
#include <iostream>
#include <optional>

enum class Animal {
  pig,
  chicken,
  goat,
  cat,
  dog,
  duck,
};

constexpr std::optional<std::string_view> getAnimalName(Animal a) {
  using enum Animal;
  switch (a) {
  case pig:
    return "pig";
  case chicken:
    return "chicken";
  case goat:
    return "goat";
  case cat:
    return "cat";
  case dog:
    return "dog";
  case duck:
    return "duck";
  default:
    std::cout << "Error: Animal not found\n";
    return {};
  }
}

void printNumberOfLegs(Animal a) {
  const std::optional<std::string_view> name{getAnimalName(a)};
  if (!name) {
    return;
  }
  using std::cout;
  using enum Animal;
  cout << "A " << name.value() << " has ";
  switch (a) {
  case pig:
    [[fallthrough]];
  case goat:
  case cat:
  case dog:
    cout << 4;
    break;
  case duck:
    [[fallthrough]];
  case chicken:
    cout << 2;
    break;
  default:
    cout << "Error: Animal not found\n";
    return;
  }
  cout << " legs.\n";
}

int main() {
  printNumberOfLegs(Animal::cat);
  printNumberOfLegs(Animal::chicken);
}
