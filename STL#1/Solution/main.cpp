#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct Problem {
    string name;
    string speciality;
};

struct Doctor {
    string id;
    string speciality;
};

Problem currentProblem;

bool matchesSpeciality(const Doctor &doctor) {
    return doctor.speciality == currentProblem.speciality;
}

int main() {
    ifstream inFile("HandsOn-Input.txt");
    
    int n, m;
    inFile >> n;
    
    vector<Problem> problems(n);
    for (Problem &p : problems) {
        inFile >> p.name >> p.speciality;
    }

    inFile >> m;
    vector<Doctor> doctors(m);
    for (Doctor &d : doctors) {
        inFile >> d.id >> d.speciality;
    }

    for (const Problem &p : problems) {
        currentProblem = p;
        auto it = find_if(doctors.begin(), doctors.end(), matchesSpeciality);

        if (it != doctors.end()) {
            cout << it->id << " " << p.name << endl;
            doctors.erase(it);
        }
    }

    inFile.close();
    
    return 0;
}