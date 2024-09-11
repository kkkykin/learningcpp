#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>

class Car {
private:
  std::string m_make;
  std::string m_model;

public:
  Car(std::string_view make, std::string_view model)
      : m_make{make}, m_model{model} {}

  friend bool operator==(const Car &c1, const Car &c2);
  friend bool operator!=(const Car &c1, const Car &c2);
  const std::string &getMake() const { return m_make; }
  const std::string &getModel() const { return m_model; }
};

bool operator<(const Car &a, const Car &b) {
  return (a.getMake() + a.getModel()) < (b.getMake() + b.getModel());
}

std::ostream &operator<<(std::ostream &out, const Car &c) {
  out << "(" << c.getMake() << ", " << c.getModel() << ")";
  return out;
}

int main() {
  std::vector<Car> cars{{"Toyota", "Corolla"},
                        {"Honda", "Accord"},
                        {"Toyota", "Camry"},
                        {"Honda", "Civic"}};

  std::sort(cars.begin(), cars.end()); // requires an overloaded operator<

  for (const auto &car : cars)
    std::cout << car << '\n'; // requires an overloaded operator<<

  return 0;
}
