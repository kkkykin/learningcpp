#include "monster1.h"
#include "monster2.h"

#include <iostream>

Monster::Type Monster::getType() const {
  return m_type;
}

void Monster::print() const {
  std::optional<std::string_view> type{getTypeString(this)};
  using std::cout;
  cout << m_name << " the " << type.value();
  if (m_hit > 0)
    cout << " has " << m_hit << " hit points and says " << m_roar << ".\n";
  else
    cout << " is dead.\n";
}
