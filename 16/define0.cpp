#include "printVector0.h"

#include <vector>

int main() {
  std::vector a{1, 4, 9, 16, 25};
  printVector(a);
  std::vector<int> b(5);
  printVector(b);
  return 0;
}
