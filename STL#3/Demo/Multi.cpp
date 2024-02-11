#include "Multi.h"

#include <iostream>
#include <set>
#include <map>

void print(std::multiset<int>& numbers)
{
    for (const int& element : numbers)
        std::cout << element << " ";
    std::cout << std::endl;
}

void print(std::multimap<std::string, int>& myMap)
{
    for (const std::pair<std::string, int>& entry : myMap)              // Entries are std::pairs
        std::cout << entry.first << ": " << entry.second << std::endl;
    std::cout << std::endl;
}

void multiSet()
{
    std::multiset<int> numbers = { 1, 4, 2, 2, 5, 3, 1 };

    std::cout << "MultiSet contents:" << std::endl;
    print(numbers);
}

void multiMap()
{
    // Creation
    std::multimap<std::string, int> studentGrades = { { "John", 10 }, { "John", 9 }, { "Mathew", 7 }, { "Kate", 8 }, { "Gigel", 10 } };
    studentGrades.insert({ "John", 11 });

    std::cout << "MultiMap contents:" << std::endl;
    print(studentGrades);

    // Count
    std::cout << "John has " << studentGrades.count("John") << " grades" << std::endl;

    // Equal range
    std::cout << "John's grades: ";
    auto range = studentGrades.equal_range("John");
    for (auto it = range.first; it != range.second; ++it)
        std::cout << it->second << " ";
    std::cout << std::endl;
}

void multiMain()
{
    multiSet();

    //multiMap();
}