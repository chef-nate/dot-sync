#include <iostream>
#include <ranges>
#include <string>
#include <vector>

struct programArgs {
  int argCount;
  char **argVector;

  int getCount();
  std::vector<std::string> getArguments();

  programArgs(int argc, char **argv);
};

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

int main(int argc, char **argv) {
  programArgs args{argc, argv};

  for (auto stringArg : args.getArguments()) {
    std::cout << stringArg << std::endl;
  }

  return 0;
}
