#include <string>
#include <vector>

class programArgs {
private:
  int argCount;
  char **argVector;

public:
  // Constructors etc...
  programArgs(int argc, char **argv);

  // member functions
  int getCount();
  std::vector<std::string> getArguments();
};
