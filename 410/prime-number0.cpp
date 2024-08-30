#include <iostream>

bool is_prime(int a) {
  bool flag{false};
  if (a == 2)
    flag = true;
  else if (a == 3)
    flag = true;
  else if (a == 5)
    flag = true;
  else if (a == 7)
    flag = true;
  return flag;
}

int main() {
  int a{};
  std::cin >> a;
  if (is_prime(a))
    std::cout << "Yes\n";
  else
    std::cout << "No\n";
  return 0;
}
