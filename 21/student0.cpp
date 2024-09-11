#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

struct StudentGrade {
  std::string name{};
  char grade{};
};

class GradeMap {
private:
  std::vector<StudentGrade> m_map{};

public:
  char &operator[](std::string s) {
    const auto &found{std::find_if(m_map.begin(), m_map.end(),
                                   [&](const auto &m) { return m.name == s; })};
    if (found == m_map.end()) {
      return m_map.emplace_back(s).grade;
    } else {
      return found -> grade;
    }
  }
};

int main()
{
	GradeMap grades{};

	grades["Joe"] = 'A';
	grades["Frank"] = 'B';

	std::cout << "Joe has a grade of " << grades["Joe"] << '\n';
	std::cout << "Frank has a grade of " << grades["Frank"] << '\n';

	return 0;
}
