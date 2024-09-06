#include <iostream>
#include <array>

int main() {
  constexpr std::array a{'h', 'e', 'l', 'l', 'o'};
  std::cout << std::size(a) << a[1] << a.at(1) << std::get<1>(a);
}
