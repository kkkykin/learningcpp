#include "../8/random.h"

#include <algorithm>
#include <array>
#include <iostream>
#include <string_view>

struct Card {
  enum Rank {
    rank_ace,
    rank_2,
    rank_3,
    rank_4,
    rank_5,
    rank_6,
    rank_7,
    rank_8,
    rank_9,
    rank_10,
    rank_jack,
    rank_queen,
    rank_king,
    maxRank,
  };
  enum Suit {
    suit_club,
    suit_diamond,
    suit_heart,
    suit_spade,
    maxSuit,
  };

  // using Desk2d = std::array<std::array<int, maxSuit>, maxRank>;

  // Desk2d
  Rank rank{};
  Suit suit{};

  static constexpr std::array allRanks{
      rank_ace, rank_2, rank_3,  rank_4,    rank_5,     rank_6,   rank_7,
      rank_8,   rank_9, rank_10, rank_jack, rank_queen, rank_king};
  static constexpr std::array allSuits{suit_club, suit_diamond, suit_heart,
                                       suit_spade};

  static_assert(std::size(allRanks) == maxRank);
  static_assert(std::size(allSuits) == maxSuit);

  friend std::ostream &operator<<(std::ostream &out, const Card &card) {

    static constexpr std::array<char, maxRank> ranks{
        'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};
    static constexpr std::array<char, maxSuit> suits{'C', 'D', 'H', 'S'};
    out << ranks[card.rank] << suits[card.suit];
    return out;
  }

  int value() const {
    static constexpr std::array rankValue{11, 2, 3,  4,  5,  6, 7,
                                          8,  9, 10, 10, 10, 10};
    return rankValue[rank];
  }
};

class Deck {
private:
  std::array<Card, 52> m_cards{};
  std::size_t m_curCard{0};

public:
  Deck() {
    std::size_t i{0};
    for (auto suit : Card::allSuits)
      for (auto rank : Card::allRanks) {
        m_cards[i] = Card{rank, suit};
        ++i;
      }
  }
  Card dealCard() { return m_cards[m_curCard++]; }
  void shuffle() {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
    m_curCard = 0;
  }
  auto &getCards() { return m_cards; }
};

struct Player {
  int score{};
};

namespace Settings {
constexpr int playerBust{21};
constexpr int dealerDraw{17};
} // namespace Settings

int drawCard(Deck &d, Player &p, std::string_view name) {
  Card card{d.dealCard()};
  int value{card.value()};
  p.score += value;
  std::cout << "The " << name << " flips a " << card
            << ". They now have: " << p.score << '\n';
  return p.score;
}

void ignoreLine() {
  std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

bool playerHit() {
  char x{};
  while (true) {
    std::cin >> x;
    if (!std::cin) {
      std::cin.clear();
      ignoreLine();
      continue;
    }
    if (!std::cin.eof() && std::cin.peek() != '\n') {
      ignoreLine();
      continue;
    }
    if (x == 'h')
      return true;
    else
      return false;
  }
}

bool playBlackJack() {
  Deck deck{};
  deck.shuffle();
  Player dealer{deck.dealCard().value()};
  std::cout << "The dealer is showing: " << dealer.score << '\n';
  Player player{};
  for (int i{}; i < 2; ++i) {
    player.score += deck.dealCard().value();
  }
  std::cout << "You have score " << player.score << '\n';

  while (player.score < Settings::playerBust && playerHit()) {
    drawCard(deck, player, "player");
    if (dealer.score < Settings::dealerDraw)
      drawCard(deck, dealer, "dealer");
  }
  while (player.score <= Settings::playerBust &&
         dealer.score < Settings::dealerDraw) {
    drawCard(deck, dealer, "dealer");
  }
  if (dealer.score > Settings::playerBust) {
    std::cout << "The dealer went bust!\n";
    return true;
  } else if (player.score > Settings::playerBust) {
    std::cout << "You went bust!\n";
    return false;
  } else if (player.score > dealer.score) {
    return true;
  } else {
    return false;
  }
}

void gameOver(bool w) {
  if (w)
    std::cout << "You win!\n";
  else
    std::cout << "You lose!\n";
}

int main() {
  // std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
  //           << deck.dealCard() << '\n';

  // std::cout << deck.dealCard() << ' ' << deck.dealCard() << ' '
  //           << deck.dealCard() << '\n';

  gameOver(playBlackJack());
  return 0;
}
