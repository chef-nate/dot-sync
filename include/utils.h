#include <memory>
#include <ranges>
#include <string>
#include <unordered_map>
#include <vector>

enum class optionArguments : int { None, One, Multiple };

struct option {
  std::string m_shortName;
  std::string m_longName;
  optionArguments m_argsAmount;
};

class optionManager {
private:
  std::unordered_map<std::string, std::shared_ptr<option>> m_optionsMap;

public:
  // add option with BOTH a short (e.g. h) and long (e.g. help) name
  bool addOption(std::string optionShort, std::string optionLong,
                 optionArguments optionArgsCount);

  // add option with ONLY a short (e.g. h) name
  bool addOption(std::string optionShort, optionArguments optionArgsCount);

  bool addOption(option option);

  /*
   * add multiple options from a predifned vector
   * NOTE: if using this method you must pass a value for a long name.
   * "" is an acceptable value if you do not want to assign a long name
   *
   * std::tuple<optionShort (std::string), optionLong (std::string)
   * optionArgsCount(optionArguments)>
   */
  bool addOptions(std::vector<option> options);
};

class programArgs {
private:
  int argCount;
  char **argVector;

  // returns the number of args parsed to argc
  int getCount() { return argCount; };

  // returns argv as a vector<string> instead of char**
  std::vector<std::string> getArguments() {
    std::vector<std::string> result = {};

    for (int i : std::views::iota(0, this->getCount())) {
      result.emplace_back(this->argVector[i]);
    }

    return result;
  }

  /*
   * optionArgs:
   * case 1: no optionArgs - parse arg and ignore
   * case 2: single optionArg - parse option and optionArg
   * case 3: multi optionArg - parse option, parse optionArg until
   *   (1) another option begins with '-'
   *   (2) optionArg delimiter '--' is reached. here flag that
   *       there are no more options and parse the operands.
   */
  void parseArguments() {

    std::vector<std::string> args = this->getArguments();

    for (int i = 0; i < args.size(); i++) {
      std::string entry = args[i];

      // check to make sure entry is not empty
      if (entry.empty())
        continue;
    }
  }

public:
  // Constructors etc...
  programArgs(int argc, char **argv);
};
