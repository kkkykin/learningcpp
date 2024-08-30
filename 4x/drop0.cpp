#include <iostream>

double getInput() {
  double a{};
  std::cin >> a;
  return a;
}

void printHeight(int seconds, double height) {
  std::cout << "At " << seconds << " seconds, the ball is ";
  if (height == 0)
    std::cout << "on the ground.\n";
  else
    std::cout << "at height: " << height << " meters\n";
}

double calcHeight(int seconds, double top) {
  double gravity{9.8};
  double fallen{gravity * seconds * seconds / 2};
  return top - fallen;
}

int main() {
  double top{getInput()};
  double cur{top};
  for (int i{0}; i < 6; i++) {
    cur = calcHeight(i, top);
    if (cur < 0) {
      printHeight(i, 0);
      break;
    }
    else
      printHeight(i, cur);
  }
  return 0;
}
