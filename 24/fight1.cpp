#include "fight1.hh"
#include "../8/random.h"

#include <iostream>

Player::Player(std::string_view n) : Creature{n, '@', 10, 1, 0} {
  std::cout << "Welcome, " << n
            << ".\nYou have 10 health and are carrying 0 gold.\n";
}

Monster::Monster(Type x) : Creature{monsterData[x]} {
  std::cout << "You have encounter a " << m_name << " (" << m_symbol << ")\n";
}

bool attackMonster(Player &p, Monster &m) {
  m.reduceHealth(p.getDamage());
  std::cout << "You hit the " << m.getName() << " for " << p.getDamage()
            << " damage.\n";
  if (m.isDead()) {
    std::cout << "You killed the " << m.getName() << ".\n";
    p.levelUp();
    p.addGold(m.getGold());
    return true;
  }
  return false;
}

bool attackPlayer(Player &p, Monster &m) {
  p.reduceHealth(m.getDamage());
  std::cout << "The " << m.getName() << " hit you for " << m.getDamage()
            << " damage.\n";
  if (p.isDead()) {
    return true;
  }
  return false;
}

bool fightMonster(Player &p, Monster &m) {
  std::cout << "(R)un or (F)ight: ";
  char a{};
  std::cin >> a;

  if (a == 'r') {
    if (Random::get(0, 1)) {
      std::cout << "You successfully fled.\n";
      return true;
    }
    std::cout << "You failed to flee.\n";
    return attackPlayer(p, m);
  }

  if (attackMonster(p, m))
    return true;

  return attackPlayer(p, m);
}
