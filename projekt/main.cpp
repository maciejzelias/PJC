#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>
#include "Flags.hpp"
#include <map>
#include "operations.hpp"
#include "correctnessofarguments.hpp"


int main(int args_count, const char *args[]) {

    std::ifstream file;
    bool outputfile = false;
    bool isflagL = false;
    bool correctpath = false;
    std::ofstream output;
    auto arguments = std::vector<std::string>(args + 1, args + args_count);
    auto Flags = std::map<std::string, flags>();
    Flags["--help"] = flags::help;
    Flags["-f"] = flags::file;
    Flags["--file"] = flags::file;
    Flags["-n"] = flags::newlines;
    Flags["--newlines"] = flags::newlines;
    Flags["-d"] = flags::digits;
    Flags["--digits"] = flags::digits;
    Flags["-dd"] = flags::numbers;
    Flags["--numbers"] = flags::numbers;
    Flags["-fw"] = flags::find_words;
    Flags["--find-words"] = flags::find_words;
    Flags["-c"] = flags::chars;
    Flags["--chars"] = flags::chars;
    Flags["-w"] = flags::words;
    Flags["-words"] = flags::words;
    Flags["-s"] = flags::sorted;
    Flags["--sorted"] = flags::sorted;
    Flags["-rs"] = flags::reverse_sorted;
    Flags["--reverse-sorted"] = flags::reverse_sorted;
    Flags["-l"] = flags::by_length;
    Flags["--by-lenth"] = flags::by_length;
    Flags["-a"] = flags::anagrams;
    Flags["--anagrams"] = flags::anagrams;
    Flags["-o"] = flags::output;
    Flags["--output"] = flags::output;
    Flags["-p"] = flags::palindromes;
    Flags["--palindromes"] = flags::palindromes;
    Flags["-i"] = flags::input;
    Flags["--input"] = flags::input;

    CheckIfAllFlagsAreValid(arguments, Flags);
    if (arguments.empty() || arguments[0] == "--help") {
        HelpFlag();
    } else {
        if (arguments[0] == "-i" || arguments[0] == "--input") {
            checkFile(arguments[1]);
            if (args_count > 3) {
                std::cout
                        << "Podano za duzo flag/argumentow, po fladze -o/--output nalezy podac jedynie sciezke"
                           "do pliku\n";
                exit(0);
            }
            file = std::ifstream(arguments[1]);
            arguments = ChangeArguments(file);
            CheckIfAllFlagsAreValid(arguments, Flags);
            if (arguments.empty() || arguments[0] == "--help") {
                HelpFlag();
            }
        }
        //checking corectnessofarguments
        for (int i = 0; i < args_count - 1; i++) {
            flags actualFlag;
            if (isFlag(arguments[i], Flags)) {
                actualFlag = FindFlag(arguments[i], Flags);
            } else {
                std::cout << "jedno z podanych argumentow nie jest flaga lub jej argumentem\n";
                exit(0);
            }
            switch (actualFlag) {
                case flags::file:
                    checkFile(arguments[i + 1]);
                    correctpath = true;
                    i++;
                    break;
                case flags::newlines:
                case flags::digits:
                case flags::numbers:
                    noFileChecker(correctpath);
                    break;
                case flags::find_words:
                    noFileChecker(correctpath);
                    CheckNextArgumentFindWords(arguments[i + 1]);
                    i++;
                    break;
                case flags::chars:
                case flags::words:
                case flags::sorted:
                case flags::reverse_sorted:
                    noFileChecker(correctpath);
                    break;
                case flags::by_length:
                    noFileChecker(correctpath);
                    if (!isRSorSafter(arguments, i)) {
                        std::cout
                                << "Bledne uzycie flagi -l, musi ona poprzedzac flage -s/--sorted lub -rs/--reverse-sorted\n";
                        exit(0);
                    }
                    break;
                case flags::anagrams:
                case flags::palindromes:
                    noFileChecker(correctpath);
                    if (!noFlagsToTheEnd(arguments, i, Flags)) {
                        std::cout << "Podana flaga -a/--anagram  lub -p/--palindrom musi byc ostatnia podana flaga\n";
                        exit(0);
                    }
                    i = args_count;
                    break;
                case flags::output:
                    checkOutputFile(arguments[i + 1]);
                    outputfile = true;
                    output = std::ofstream(arguments[i + 1]);
                    i++;
                    break;
            }
        }
        //running program

        for (int i = 0; i < arguments.size(); i++) {
            auto runningflag = FindFlag(arguments[i], Flags);

            switch (runningflag) {
                case flags::file:
                    file = std::ifstream(arguments[i + 1]);
                    i++;
                    break;
                case flags::newlines:
                    if (outputfile) {
                        HowManyLinesInFile(file, output);
                    } else {
                        HowManyLinesInFile(file);
                    }
                    break;
                case flags::digits:
                    if (outputfile) {
                        HowManyDigitsInFile(file, output);
                    } else {
                        HowManyDigitsInFile(file);
                    }
                    break;
                case flags::numbers:
                    if (outputfile) {
                        HowManyRealNumbersInFile(file, output);
                    } else {
                        HowManyRealNumbersInFile(file);
                    }
                    break;
                case flags::find_words:
                    if (outputfile) {
                        AllWordsBegginingWithNextArg(file, arguments[i + 1], output);
                    } else {
                        AllWordsBegginingWithNextArg(file, arguments[i + 1]);
                    }
                    i++;
                    break;
                case flags::chars:
                    if (outputfile) {
                        HowManyCharsInFile(file, output);
                    } else {
                        HowManyCharsInFile(file);
                    }
                    break;
                case flags::words:
                    if (outputfile) {
                        HowManyWordsInFile(file, output);
                    } else {
                        HowManyWordsInFile(file);
                    }
                    break;
                case flags::sorted:
                    if (outputfile) {
                        if (isflagL) {
                            AllWordsFromFileSorting(file, ByLength, output);
                            isflagL = false;
                        } else {
                            AllWordsFromFileSorting(file, Alphabetically, output);
                        }
                    } else {
                        if (isflagL) {
                            AllWordsFromFileSorting(file, ByLength);
                            isflagL = false;
                        } else {
                            AllWordsFromFileSorting(file, Alphabetically);
                        }
                    }
                    break;
                case flags::reverse_sorted:
                    if (outputfile) {
                        if (isflagL) {
                            AllWordsFromFileSorting(file, ReverseByLength, output);
                            isflagL = false;
                        } else {
                            AllWordsFromFileSorting(file, ReverseAlphabetically, output);
                        }
                    } else {
                        if (isflagL) {
                            AllWordsFromFileSorting(file, ReverseByLength);
                            isflagL = false;
                        } else {
                            AllWordsFromFileSorting(file, ReverseAlphabetically);
                        }
                    }
                    break;
                case flags::by_length:
                    isflagL = true;
                    break;
                case flags::anagrams:
                    if (outputfile) {
                        CheckingAnagrams(file, AnagramPalindromHelp(arguments, i), output);
                    } else {
                        CheckingAnagrams(file, AnagramPalindromHelp(arguments, i));
                    }
                    break;
                case flags::palindromes:
                    if (outputfile) {
                        CheckingPalindroms(file, AnagramPalindromHelp(arguments, i), output);
                    } else {
                        CheckingPalindroms(file, AnagramPalindromHelp(arguments, i));
                    }
                    break;
                case flags::output:
                    i++;
                    break;
            }
        }
    }
    return 0;
}

