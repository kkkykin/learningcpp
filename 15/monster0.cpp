#include "monster1.h"
#include "monster2.h"

int main() {
  // std::cout << MonsterGenerator::getName(0);
  Monster m{ MonsterGenerator::generate() };
  m.print();

  // Monster skeleton{ Monster::skeleton, "Bones", "*rattle*", 4 };
  // skeleton.print();

  // Monster vampire{ Monster::vampire, "Nibblez", "*hiss*", 0 };
  // vampire.print();

  // Monster skeleton{Monster::skeleton, "Bones", "*rattle*", 4};
  // std::cout << getTypeString(&skeleton).value();
  return 0;
}
