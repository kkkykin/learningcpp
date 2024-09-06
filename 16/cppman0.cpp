#include "../8/random.h"

#include <iostream>
#include <vector>
#include <string_view>
#include <string>
#include <limits>

namespace WordList {
  using namespace std::string_view_literals;
  std::vector words{"mystery"sv,   "broccoli"sv,  "account"sv,
                    "almost"sv,    "spaghetti"sv, "opinion"sv,
                    "beautiful"sv, "distance"sv,  "luggage"sv};
  std::string_view getRandomWord() {
    return words[Random::get<std::size_t>(0, std::size(words) - 1)];
  }
}

class Session {
private:
  const std::string answer{WordList::getRandomWord()};
  std::vector<char> guessted{};
  std::vector<char> correct{};
  std::vector<char> wrong{};

public:
  std::string_view getAnswer() const {
    return answer;
  }
  const std::vector<char> &getGuessted() const {
    return guessted;
  }
  const std::vector<char> &getCorrect() const {
    return correct;
  }
  const std::vector<char> &getWrong() const {
    return wrong;
  }
  void pushGuessted(char a) {
    guessted.push_back(a);
    bool input{true};
    for (const auto &b : answer) {
      if (a == b) {
        correct.push_back(a);
        input = false;
        break;
      }
    }
    if (input)
      wrong.push_back(a);
  }
};

bool printCurrent(Session &a) {
  std::cout << "The word: ";
  bool win{true};
  for ([[maybe_unused]] const auto &x : a.getAnswer()) {
    bool space{true};
    for (const auto y : a.getCorrect()) {
      if (y == x) {
        std::cout << y;
        space = false;
      }
    }
    if (space) {
      std::cout << '_';
      win = false;
    }
  }
  if (win) {
    std::cout << "You win.";
  } else {
    const std::vector<char> wrong{a.getWrong()};
    std::cout << "\tWrong times: " << std::size(wrong) << "\t\tIncorrect letters:";
    for (const auto &x : wrong) {
      std::cout << ' ' << x;
    }
  }
  std::cout << '\n';
  return win;
}

void prepairGame() {
  std::cout << "Welcome to C++man (a variant of Hangman)\n"
               "To win: guess the word. To lose: run out of pluses.\n\n";
}

char inputValidChar(Session &c) {
  while (true) {
    char a{};
    std::cout << "Enter your next letter: ";
    std::cin >> a;
    bool repeated{false};
    for (const auto b : c.getGuessted()) {
      if (b == a) {
        repeated = true;
        break;
      }
    }
    if (!std::cin || a < 'a' || a > 'z' || repeated) {
      std::cin.clear();
      std::cout << "That wasn't a valid input. Try again.\n";
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      continue;
    } else {
      c.pushGuessted(a);
      return a;
    }
  }
}

void gaming(Session &a) {
  while (!printCurrent(a)) {
    if (std::size(a.getWrong()) > 5) {
      std::cout << "You failed.\n";
      break;
    }
    inputValidChar(a);
  }
}

int main() {
  Session a{};
  prepairGame();
  gaming(a);
  return 0;
}
