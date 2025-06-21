#include <iostream>
#include <utils.h>

int main(int argc, char **argv) {
  programArgs args{argc, argv};

  for (auto stringArg : args.getArguments()) {
    std::cout << stringArg << std::endl;
  }

  return 0;
}
