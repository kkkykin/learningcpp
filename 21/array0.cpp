#include <iostream>

class IntArray {
private:
  int *array[1]{};

public:
  IntArray(int x) : array{new int[x]} {};
  // IntArray(const IntArray &x) : array{new int[x.getLength()]} {}
  ~IntArray() { delete[] *array; }
  int &operator[](int x) { return *(array[x]); }
  int getLength() const { return static_cast<int>(std::size(array)); }
};

std::ostream &operator<<(std::ostream &out, IntArray &a) {
  for (int i{}; i < a.getLength(); ++i) {
    out << a[i];
  }
  return out;
}

IntArray fillArray() {
  IntArray a(5);

  a[0] = 5;
  a[1] = 8;
  a[2] = 2;
  a[3] = 3;
  a[4] = 6;

  return a;
}

int main() {
  IntArray a{fillArray()};

  std::cout << a << '\n';

  auto &ref{
      a}; // we're using this reference to avoid compiler self-assignment errors
  a = ref;

  IntArray b(1);
  b = a;

  a[4] = 7;

  std::cout << b << '\n';

  return 0;
}
