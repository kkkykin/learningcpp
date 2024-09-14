#include <iostream>
#include <string>
#include <vector>
#include <functional>

// ...
class Teacher {
  std::string m_name{};

public:
  Teacher(const std::string_view n) : m_name{n}{};
  std::string_view getName() const {
    return m_name;
  }
};

class Department {
  std::vector<std::reference_wrapper<const Teacher>> m_teachers{};

public:
  void add(const Teacher &t) {
    m_teachers.emplace_back(t);
  }
  auto &getTeachers() {
    return m_teachers;
  };
};

std::ostream &operator<<(std::ostream &out, Department &d) {
  out << "Department:";
  for (const auto &x : d.getTeachers()) {
    out << ' ' << x.get().getName();
  }
  out << '\n';
  return out;
}

int main()
{
  // Create a teacher outside the scope of the Department
  Teacher t1{ "Bob" };
  Teacher t2{ "Frank" };
  Teacher t3{ "Beth" };

  {
    // Create a department and add some Teachers to it
    Department department{}; // create an empty Department

    department.add(t1);
    department.add(t2);
    department.add(t3);

    std::cout << department;

  } // department goes out of scope here and is destroyed

  std::cout << t1.getName() << " still exists!\n";
  std::cout << t2.getName() << " still exists!\n";
  std::cout << t3.getName() << " still exists!\n";

  return 0;
}
