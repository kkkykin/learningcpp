#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Student {
  std::string_view name{};
  int points{};
};

int main() {
  constexpr std::array<Student, 8> arr{
      {{"Albert", 3},
       {"Ben", 5},
       {"Christine", 2},
       {"Dan", 8}, // Dan has the most points (8).
       {"Enchilada", 4},
       {"Francis", 1},
       {"Greg", 3},
       {"Hagrid", 5}}};
  constexpr auto maxPoint{[](Student a, Student b) {
    return (a.points < b.points);
  }};
  auto max{std::max_element(arr.begin(), arr.end(), maxPoint)};
  std::cout << max -> name << " is the best student.\n";
  return 0;
}
