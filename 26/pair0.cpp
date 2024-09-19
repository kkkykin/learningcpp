#include <iostream>
#include <string>

template <typename T> class Pair1 {
private:
  T m_first{};
  T m_second{};

public:
  Pair1(const T &a, const T &b) : m_first{a}, m_second{b} {}
  const T& first() const {return m_first;}
  const T& second() const {return m_second;}
};

template <typename T1, typename T2> class Pair {
private:
  T1 m_first{};
  T2 m_second{};

public:
  Pair(const T1 &a, const T2 &b) : m_first{a}, m_second{b} {}
  const T1& first()const {return m_first;}
  const T2& second()const {return m_second;}
};

template <typename T> class StringValuePair : public Pair<std::string, T> {
public:
  StringValuePair(std::string_view s, const T &t)
      : Pair<std::string, T>{static_cast<std::string>(s), t} {}
};

int main()
{
	StringValuePair<int> svp { "Hello", 5 };
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;
}

// int main()
// {
// 	Pair<int, double> p1 { 5, 6.7 };
// 	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

// 	const Pair<double, int> p2 { 2.3, 4 };
// 	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

// 	return 0;
// }

// int main()
// {
// 	Pair1<int> p1 { 5, 8 };
// 	std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

// 	const Pair1<double> p2 { 2.3, 4.5 };
// 	std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

// 	return 0;
// }
