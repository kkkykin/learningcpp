#include <array>
#include <iostream>

template <typename T, auto N> void printArray(const std::array<T, N> &a) {
  using std::cout;
  cout << "The array (";
  bool later{false};
  for (const auto &i : a) {
    if (later) {
      cout << ',';
    }
    later = true;
    cout << ' ' << i;
  }
  cout << " ) has length " << N << '\n';
}

int main()
{
    constexpr std::array arr1 { 1, 4, 9, 16 };
    printArray(arr1);

    constexpr std::array arr2 { 'h', 'e', 'l', 'l', 'o' };
    printArray(arr2);

    return 0;
}
