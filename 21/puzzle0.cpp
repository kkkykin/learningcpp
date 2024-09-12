// #include "puzzle1.h"
#include "puzzle2.h"
#include "puzzle3.h"
#include "puzzle4.h"

int main()
{
    Board board{};
    board.shuffleBoard();
    std::cout << board;

    while (true) {
      using std::cout;
      Direction m{UserInput::handleInput()};
      if (m.getDir() == Direction::maxDirections) {
        return 0;
      }
      std::cout << board.moveTile(m);
      if (board.checkWin()) {
        std::cout << "\n\nYou won!\n\n";
        return 0;
      }
    }
    return 0;
}
