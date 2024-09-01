#include <iostream>
#include <string_view>

// Write the function getQuantityPhrase() here
constexpr std::string_view getQuantityPhrase(int maryApples) {
  switch (maryApples) {
  case 0:
    return "no";
  case 1:
    return "a single";
  case 2:
    return "a couple of";
  case 3:
    return "a few";
  default:
    if (maryApples < 0)
      return "negative";
    else
      return "many";
  }
}

// Write the function getApplesPluralized() here
constexpr std::string_view getApplesPluralized(int maryApples) {
  if (maryApples == 1)
    return "apple";
  else
    return "apples";
}

int main()
{
    constexpr int maryApples { 3 };
    std::cout << "Mary has " << getQuantityPhrase(maryApples) << ' ' << getApplesPluralized(maryApples) << ".\n";

    std::cout << "How many apples do you have? ";
    int numApples{};
    std::cin >> numApples;

    std::cout << "You have " << getQuantityPhrase(numApples) << ' ' << getApplesPluralized(numApples) << ".\n";

    return 0;
}
