#ifndef FIGHT1_HH
#define FIGHT1_HH

#include <iostream>
#include <string>
#include <string_view>

class Creature {
protected:
  std::string m_name{};
  char m_symbol{};
  int m_health{};
  int m_damage{};
  int m_gold{};

public:
  Creature(std::string_view n, char s, int h, int d, int g)
      : m_name{n}, m_symbol{s}, m_health(h), m_damage(d), m_gold(g) {}

  const std::string &getName() const { return m_name; }
  char getSymbol() const { return m_symbol; }
  int getHealth() const { return m_health; }
  int getDamage() const { return m_damage; }
  int getGold() const { return m_gold; }

  void reduceHealth(int x) { m_health -= x; }
  bool isDead() const { return m_health <= 0; }
  void addGold(int x) {
    std::cout << "You found " << x << " gold.\n";
    m_gold += x; }
};

class Player : public Creature {
private:
  int m_level{1};

public:
  Player(std::string_view n);

  void levelUp() {
    std::cout << "You are now level " << m_level << '\n';
    ++m_level;
    ++m_damage;
  }

  int getLevel() const { return m_level; }

  bool hasWon() const { return m_level >= 6; }
};

class Monster : public Creature {
public:
  enum Type {
    dragon,
    orc,
    slime,
    maxTypes,
  };

private:
  static inline Creature monsterData[]{{"dragon", 'D', 20, 4, 100},
                                       {"orc", 'o', 4, 2, 25},
                                       {"slime", 's', 1, 1, 10}};

public:
  Monster(Type x);
};

bool fightMonster(Player &p, Monster &m);

#endif
