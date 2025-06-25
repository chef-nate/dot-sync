#include "utils.h"

programArgs::programArgs(int argc, char **argv) {
  this->argCount = argc;
  this->argVector = argv;
}

bool optionManager::addOption(std::string optionShort, std::string optionLong,
                              optionArguments optionArgsCount) {
  if (optionShort.empty()) {
    // invalid argument passed in.
    return false;
  }

  if (this->m_optionsMap.contains(optionShort)) {
    // cannot define two options with the same name (optionShort)
    return false;
  }

  if (!optionLong.empty() && this->m_optionsMap.contains(optionLong)) {
    // cannot define two options with the same name (optionLong)
    return false;
  }

  std::shared_ptr<option> opt(
      new option(optionShort, optionLong, optionArgsCount));

  if (optionLong.empty()) {
    this->m_optionsMap[optionShort] = opt;
  } else {
    this->m_optionsMap[optionShort] = opt;
    this->m_optionsMap[optionLong] = opt;
  }

  return true;
}

bool optionManager::addOption(std::string optionShort,
                              optionArguments optionArgsCount) {
  return this->addOption(optionShort, "", optionArgsCount);
}

bool optionManager::addOption(option option) {
  return this->addOption(option.m_shortName, option.m_longName,
                         option.m_argsAmount);
}

bool optionManager::addOptions(std::vector<option> options) {
  bool anyReturnFalse = false;

  for (auto opt : options) {
    anyReturnFalse |= this->addOption(opt);
  }

  return !anyReturnFalse;
}
