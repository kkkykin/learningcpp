#include <iostream>
#include <algorithm>
#include <initializer_list>

class IntArray {
private:
  int m_length{};
  int *m_array{};

public:
  IntArray() = default;
  IntArray(int x)
      : m_length{x}, m_array{new int[x]{}} {}
  IntArray(std::initializer_list<int> list)
    : IntArray(static_cast<int>(list.size())) {
    std::copy(list.begin(), list.end(), m_array);
  }

  	IntArray& operator=(std::initializer_list<int> list)
	{
		// If the new list is a different size, reallocate it
		int length { static_cast<int>(list.size()) };
		if (length != m_length)
		{
			delete[] m_array;
			m_length = length;
			m_array = new int[list.size()]{};
		}

		// Now initialize our array from the list
		std::copy(list.begin(), list.end(), m_array);

		return *this;
	}

  // IntArray &operator=(IntArray &&t) noexcept {
  //   erase();
  //   m_length = t.getLength();
  //   m_array = t.getArray();
  //   t.m_array = nullptr;
  //   return *this;
  // }

  ~IntArray() {
    delete[] m_array;
  }

  IntArray(const IntArray&) = delete; // to avoid shallow copies
  IntArray& operator=(const IntArray& list) = delete; // to avoid shallow copies

  void erase() {
    m_length = 0;
    delete[] m_array;
    m_array = nullptr;
  }
  int *getArray() {
    return m_array;
  }
  int getLength() const {
    return m_length;
  }
  int operator[](int i) const {
    return m_array[i];
  }
};

int main()
{
	IntArray array { 5, 4, 3, 2, 1 }; // initializer list
	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	array = { 1, 3, 5, 7, 9, 11 };

	for (int count{ 0 }; count < array.getLength(); ++count)
		std::cout << array[count] << ' ';

	std::cout << '\n';

	return 0;
}
