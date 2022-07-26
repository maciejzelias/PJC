//
// Created by macie on 11.06.2021.
#include <iostream>
#include <fstream>
#include <vector>
#include "correctnessofarguments.hpp"
#include <map>


/*!\fn
 * Auxiliary function for check corectness of arguments,
 * Check if file path is correct
 * if not stops program and give suitable message
 * @param path - path to source file
 * */
void checkFile(const std::string path) {
    auto file = std::ifstream(path);
    if (!file.good()) {
        std::cout << "niepoprawna sciezka po fladze -f/--file lub -i/--input\n";
        exit(0);
    }
}

/*!\fn
 * Auxiliary function for check corectness of arguments,
 * Check if output file path is correct
 * if not stops program and give suitable message
 * @param path - path to output file
 * */
void checkOutputFile(const std::string path) {
    auto file = std::ofstream(path);
    if (!file.good()) {
        std::cout << "niepoprawna sciezka po fladze -o/--output\n";
        exit(0);
    }
}

/*!\fn
 * Auxiliary function for check corectness of arguments,
 * ready to use in case of flag --help
 * shows instruction how to use a program and what are the flags
 * */
void HelpFlag() {
    std::cout << "Welcome \n"
                 "to PJAText2 !" << std::endl;
    std::cout << "this program can help you with a lot of operations on your file.txt\n";
    std::cout << "There are allowed operations : \n"
                 "*nothing*/--help  = shows menu\n"
                 "-f/--file = next argument should be path to your file\n"
                 "-n/--newlines = this flag shows count of your lines in file\n"
                 "-fw/--find-word = will find and show all words that begin with next argument\n"
                 "-d/--digits = this flag shows number of digits in file\n"
                 "-dd/--numbers = this flag shows count of real numbers in file (int,float,double)\n"
                 "-c/--chars = this flag shows number of chars in file\n"
                 "-w/--words = this flag shows number of strings in file\n"
                 "-s/--sorted = this flag shows all strings from file alphabetically\n"
                 "-rs/--reverse-sorted = this flag shows all string from file reverse-alphabetically\n"
                 "-l/--by-length = this flag changes action of two above flags to sort it by length\n"
                 "-a/--anagrams = this flag will find anagrams of next arguments in file\n"
                 "-p/--palindroms = this flag will check if next arguments are palindroms and find those in file\n"
                 "-o/--output = this flag will show all results of program in next-argument file\n"
                 "-i/--input = this flag will allow you to give argument flags in file\n";
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * checks if argument is only 1-char word
 * @param argument
 */
void CheckNextArgumentFindWords(const std::string argument) {
    if (argument.size() != 1) {
        std::cout << "podales argument składający się z wiecej niz jednego znaku po fladze -fw\n";
        exit(0);
    }
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * Checks if given string is a flag by comapring it to arguments in
 * map with valid flags
 *
 * @param potencialFlag - string with potencial flag
 * @param flags - map with valid flags
 *
 * @return true if potencialFlag is flag and false if it is not
 */
bool isFlag(const std::string potencialFlag, const std::map<std::string, flags> flags) {
    for (const auto &flag : flags) {
        if (potencialFlag == flag.first) {
            return true;
        }
    }
    return false;
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * Finds a flag that matches given string in map with valid flags
 * and returns flag in type enum
 *
 * @param matchingFlag - flag in string
 * @param flags - map with valid flags
 * @return enum flag that matched given string
 */
flags FindFlag(const std::string matchingFlag, const std::map<std::string, flags> flags) {
    for (const auto &arg : flags) {
        if (arg.first == matchingFlag) {
            return arg.second;
        }
    }
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * checks if there are no flags to the end of given vector,
 * starting from given index
 *
 * @param potencialFlags - vector with arguments
 * @param index - index to start checking
 * @param flags - map of valid flags to compare
 * @return true if there was an flag in that section of vector, false if not
 */
bool
noFlagsToTheEnd(const std::vector<std::string> potencialFlags, int index, const std::map<std::string, flags> flags) {
    for (int i = index + 1; i < potencialFlags.size(); i++) {
        if (isFlag(potencialFlags[i], flags)) {
            return false;
        }
    }
    return true;
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * if given bool is false stops program and give suitable message
 *
 * @param path - bool that says if there was path given or not
 */
void noFileChecker(const bool path) {
    if (!path) {
        std::cout << "brak podanej sciezki do pliku ( wpisz na poczatku -f/--file /sciezkadopliku/\n";
        exit(0);
    }
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * Checks if there is -rs or -s flag in given vector
 * starting from given index to the end of a vector
 * @param args - given vector with arguments
 * @param index - index to start checking
 * @return true if there was -rs or -s in that section of vector, false if not
 */
bool isRSorSafter(std::vector<std::string> args, int index) {
    for (int i = index + 1; i < args.size(); i++) {
        if (args[i] == "-s" || args[i] == "--sorted" || args[i] == "-rs" || args[i] == "--reverse-sorted") {
            return true;
        }
    }
    return false;
}

/*!\fn
 * Auxiliary function to check corectness of arguments,
 * Checking if all flags from given vector are valid,
 * by comparing them to map of flags.
 *
 * @param arguments - vector of arguments to check
 * @param flags - map of valid flags
 */
void CheckIfAllFlagsAreValid(const std::vector<std::string> arguments, const std::map<std::string, flags> flags) {
    bool validflag;
    for (const auto &argument : arguments) {
        if (argument[0] == '-' || (argument[0] == '-' && argument[1] == '-')) {
            validflag = false;
            for (const auto &flag : flags) {
                if (argument == flag.first) {
                    validflag = true;
                }
            }
            if (!validflag) {
                std::cout << " one of flags is not valid , type --help to check all valid flags\n";
                exit(0);
            }
        }
    }
}
//

