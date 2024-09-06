#include <iostream>
#include <vector>
#include <string_view>

void printStackValue(const std::vector<int> &a) {
  for (int b : a) {
    std::cout << ' ' << b;
  }
}

void printStack(const std::vector<int> &a) {
  std::cout << '\t' << "(Stack:";
  if (std::size(a) == 0)
    std::cout << " empty";
  else printStackValue(a);
  std::cout << ")\n";
}

void PushPrint(std::vector<int> &a, int value) {
  a.push_back(value);
  std::cout << "Push \t" << value;
  printStack(a);
}

void PopPrint(std::vector<int> &a) {
  a.pop_back();
  std::cout << "Pop \t";
  printStack(a);
}

int main() {
  std::vector<int> a{};
  std::cout << '\t';
  printStack(a);
  PushPrint(a, 1);
  PushPrint(a, 2);
  PushPrint(a, 3);
  PopPrint(a);
  PushPrint(a, 4);
  PopPrint(a);
  PopPrint(a);
  return 0;
}
