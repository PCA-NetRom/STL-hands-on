#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    ifstream inFile("HandsOn-Input.txt");

    int no_problems, no_doctors;
    string name, speciality;
    
    inFile >> no_problems;

    for (int i = 0; i < no_problems; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
    }

    inFile >> no_doctors;

    for (int i = 0; i < no_doctors; i++)
    {
        inFile >> name;
        inFile >> speciality;
        cout << name << ' ' << speciality << '\n';
    }

    return 0;
}