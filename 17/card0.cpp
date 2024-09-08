#include "../8/random.h"

#include <array>
#include <iostream>
#include <string_view>
#include <algorithm>

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

class Desk {
private:
  std::array<Card, 52> m_cards{};

public:
  Desk() {
    std::size_t i{0};
    for (auto suit : Card::allSuits)
      for (auto rank : Card::allRanks) {
        m_cards[i] = Card{rank, suit};
        ++i;
      }
  }
  void shuffle() {
    std::shuffle(m_cards.begin(), m_cards.end(), Random::mt);
  }
  auto &getCards() {
    return m_cards;
  }

};

int main() {
  // Print one card
  // Card card{Card::rank_5, Card::suit_heart};
  // std::cout << card << '\n';
  Desk desk{};
  desk.shuffle();
  for (const auto &x : desk.getCards()) {
    std::cout << x << ' ';
  }
  // Print all cards
  std::cout << '\n';

  return 0;
}
