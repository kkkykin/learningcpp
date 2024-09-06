#include <iostream>
#include <vector>
#include <utility>
#include <cassert>

template <typename T>
std::pair<std::size_t, T> findMin(const std::vector<T> &a) {
  assert(!(a.empty()));
  std::size_t index{0};
  T min{a[0]};
  for (std::size_t i{1}; i < std::size(a); ++i) {
    if (a[i] < min) {
      index = i;
      min = a[i];
    }
  }
  return std::pair<std::size_t, T>{index, min};
}

template <typename T>
std::pair<std::size_t, T> findMax(const std::vector<T> &a) {
  assert(!(a.empty()));
  std::size_t index{0};
  T max{a[0]};
  for (std::size_t i{1}; i < std::size(a); ++i) {
    if (a[i] > max) {
      index = i;
      max = a[i];
    }
  }
  return std::pair<std::size_t, T>{index, max};
}

void printResult(const auto &a) {
  using std::cout;
  const std::pair min{findMin(a)};
  const std::pair max{findMax(a)};
  cout << "The min element has index " << min.first << " and value " << min.second << '\n';
  cout << "The max element has index " << max.first << " and value " << max.second << '\n';
}

int main() {
  std::vector v1 { 3, 8, 2, 5, 7, 8, 3 };
  std::vector v2{5.5, 2.7, 3.3, 7.6, 1.2, 8.8, 6.6};
  
  printResult(v1);
  printResult(v2);
}
