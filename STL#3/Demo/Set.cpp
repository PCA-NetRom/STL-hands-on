#include "Set.h"

#include <iostream>
#include <algorithm>
#include <utility>
#include <set>
#include <vector>
#include "Demo-AssociativeContainers.h"

struct Point
{
    int x;
    int y;

    // This must be implemented to be able to use Point with Set
    bool operator<(const Point& other) const
    {
        if (x < other.x)
            return true;
        else if (x == other.x && y < other.y)
            return true;
        else
            return false;
    }
};

void print(std::set<int>& numbers)
{
    for (const int& element : numbers)
        std::cout << element << " ";
    std::cout << std::endl;
}

void print(std::vector<int>& numbers)
{
    for (const int& element : numbers)
        std::cout << element << " ";
    std::cout << std::endl;
}

void simpleCreation()
{
    // Creation
    std::set<int> numbers = { 1, 4, 2, 2, 5, 3, 1 };

    std::cout << "The initial numbers are:" << std::endl;
    print(numbers);                     // Printed values are unique and sorted ascending

    // Insertion
    numbers.insert(1);                  // Duplicates are ignored
    numbers.insert({ 0, 10, 100 });       // Multiple values insertion

    std::cout << "The numbers after insertion are:" << std::endl;
    print(numbers);

    // Deletion
    numbers.erase(1);
    numbers.erase(2);
    numbers.erase(3);

    std::cout << "The numbers after erase are:" << std::endl;
    print(numbers);
}

void customCreation()
{
    std::set<Point> points = { {0, 0}, {2, 2}, {5, 3}, {1, -1} };       // Needs Point::operator<() implemented

    bool found1 = points.contains({ 2, 2 });
    bool found2 = points.contains({ -1, -1 });
}

void algorithm()
{
    std::set<int> set1 = { 1, 2, 3, 4, 5 };
    std::set<int> set2 = { 3, 4, 5, 6, 7 };

    // Intersection in set
    std::set<int> result;
    std::set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::inserter(result, result.begin()));

    std::cout << "The intersection is:" << std::endl;
    print(result);

    // Intersection in vector
    std::vector<int> resultVec;
    std::set_intersection(set1.begin(), set1.end(),
        set2.begin(), set2.end(),
        std::back_inserter(resultVec));

    std::cout << "The intersection vector is:" << std::endl;
    print(resultVec);
}

void setMain()
{
    simpleCreation();

    //customCreation();

    //algorithm();

    std::getchar();
}

