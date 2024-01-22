#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
    ifstream inFile("input.txt");
    int n;

    inFile >> n;

    cout << n;
    
    return 0;
}