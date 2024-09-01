#include "random.h"
#include <iostream>
#include <string_view>

int askInt() {
  int a{0};
  std::cin >> a;
  return a;
}

bool inGame(int target, int times) {
  using std::cout;
  std::string_view guess{"Your guess is too "};
  for (int i{1}, j{0}; i <= times; ++i) {
    cout << "Guess #" << i << ": ";
    j = askInt();
    if (j < target)
      cout << guess << "low.\n";
    else if (j > target)
      cout << guess << "high.\n";
    else {
      return true;
    }
  }
  return false;
}

void startGame(int min = 1, int max = 100, int times = 7) {
  std::cout << "Let's play a game. I'm thinking of a number between " << min
            << " and " << max << ". You have " << times
            << " tries to guess what it is.\n";
}

void configureGame() {
  int min{askInt()};
  int max(askInt());
  while (min > max) {
    std::cout << "min bigger than max, reinput please: \n";
    min = askInt();
    max = askInt();
  }
  int target{Random::get(min, max)};
  startGame(min, max, 7);
  using std::cout;
  if (inGame(target, 7))
    cout << "Correct! You win!.\n";
  else
    cout << "Sorry, you lose. The correct number was " << target << '\n';
}

bool yesOrNo() {
  std::cout << "Would you like to play again (y/n)? ";
  char ans{'n'};
  do
    std::cin >> ans;
  while ((ans != 'y') && ans != 'n');
  if (ans == 'y')
    return true;
  else
    return false;
}

int main() {
  do
    configureGame();
  while (yesOrNo());
  return 0;
}
