#include <ranges>
#include <utils.h>

programArgs::programArgs(int argc, char **argv) {
  this->argCount = argc;
  this->argVector = argv;
}

int programArgs::getCount() { return this->argCount; }

std::vector<std::string> programArgs::getArguments() {
  std::vector<std::string> result = {};

  for (int i : std::views::iota(0, this->getCount())) {
    result.emplace_back(this->argVector[i]);
  }

  return result;
}
