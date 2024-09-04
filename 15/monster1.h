#ifndef MONSTER1_H
#define MONSTER1_H

#include <string>

class Monster {
public:
  enum Type {
    dragon,
    goblin,
    ogre,
    orc,
    skeleton,
    troll,
    vampire,
    zombie,
    maxMonsterTypes,
  };

  constexpr Monster(Type a, std::string_view b, std::string_view c, int d)
      : m_type{a}, m_name{b}, m_roar{c}, m_hit{d} {};

  void print() const;
  Type getType() const;

private:
  Type m_type{};
  std::string m_name{"???"};
  std::string m_roar{"???"};
  int m_hit{100};
};


#endif
