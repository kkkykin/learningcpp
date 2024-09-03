namespace MonsterType {
enum MonsterType {
  orc,
  goblin,
  troll,
  ogre,
  skeleton,
};
}

int main() {
  constexpr MonsterType::MonsterType a{MonsterType::troll};
  static_assert((MonsterType::troll == a), "Yes");
  return 0;
}
