#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>
#include <vector>

using namespace std;

struct Problem
{
    string name;
    int position, difficulty;
};

bool difficultyGreaterOrEqualToFive(const Problem& problem)
{
    return problem.difficulty >= 5;
}

bool difficultyGreaterOrEqualToEight(const Problem& problem)
{
    return problem.difficulty >= 8;
}

void addProblems(vector<Problem>& problems)
{
    problems.push_back({"Problem1", 1, 7});
    problems.push_back({"Problem2", 2, 5});
    problems.push_back({"Problem3", 3, 4});
    problems.push_back({"Problem4", 4, 8});
    problems.push_back({"Problem5", 5, 4});
    problems.push_back({"Problem6", 6, 5});
    problems.push_back({"Problem7", 7, 3});
    problems.push_back({"Problem8", 8, 8});
}

void demo1()
{
    vector <int> v(2, 5);
    
    v.push_back(7);
    v.push_back(5);
    v.push_back(10);
    
    for (int i = 0; i < v.size(); i++)
        cout << v[i] << ' ';
    
    cout << "\nVector size: " << v.size() << '\n' << "Vector capacity: " << v.capacity() << '\n';
}

void demo2()
{
    filesystem::path filePath = "volunteersList.txt";

    if (!filesystem::exists(filePath))
    {
        cerr << "File does not exist." << endl;
        return;
    }

    ifstream inputFile(filePath);

    if (!inputFile)
    {
        cerr << "Failed to open the file." << endl;
        return;
    }

    vector<pair<int, string>> youngVolunteers;
    int age;
    string name;
    
    while (inputFile >> name && inputFile >> age)
    {
        if (age >= 40)
            break;

        youngVolunteers.emplace_back(age, name);
    }
    
    for (vector<pair<int, string>>::iterator i = youngVolunteers.begin(); i != youngVolunteers.end(); i++)
        cout << i->first << ' ' << i->second << '\n';

    return;
}

void demo3()
{
    vector<Problem> problems;
    
    addProblems(problems);
    
    int counter = count_if(problems.begin(), problems.end(), difficultyGreaterOrEqualToFive);
    cout << "Total problems with difficulty >= 5: " << counter << '\n';
    
    auto highDifficultyProblem = find_if(problems.begin(), problems.end(), difficultyGreaterOrEqualToEight);
    if (highDifficultyProblem != problems.end())
    {
        problems.erase(remove_if(highDifficultyProblem + 1, problems.end(), difficultyGreaterOrEqualToFive), problems.end());
    }

    counter = count_if(problems.begin(), problems.end(), difficultyGreaterOrEqualToFive);
    cout << "Total problems with difficulty >= 5: " << counter << '\n';

    for (const auto& p : problems) 
        cout << p.name << ": " << p.position << " " << p.difficulty << '\n';
}

int main()
{
    demo1();
    // demo2();
    // demo3();
    return 0;
}