#include "printVector0.h"

#include <iostream>
#include <vector>

std::vector<int> inputVector(int count) {
  std::cout << "Enter " << count << " integers: ";
  std::vector<int> init{};
  for (int x{}; count > 0; --count) {
    std::cin >> x;
    init.insert(init.end(), x);
  }
  return init;
}

int sumVector(const std::vector<int> &a) {
  int sum{0};
  for (std::size_t i{}; i < std::size(a); ++i) {
    sum += a[i];
  }
  return sum;
}

int productVector(const std::vector<int> &a) {
  int product{1};
  for (std::size_t i{}; i < std::size(a); ++i) {
    product *= a[i];
  }
  return product;
}

int main() {
  std::vector a{inputVector(3)};
  printVector(a);
  std::cout << "The sum is: " << sumVector(a) << '\n';
  std::cout << "The product is: " << productVector(a) << '\n';
  return 0;
}
