#include <cstdlib> // for std::exit
#include <iostream>
#include <limits> // for std::numeric_limits
#include <vector>

void ignoreLine()
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// returns true if extraction failed, false otherwise
bool clearFailedExtraction()
{
    // Check for failed extraction
    if (!std::cin) // If the previous extraction failed
    {
        if (std::cin.eof()) // If the stream was closed
        {
            exit(0); // Shut down the program now
        }

        // Let's handle the failure
        std::cin.clear(); // Put us back in 'normal' operation mode
        ignoreLine();     // And remove the bad input

        return true;
    }

    return false;
}

template <typename T>
T getNumber([[maybe_unused]] T a)
{
    while (true) // Loop until user enters a valid input
    {
        std::cout << "Enter a decimal number: ";
        T x{};
        std::cin >> x;

        if (clearFailedExtraction())
        {
            std::cout << "Oops, that input is invalid.  Please try again.\n";
            continue;
        }

        ignoreLine(); // Remove any extraneous input
        return x;     // Return the value we extracted
    }
}

template <typename T>
T findNumber(const std::vector<T> &a, T b) {
  for (std::size_t i{0}; i < std::size(a); ++i) {
    if (a[i] == b) {
      return static_cast<T>(i);
    }
  }
  return -1;
}

int main() {
  std::vector arr{ 4, 6, 7, 3, 8, 2, 1, 9 };
  std::vector ar{ 4.4, 6.6, 7.7, 3.3, 8.8, 2.2, 1.1, 9.9 };
  std::cout << "Enter a number between 1 and 9: ";
  auto x{getNumber(ar[0])};
  auto found{findNumber(ar, x)};
  std::cout << "The number " << x << ' ';
  if (found >= 0) {
    std::cout << "has index " << found;
  } else {
    std::cout << " was not found";
  }
  return 0;
}
