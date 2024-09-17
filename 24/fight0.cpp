#include "fight1.hh"
#include "../8/random.h"

#include <iostream>
#include <string>

std::string inputName() {
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  return name;
}

// int main() {
//   Monster m{Monster::Type::orc};
//   std::cout << "A " << m.getName() << " (" << m.getSymbol()
//             << ") was created.\n";

//   return 0;
// }

int main() {
  std::cout << "Enter your name: ";
  Player player{inputName()};
  
  while (!player.hasWon()) {
    Monster m{static_cast<Monster::Type>(Random::get(0, Monster::Type::maxTypes - 1))};

    while (true) {
      if (fightMonster(player, m))
        break;
    }

    if (player.getHealth() <= 0) {
      std::cout << "You died at level " << player.getLevel() << " and with "
                << player.getGold() << " gold.\n";
      break;
    }
  }
  return 0;
}

// int main()
// {
// 	Creature o{ "orc", 'o', 4, 2, 10 };
// 	o.addGold(5);
// 	o.reduceHealth(1);
// 	std::cout << "The " << o.getName() << " has " << o.getHealth() << "
// health and is carrying " << o.getGold() << " gold.\n";

// 	return 0;
// }
