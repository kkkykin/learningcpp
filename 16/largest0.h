#ifndef LARGEST0_H
#define LARGEST0_H

#include <vector>

template <typename T>
T findMax(const std::vector<T> &a) {
  const std::size_t length{std::size(a)};
  if (length < 1)
    return T{};

  T x{a[0]};
  for (std::size_t i{0}; i < length; ++i) {
    if (a[i] > x)
      x = a[i];
  }
  return x;
}

#endif
