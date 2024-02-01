#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include <map>

using namespace std;

struct Problem {
    string name;
    string speciality;
    int priority;
    int duration;

    bool operator <(const Problem& other) const {
        if (priority != other.priority) {
            return (priority < other.priority);
        }
        return (duration > other.duration);
    }
};

struct Doctor {
    string id;
    string speciality;
    int usedHours;
    vector<Problem> usedProblems;
};

Problem currentProblem;

int main() {
    ifstream inFile("HandsOn-Input.txt");

    int n, m;
    inFile >> n;

    vector<Problem> problems(n);
    priority_queue<Problem> pq;
    for (Problem& p : problems) {
        inFile >> p.name >> p.speciality >> p.duration >> p.priority;
        pq.push(p);
    }

    inFile >> m;
    vector<Doctor> doctors(m);
    for (Doctor& d : doctors) {
        inFile >> d.id >> d.speciality;
        d.usedHours = 0;
    }

	while (!pq.empty()) {

		auto current = pq.top();
		pq.pop();
		auto foundDoctor = find_if(doctors.begin(), doctors.end(), [=](Doctor d) {
			if (d.usedHours + current.duration <= 8 && d.speciality == current.speciality) {
				return true;
			}
			return false;
			});

		if (foundDoctor != doctors.end()) {
			foundDoctor->usedHours += current.duration;
			foundDoctor->usedProblems.push_back(current);
		}
	}

    for (auto it : doctors) {
        if (it.usedProblems.size() > 0) {
            cout << it.id << " " << it.usedProblems.size() << " ";
            for (auto it2 : it.usedProblems) {
                cout << it2.name << " ";
            }
            cout << "\n";
        }
    }

    inFile.close();

    return 0;
}