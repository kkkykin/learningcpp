#include <iostream>
#include <string_view>

struct Monster {

  enum Type {
    ogre,
    dragon,
    orc,
    giantSpider,
    slime,
  };

  Type type{};
  std::string_view name{"???"};
  int health{100};
};

constexpr std::string_view getMonsterName(const Monster::Type &a) {
  using enum Monster::Type;
  switch (a) {
  case ogre:
    return "Ogre";
  case dragon:
    return "Dragon";
  case orc:
    return "Orc";
  case giantSpider:
    return "Giant Spider";
  case slime:
    return "Slime";
  default:
    return "???";
  }
}

void printMonster(const Monster& a) {
  std::cout << "This " << getMonsterName(a.type) << " is named " << a.name
            << " and has " << a.health << " health.\n";
}

int main() {
  printMonster({Monster::Type::ogre, "Torg", 145});
  printMonster({Monster::Type::slime, "Blurp", 23});
  return 0;
}
