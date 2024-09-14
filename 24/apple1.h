#include <iostream>

#include <string>
#include <string_view>

class Fruit {
private:
  std::string m_name{};
  std::string m_color{};

public:
  Fruit(std::string_view n, std::string_view c) : m_name{n}, m_color{c} {}
  const std::string &getName() const { return m_name; }
  const std::string &getColor() const { return m_color; }
};

class Apple : public Fruit {
private:
  double m_fiber{};

public:
  Apple(std::string_view n, std::string_view c, double f)
      : Fruit{n, c}, m_fiber{f} {}

  Apple(std::string_view c): Fruit("Apple", c){}
  
  double getFiber() const { return m_fiber; }
};

class Banana : public Fruit {
public:
  Banana(std::string_view n, std::string_view c) : Fruit{n, c} {}
  Banana() : Fruit{"Banana", "yellow"} {}
};

class GrannySmith : public Apple {
public:
  GrannySmith() : Apple{"granny smith apple", "green", 0} {}
};

std::ostream &operator<<(std::ostream &out, const Fruit &f);

std::ostream &operator<<(std::ostream &out, const Apple &a);

std::ostream &operator<<(std::ostream &out, const Banana &b);
