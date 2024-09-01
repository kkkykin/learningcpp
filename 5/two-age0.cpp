#include <iostream>
#include <string_view>
#include <string>

std::string getName() {
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  return name;
}

int getAge() {
  int age{};
  std::cin >> age;
  return age;
}

void printResult(std::string_view oldName, int oldAge,
                 std::string_view youngName, int youngAge) {
  std::cout << oldName << " (age " << oldAge << ") is older than " << youngName
            << " (age " << youngAge << ").";
}

int main() {
  const std::string aname{getName()};
  const int aage{getAge()};
  const std::string bname{getName()};
  const int bage{getAge()};
  if (aage > bage)
    printResult(aname, aage, bname, bage);
  else
    printResult(bname, bage, aname, aage);
  return 0;
}
