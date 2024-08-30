#include <iostream>
#include <string>

int main() {
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  int age{};
  std::cin >> age;
  std::cout << age + std::ssize(name);
}
