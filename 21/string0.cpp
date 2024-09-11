#include <iostream>
#include <string_view>

class MyString {
private:
  std::string_view str{};

public:
  MyString(std::string_view s) : str{s} {};
  std::string_view getStr() const {
    return str;
  }

  std::string_view operator()(int b, int l) const {
    return str.substr(static_cast<std::size_t>(b), static_cast<std::size_t>(l));
  }
};

std::ostream &operator<<(std::ostream &out, MyString &s) {
  out << s.getStr();
  return out;
}

int main() {
  MyString s { "Hello, world!" };
  std::cout << s(7, 5) << '\n'; // start at index 7 and return 5 characters
  return 0;
}
