#include <iostream>
#include <cstdint>

class Average {
private:
  std::int32_t m_sum{};
  std::int32_t m_count{};

public:
  std::int32_t getSum() const {
    return m_sum;
  }
  std::int32_t getCount() const {
    return m_count;
  }
  Average &operator+=(int x) {
    m_sum += x;
    ++m_count;
    return *this;
  }
};

std::ostream &operator<<(std::ostream &out, const Average &a) {
  if (a.getCount() == 0) {
    out << 0;
    return out;
  }
  out << static_cast<double>(a.getSum()) / a.getCount();
  return out;
}

int main()
{
	Average avg{};
	std::cout << avg << '\n';

	avg += 4;
	std::cout << avg << '\n'; // 4 / 1 = 4

	avg += 8;
	std::cout << avg << '\n'; // (4 + 8) / 2 = 6

	avg += 24;
	std::cout << avg << '\n'; // (4 + 8 + 24) / 3 = 12

	avg += -10;
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10) / 4 = 6.5

	(avg += 6) += 10; // 2 calls chained together
	std::cout << avg << '\n'; // (4 + 8 + 24 - 10 + 6 + 10) / 6 = 7

	Average copy{ avg };
	std::cout << copy << '\n';

	return 0;
}
