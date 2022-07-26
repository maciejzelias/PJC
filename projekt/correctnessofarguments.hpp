//
// Created by macie on 11.06.2021.
//

#ifndef PROJEKTPJC_CORRECTNESSOFARGUMENTS_HPP
#define PROJEKTPJC_CORRECTNESSOFARGUMENTS_HPP

#include "Flags.hpp"
#include <map>

void checkFile(const std::string path);

void checkOutputFile(const std::string path);

void HelpFlag();

void CheckNextArgumentFindWords(const std::string argument);

bool isFlag(const std::string potencialFlag, const std::map<std::string, flags> flags);

flags FindFlag(const std::string matchingFlag, const std::map<std::string, flags> flags);

bool
noFlagsToTheEnd(const std::vector<std::string> potencialFlags, int index, const std::map<std::string, flags> flags);

void noFileChecker(const bool path);

bool isRSorSafter(std::vector<std::string> args, int index);

void CheckIfAllFlagsAreValid(const std::vector<std::string> arguments, const std::map<std::string, flags> flags);

#endif //PROJEKTPJC_CORRECTNESSOFARGUMENTS_HPP
