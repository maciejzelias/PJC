//
// Created by macie on 11.06.2021.
//

#ifndef PROJEKTPJC_OPERATIONS_HPP
#define PROJEKTPJC_OPERATIONS_HPP

#include <fstream>
#include <vector>

/*!\enum
 * enum class to define method of sorting
 */
enum HowToSort {
    Alphabetically,
    ReverseAlphabetically,
    ByLength,
    ReverseByLength
};


void HowManyLinesInFile(std::ifstream &path);

void HowManyLinesInFile(std::ifstream &path, std::ofstream &output);

void HowManyDigitsInFile(std::ifstream &path);

void HowManyDigitsInFile(std::ifstream &path, std::ofstream &output);

void HowManyRealNumbersInFile(std::ifstream &path);

void HowManyRealNumbersInFile(std::ifstream &path, std::ofstream &output);

void AllWordsBegginingWithNextArg(std::ifstream &path, const std::string arg);

void AllWordsBegginingWithNextArg(std::ifstream &path, const std::string arg, std::ofstream &output);

void HowManyCharsInFile(std::ifstream &path);

void HowManyCharsInFile(std::ifstream &path, std::ofstream &output);

void HowManyWordsInFile(std::ifstream &path);

void HowManyWordsInFile(std::ifstream &path, std::ofstream &output);

void AllWordsFromFileSorting(std::ifstream &path, HowToSort Sorting);

void AllWordsFromFileSorting(std::ifstream &path, HowToSort Sorting, std::ofstream &output);

std::vector<std::string> AnagramPalindromHelp(const std::vector<std::string> vec, const int index);

void CheckingAnagrams(std::ifstream &path, std::vector<std::string> vec);

void CheckingAnagrams(std::ifstream &path, std::vector<std::string> vec, std::ofstream &output);

void CheckingPalindroms(std::ifstream &path, std::vector<std::string> vec);

void CheckingPalindroms(std::ifstream &path, std::vector<std::string> vec, std::ofstream &output);

std::vector<std::string> ChangeArguments (std::ifstream &path);

#endif //PROJEKTPJC_OPERATIONS_HPP
