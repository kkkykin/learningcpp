#include "io1.h"

int main() {
  [[maybe_unused]] int a{readNumber()}, b{readNumber()};
  writeAnswer(a + b);
}
