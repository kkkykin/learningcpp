#ifndef MONSTER2_H
#define MONSTER2_H

#include "monster1.h"

#include <string_view>
#include <optional>

std::string_view resolveTypeString();

std::optional<std::string_view> getTypeString(const Monster *a);

namespace MonsterGenerator {
  Monster generate();
  std::string_view getName(int a);
  std::string_view getRoar(int n);
}

#endif
