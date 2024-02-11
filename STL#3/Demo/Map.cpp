#include "Map.h"

#include <iostream>
#include <map>
#include <string>

struct Student
{
    std::string name;
    int age;
    std::string series;

    // This must be implemented to be able to use Student with Map
    bool operator<(const Student& other) const
    {
        return name < other.name;
    }
};

void print(std::map<std::string, int>& myMap)
{
    for (const std::pair<std::string, int>& entry : myMap)              // Entries are std::pairs
        std::cout << entry.first << ": " << entry.second << std::endl;
    std::cout << std::endl;
}

void basic()
{
    // Creation
    std::map<std::string, int> studentGrades = { { "John", 9 },{ "Mathew", 7 },{ "Kate", 8 },{ "Gigel", 10 } };

    std::cout << "Map contents:" << std::endl;
    print(studentGrades);                                   // Keys are printed in ascending order

    // Insertion
    studentGrades.insert({ "Leonardo", 11 });

    std::cout << "Map contents after insertion:" << std::endl;
    print(studentGrades);                                   // Keys are printed in ascending order

    // Access
    std::cout << "Kate's grade is: " << studentGrades["Kate"] << std::endl;

    std::cout << "Unknown's grade is: " << studentGrades["Unknown"] << std::endl;

    print(studentGrades);                                   // "Unknown" was added to the map with a default grade

    // Search
    bool found = studentGrades.contains("Gigel");
    bool found2 = studentGrades.contains("Unknown2");       // Use contains() before accessing with []
}

void custom()
{
    std::map<Student, int> studentGrades;
    Student student1 = { "John", 19, "A"};
    studentGrades[student1] = 8;
    Student student2 = { "Kate", 20, "B" };
    studentGrades[student2] = 9;
    Student student3 = { "Gigel", 18, "D" };
    studentGrades[student3] = 10;
}

void mapMain()
{
    basic();

    //custom();
}
