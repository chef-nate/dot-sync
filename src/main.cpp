#include <cstdlib>
#include <utils.h>

// These get passed into optionManager and declared so that the args (argc,
// argv) can be properally parsed
std::vector<option> Args = {};

int main(int argc, char **argv) {
  programArgs args{argc, argv};

  return EXIT_SUCCESS;
}
