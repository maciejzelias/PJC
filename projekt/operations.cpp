//
// Created by macie on 11.06.2021.
#include "operations.hpp"
#include <algorithm>
#include <iostream>
#include <set>


/*! \fn
 * Function for flag --newlines, counting number of lines in file
 * and displaying result on console
 *
 * @param path - Path to source file
 */
void HowManyLinesInFile(std::ifstream &path) {
    auto count = 0;
    for (auto line = std::string(); std::getline(path, line);) {
        count++;
    }
    std::cout << "lines in file : " << count << " \n";
    path.clear();
    path.seekg(0, std::ios::beg);
}     // -n

/*! \fn
 * Function for flag -n , counting number of lines in file
 * and sending result to output file
 *
 * @param path - Path to source file
 * @param output - Path to output file
 */
void HowManyLinesInFile(std::ifstream &path, std::ofstream &output) {
    auto count = 0;
    for (auto line = std::string(); std::getline(path, line);) {
        count++;
    }
    output << "lines in file : " << count << " \n";
    path.clear();
    path.seekg(0, std::ios::beg);
}


/*! \fn
 * Function for flag --digits, counting number of digits in file
 * and displaying result on console
 *
 * @param path - Path to source file
 */
void HowManyDigitsInFile(std::ifstream &path) {
    auto count = 0;
    for (auto word = std::string(); path >> word;) {
        count += std::count_if(word.begin(), word.end(), [](char a) {
            return std::isdigit(a);
        });
    }
    std::cout << "digits in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}     // -d

/*! \fn
 * Function for flag --digits, counting number of digits in file
 * and sending result to output file
 *
 * @param path - Path to source file
 */
void HowManyDigitsInFile(std::ifstream &path, std::ofstream &output) {
    auto count = 0;
    for (auto word = std::string(); path >> word;) {
        count += std::count_if(word.begin(), word.end(), [](char a) {
            return std::isdigit(a);
        });
    }
    output << "digits in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}


/*! \fn
 * Function for flag --numbers, counting number of real numbers in file
 * and displaying result on console
 * @param path - Path to source file
 */
void HowManyRealNumbersInFile(std::ifstream &path) {
    auto count = 0;
    int help;
    for (auto word = std::string(); path >> word;) {
        help = std::count_if(word.begin(), word.end(), [](char a) {
                                 if (a == '.' || a == ',' || std::isdigit(a)) {
                                     return true;
                                 } else {
                                     return false;
                                 }
                             }
        );
        if (help == word.size()) {
            count++;
        }
    }
    std::cout << "real numbers in file : " << count << " \n";
    path.clear();
    path.seekg(0, std::ios::beg);
}    // -dd

/*! \fn
 * Function for flag --numbers, counting number of real numbers in file
 * and sending result to output file
 *
 * @param path - Path to source file
 */
void HowManyRealNumbersInFile(std::ifstream &path, std::ofstream &output) {
    auto count = 0;
    int help;
    for (auto word = std::string(); path >> word;) {
        help = std::count_if(word.begin(), word.end(), [](char a) {
                                 if (a == '.' || a == ',' || std::isdigit(a)) {
                                     return true;
                                 } else {
                                     return false;
                                 }
                             }
        );
        if (help == word.size()) {
            count++;
        }
    }
    output << "real numbers in file : " << count << " \n";
    path.clear();
    path.seekg(0, std::ios::beg);
}


/*! \fn
 * Function for flag --find-word, displaying all arguments from file
 * that starts with next argument given
 *
 * @param path - Path to source file
 * @param arg - next argument given
 */
void AllWordsBegginingWithNextArg(std::ifstream &path, const std::string arg) {
    std::cout << "Words from file that beign with argument " << arg << " : ";
    for (auto word = std::string(); path >> word;) {
        if (word[0] == arg[0]) {
            std::cout << word << " ";
        }
    }
    std::cout << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}     //-fw

/*! \fn
 * Function for flag --find-word, sending all arguments from file
 * that starts with next argument given to output file
 *
 * @param path - Path to source file
 * @param arg - next argument given
 * @param output - Path to output file
 */
void AllWordsBegginingWithNextArg(std::ifstream &path, const std::string arg, std::ofstream &output) {
    output << "Words from file that beign with argument " << arg << " : ";
    for (auto word = std::string(); path >> word;) {
        if (word[0] == arg[0]) {
            output << word << " ";
        }
    }
    output << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}


/*! \fn
 * Function for flag --chars , counting number of chars in file
 * and display result in console
 *
 * @param path - Path to source file
 */
void HowManyCharsInFile(std::ifstream &path) {
    auto count = 0;
    for (auto line = std::string(); std::getline(path, line);) {
        count += line.size();
    }
    std::cout << "chars in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}   // -c

/*! \fn
 * Function for flag --chars , counting number of chars in file
 * and send result to output file
 *
 * @param path - Path to source file
 * @param output - Path to output file
 */
void HowManyCharsInFile(std::ifstream &path, std::ofstream &output) {
    auto count = 0;
    for (auto line = std::string(); std::getline(path, line);) {
        count += line.size();
    }
    output << "chars in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}


/*!\fn
 * Function for flag --words , counting number of words in source file
 * and displaying result in console
 *
 * @param path - Path to source file
 */
void HowManyWordsInFile(std::ifstream &path) {
    auto count = 0;
    for (auto word = std::string(); path >> word;) {
        count++;
    }
    std::cout << "words in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}  //-w

/*!\fn
 * Function for flag --words , counting number of words in source file
 * and sending result to output file
 *
 * @param path - Path to source file
 * @param output - Path to output file
 */
void HowManyWordsInFile(std::ifstream &path, std::ofstream &output) {
    auto count = 0;
    for (auto word = std::string(); path >> word;) {
        count++;
    }
    output << "words in file : " << count << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}

/*!\fn
 * Function for flag --sorted / --reverse-sorted , sorting arguments from source file
 * Alphabetically / Reverse-Alphabetically / By_length or Reverse-By_length and displaying
 * them on console
 *
 * @param path - path to source file
 * @param Sorting - sort method
 */
void AllWordsFromFileSorting(std::ifstream &path, HowToSort Sorting) {
    auto words = std::vector<std::string>();
    for (auto word = std::string(); path >> word;) {
        words.push_back(word);
    }
    if (Sorting == Alphabetically) {
        std::sort(words.begin(), words.end());
        std::cout << "All words alphabetically : ";
    } else if (Sorting == ReverseAlphabetically) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a > b;
        });
        std::cout << "All words reverse-alphabetically : ";
    } else if (Sorting == ByLength) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a.length() > b.length();
        });
        std::cout << "All words sorted by_length: ";
    } else if (Sorting == ReverseByLength) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a.length() < b.length();
        });
        std::cout << "All words sorted by_length-reverse: ";
    }
    for (const auto &i : words) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}  // -l -s -rs

/*!\fn
 * Function for flag --sorted / --reverse-sorted , sorting arguments from source file
 * Alphabetically / Reverse-Alphabetically / By_length or Reverse-By_length sending them
 * to output file
 *
 * @param path - path to source file
 * @param Sorting - sort method
 * @param output  - path to output file
 */
void AllWordsFromFileSorting(std::ifstream &path, HowToSort Sorting, std::ofstream &output) {
    auto words = std::vector<std::string>();
    for (auto word = std::string(); path >> word;) {
        words.push_back(word);
    }
    if (Sorting == Alphabetically) {
        std::sort(words.begin(), words.end());
        output << "All words alphabetically : ";
    } else if (Sorting == ReverseAlphabetically) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a > b;
        });
        output << "All words reverse-alphabetically : ";
    } else if (Sorting == ByLength) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a.length() > b.length();
        });
        output << "All words sorted by_length: ";
    } else if (Sorting == ReverseByLength) {
        std::sort(words.begin(), words.end(), [](const std::string &a, const std::string &b) {
            return a.length() < b.length();
        });
        output << "All words sorted by_length-reverse: ";
    }
    for (const auto &i : words) {
        output << i << " ";
    }
    output << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}

/*!\fn
 * Auxiliary function for checking anagrams and palindroms,
 * modifying given vector, deleting arguments before given index
 *
 * @param vec - vector to modify
 * @param index - index where deleting arguments should be stopped
 * @return vector with deleted arguments before given index
 */
std::vector<std::string> AnagramPalindromHelp(std::vector<std::string> vec, const int index) {
    vec.erase(vec.begin(), vec.begin() + index + 1);
    return vec;
}

/*!\fn
 * Function for Flag --anagrams, matches anagrams from given vector
 * and path and display them on console
 * @param path - path to source file
 * @param vec - vector with arguments to match
 */
void CheckingAnagrams(std::ifstream &path, std::vector<std::string> vec) {
    auto vec_with_anagrams = std::set<std::string>();
    for (auto word = std::string(); path >> word;) {
        std::sort(word.begin(), word.end());
        std::copy_if(vec.begin(), vec.end(), std::inserter(vec_with_anagrams, vec_with_anagrams.begin()),
                     [word](std::string str) {
                         std::sort(str.begin(), str.end());
                         return word == str;
                     });
    }
    std::cout << "matched anagrams in file : ";
    for (const auto &i : vec_with_anagrams) {
        std::cout << i << " ";
    }
    std::cout << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}   // -a
/*!\fn
 * Function for Flag --anagrams, matches anagrams from given vector
 * and path and send them to output file
 *
 * @param path - path to source file
 * @param vec - vector with arguments to match
 * @param output - path to output file
 */
void CheckingAnagrams(std::ifstream &path, std::vector<std::string> vec, std::ofstream &output) {
    auto vec_with_anagrams = std::set<std::string>();
    for (auto word = std::string(); path >> word;) {
        std::sort(word.begin(), word.end());
        std::copy_if(vec.begin(), vec.end(), std::inserter(vec_with_anagrams, vec_with_anagrams.begin()),
                     [word](std::string str) {
                         std::sort(str.begin(), str.end());
                         return word == str;
                     });
    }
    output << "matched anagrams in file : ";
    for (const auto &i : vec_with_anagrams) {
        output << i << " ";
    }
    output << "\n";
    path.clear();
    path.seekg(0, std::ios::beg);
}

/*!\fn
 *  Function for flag --palindromes , matches palindroms from vector
 *  to arguments in file and display them on console
 * @param path -  path to source file
 * @param vec - vector with arguments to check and match
 */
void CheckingPalindroms(std::ifstream &path, std::vector<std::string> vec) {
    auto vec_with_palindroms = std::set<std::string>();
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](std::string str) {
        auto str2 = str;
        std::reverse(str.begin(), str.end());
        if (str != str2) {
            return true;
        } else {
            return false;
        }
    }), vec.end());

    for (auto word = std::string(); path >> word;) {
        auto find = std::find(vec.begin(), vec.end(), word);
        if (find != std::end(vec)) {
            vec_with_palindroms.insert(word);
        }
    }
    std::cout << "palindromes in file : ";
    for (const auto &i : vec_with_palindroms) {
        std::cout << i << " ";
    }
    path.clear();
    path.seekg(0, std::ios::beg);
} // -p

/*!\fn
 *  Function for flag --palindromes , matches palindroms from vector
 *  to arguments in file and sends them to output file
 *
 * @param path - path to source file
 * @param vec - vector with arguments to check and match
 * @param output - path to output file
 */
void CheckingPalindroms(std::ifstream &path, std::vector<std::string> vec, std::ofstream &output) {
    auto vec_with_palindroms = std::set<std::string>();
    vec.erase(std::remove_if(vec.begin(), vec.end(), [](std::string str) {
        auto str2 = str;
        std::reverse(str.begin(), str.end());
        if (str != str2) {
            return true;
        } else {
            return false;
        }
    }), vec.end());

    for (auto word = std::string(); path >> word;) {
        auto find = std::find(vec.begin(), vec.end(), word);
        if (find != std::end(vec)) {
            vec_with_palindroms.insert(word);
        }
    }
    output << "palindromes in file : ";
    for (const auto &i : vec_with_palindroms) {
        output << i << " ";
    }
    path.clear();
    path.seekg(0, std::ios::beg);
}

/*!\fn
 * Auxiliary function for flag --input, gets a path to source file
 * and returns container with all arguments
 * @param path - path to source file
 * @return container with all arguments from source file
 */
std::vector<std::string> ChangeArguments(std::ifstream &path) {
    auto vec = std::vector<std::string>();
    for (auto word = std::string(); path >> word;) {
        vec.push_back(word);
    }
    return vec;
}

//

