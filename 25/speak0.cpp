#include <array>
#include <iostream>
#include <string>

class Animal {
private:
  std::string m_name{};
  std::string m_speak{};

public:
  Animal(std::string_view n, std::string_view s) : m_name{n}, m_speak{s} {}
  const std::string &getName() const { return m_name; }
  const std::string& speak() const { return m_speak; }
};

class Cat : public Animal {
public:
  Cat(std::string_view n) : Animal{n, "meow"} {}
};

class Dog : public Animal {
public:
  Dog(std::string_view n) : Animal{n, "bark"} {}
};

int main()
{
    const Cat fred{ "Fred" };
    const Cat misty{ "Misty" };
    const Cat zeke{ "Zeke" };

    const Dog garbo{ "Garbo" };
    const Dog pooky{ "Pooky" };
    const Dog truffle{ "Truffle" };

    // Set up an array of pointers to animals, and set those pointers to our Cat and Dog objects
    const auto animals{ std::to_array<const Animal*>({ &fred, &garbo, &misty, &pooky, &truffle, &zeke }) };

    // Before C++20, with the array size being explicitly specified
    // const std::array<const Animal*, 6> animals{ &fred, &garbo, &misty, &pooky, &truffle, &zeke };

    for (const auto animal : animals)
    {
        std::cout << animal->getName() << " says " << animal->speak() << '\n';
    }

    return 0;
}
