#include <iostream>
#include <cassert>

class IntArray {
private:
  int m_length{0};
  // 有指针顺带一个长度，初始化为 nullptr
  int *m_array{ nullptr };

public:
  explicit IntArray(int x) : m_length{x} {
    assert(x > 0 && "IntArray length should be a positive integer");
    m_array = new int[static_cast<std::size_t>(x)] {};
  }
  IntArray(const IntArray &x) : m_length{x.m_length} {
    deepCopy(x);
  }
  void deepCopy(const IntArray &x) {
    m_array = new int[static_cast<std::size_t>(m_length)]{};
    for (int i{}; i < x.m_length; ++i) {
      m_array[i] = x.m_array[i];
    }
  }
  ~IntArray() { delete[] m_array; }
  int &operator[](int x) { return m_array[x]; }
  int getLength() const { return m_length; }
  IntArray &operator=(const IntArray &x) {
    if (this == &x)
      return *this;
    m_length = x.m_length;
    deepCopy(x);
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, IntArray &a) {
  for (int i{}; i < a.getLength(); ++i) {
    out << a[i] << ' ';
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
