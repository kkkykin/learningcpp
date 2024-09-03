#include <iostream>

struct Website {
  int watched{};
  double per{};
  int earn{};
};

void printValue(Website &a) {
  std::cout << a.watched << " * " << a.per << " * " << a.earn << " = ";
  std::cout << (a.watched * a.per * a.earn);
}

void inputWeb(Website &a) {
  using std::cin;
  cin >> a.watched;

  cin >> a.per;
  cin >> a.earn;
  
}

int main() {
  Website a{};
  inputWeb(a);
  printValue(a);
}
