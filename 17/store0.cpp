#include "../8/random.h"

#include <array>
#include <iostream>
#include <limits>
#include <string>
#include <string_view>

namespace Potion {
enum Type {
  healing,
  mana,
  speed,
  invisibility,
  maxType,
};
constexpr std::array types{healing, mana, speed, invisibility};

constexpr std::array costs{20, 30, 12, 50};
using namespace std::string_view_literals;
constexpr std::array names{"healing"sv, "mana"sv, "speed"sv, "invisibility"sv};

static_assert(maxType == std::size(types));
static_assert(maxType == std::size(names));
static_assert(maxType == std::size(costs));
} // namespace Potion

class Player {
private:
  static constexpr int m_maxGold{120};
  static constexpr int m_minGold{80};

  const std::string_view m_name{};
  int m_gold{};
  std::array<int, Potion::maxType> m_inventory{};

public:
  Player(std::string_view n)
      : m_name{n}, m_gold{Random::get(m_minGold, m_maxGold)} {
    std::cout << "Hello, " << n << ", you have " << m_gold << " gold.\n\n";
  }
  constexpr int getGold() const { return m_gold; }
  constexpr auto &getInventory() const { return m_inventory; }
  void setGold(int g) { m_gold = g; }
  void addItem(std::size_t x, int count = 1) { m_inventory[x] += count; }
};

void shop() {
  std::cout << "Here is our selection for today:\n";
  for (const auto &i : Potion::types) {
    std::cout << i << ") " << Potion::names[i] << " costs " << Potion::costs[i]
              << '\n';
  }
}

int inputInt() {
  while (true) {
    char x{};
    std::cin >> x;
    if (x == 'q') {
      return Potion::maxType;
    }
    int y{x - '0'};
    if (!std::cin || y > Potion::maxType || y < 0) {
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    }
    return y;
  }
}

void printInventory(const Player &p) {
  std::cout << "\nYour inventory contains: \n";
  const auto inventory{p.getInventory()};
  for (const auto &x : Potion::types) {
    if (inventory[x] > 0) {
      std::cout << inventory[x] << "x potion of " << Potion::names[x] << '\n';
    }
  }
}

void shopping(Player &p) {
  int curGold{p.getGold()};
  while (true) {
    shop();
    std::cout
        << "Enter the number of the potion you'd like to buy, or 'q' to quit: ";
    std::size_t x{static_cast<std::size_t>(inputInt())};
    if (x == Potion::maxType) {
      p.setGold(curGold);
      printInventory(p);
      std::cout << "You escaped with " << curGold << " gold remaining.\n\n"
                << "Thanks for shopping at Roscoe's potion emporium!";
      break;
    } else if (curGold >= Potion::costs[x]) {
      curGold -= Potion::costs[x];
      p.addItem(x);
      std::cout << "You purchased a potion of " << Potion::names[x]
                << " You have " << curGold << " gold left.\n";
    } else {
      std::cout << "You can not affort that.\n";
    }
  }
}

int main() {
  std::cout << "Welcome to Roscoe's potion emporium!\nEnter your name: ";
  std::string name{};
  std::getline(std::cin >> std::ws, name);
  Player player{name};

  shopping(player);

  return 0;
}
