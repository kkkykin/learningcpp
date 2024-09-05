#include <iostream>
#include <vector>
#include <string>
#include <string_view>

template <typename T>
bool isValueInArray(T name, const std::vector<T>& names) {
  bool flag = false;
  for (const auto &n : names) {
    if (name == n) {
      flag = true;
      break;
    }
  };
  return flag;
}

std::string inputName() {
  std::string a{};
  std::getline(std::cin >> std::ws, a);
  return a;
}

int main() {
  using namespace std::string_view_literals;
  static std::vector<std::string_view> names {
    "Alex"sv, "Betty"sv, "Caroline"sv, "Dave"sv, "Emily"sv, "Fred"sv, "Greg"sv,
        "Holly"sv
  };
  std::string a{inputName()};
  std::cout << a << " was "
            << ((isValueInArray<std::string_view>(a, names)) ? "" : "not ")
            << "found.";
  return 0;
}
