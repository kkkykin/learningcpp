#include <iostream>

using Radian = double;
using Degree = double;

namespace constants
{
    inline constexpr double pi { 3.14159 };
}

constexpr Radian convertToRadians(Degree degrees)
{
    return degrees * constants::pi / 180;
}

int main()
{
    std::cout << "Enter a number of degrees: ";
    Degree degrees{};
    std::cin >> degrees;

    Radian radians { convertToRadians(degrees) };
    std::cout << degrees << " degrees is " << radians << " radians.\n";

    return 0;
}
