#ifndef PRINTVECTOR0_H
#define PRINTVECTOR0_H

#include <iostream>

void printVector(const auto &a) {
  for (std::size_t i{0}; i < std::size(a); ++i) {
    std::cout << a[i] << '\t';
  }
  std::cout << '\n';
}

#endif
