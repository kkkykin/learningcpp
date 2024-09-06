#include <iostream>
#include <vector>
#include <utility>

void inputVector(auto &a) {
  std::cout << "Enter numbers to add (use -1 to stop): ";
  int tmp{};
  while (tmp != -1) {
    std::cin >> tmp;
    if (a.empty() && tmp == -1) {
      tmp = 0;
      std::cout << "Please input valid vector.\n";
      continue;
    }
    a.push_back(tmp);
  }
}

void printVector(const auto &a) {
  std::cout << "With array (";
  for (std::size_t i{0}; i < std::size(a); ++i) {
    if (i > 0) {
      std::cout << ',';
    }
    std::cout << ' ' << a[i];
  }
  std::cout << " ):\n";
}

std::pair<std::size_t, std::size_t> findIndice(const auto &a) {
  std::size_t min{0};
  std::size_t max{0};
  for (std::size_t i{1}; i < std::size(a); ++i) {
    if (a[i] < a[min])
      min = i;
    if (a[i] > a[max])
      max = i;
  }
  return {min, max};
}

void printPair(const std::vector<int> &a) {
  const auto pair{findIndice(a)};
  std::cout << "The min element has index " << pair.first << " and value "
            << a[pair.first] << '\n';
  std::cout << "The max element has index " << pair.second << " and value "
            << a[pair.second] << '\n';
}

int main() {
  std::vector<int> a{};
  inputVector(a);
  printVector(a);
  printPair(a);
  return 0;
}
