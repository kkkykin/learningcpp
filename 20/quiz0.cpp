#include <iostream>

double max(double a, double b) {
  return (a > b) ? a : b;
}

void swap(int& a, int& b) {
  int x{};
  x = a;
  a = b;
  b = a;
}

auto& getLargestElement(auto *v, auto length) {
  
}
