#include <iostream>
#include <algorithm>
#include <string>

int main() {
  int length{};
  std::cin >> length;
  std::string *names{new std::string[length]};
  for (int i{}; i < length; ++i) {
    std::getline(std::cin >> std::ws, *(i + names));
  }
  std::sort(names, names + length);
  for (int i{}; i < length; ++i) {
    std::cout << *(i + names) << ' ';
  }
  delete[] names;
  return 0;
}
