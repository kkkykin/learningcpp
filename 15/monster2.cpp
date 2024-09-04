#include "monster1.h"
#include "monster2.h"
#include "../8/random.h"

std::string_view resolveTypeString(Monster::Type a) {
  using enum Monster::Type;
  switch (a) {
  case dragon:   return "dragon";
  case goblin:   return "goblin";
  case ogre:     return "ogre";
  case orc:      return "orc";
  case skeleton: return "skeleton";
  case troll:    return "troll";
  case vampire:  return "vampire";
  case zombie:   return "zombie";
  default:       return {};
  }
};

std::optional<std::string_view> getTypeString(const Monster *a) {
  return resolveTypeString(a -> getType());
}

using namespace MonsterGenerator;

Monster MonsterGenerator::generate() {
  return Monster{static_cast<Monster::Type>(Random::get(0, 5)),
                 getName(Random::get(0, 5)), getRoar(Random::get(0, 5)),
                 Random::get(0, 100)};
  
}

std::string_view MonsterGenerator::getName(int a) {
  switch (a) {
  case 0:  return "Blarg";
  case 1:  return "Moog";
  case 2:  return "Pksh";
  case 3:  return "Tyrn";
  case 4:  return "Mort";
  case 5:  return "Hans";
  default: return "???";
  }
}

std::string_view MonsterGenerator::getRoar(int n)
{
  switch (n)
    {
    case 0:  return "*ROAR*";
    case 1:  return "*peep*";
    case 2:  return "*squeal*";
    case 3:  return "*whine*";
    case 4:  return "*growl*";
    case 5:  return "*burp*";
    default: return "???";
    }
}
