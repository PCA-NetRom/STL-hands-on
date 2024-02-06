#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include <map>

static const int k_hospitalOpenTime = 9;
static const int k_hospitalCloseTime = 17;

struct Problem 
{
    std::string name;
    std::string speciality;
    int priority;
    int duration;

    bool operator< (const Problem& other) const 
    {
        if (priority != other.priority) 
            return (priority < other.priority);

        return (duration > other.duration);
    }
};

struct Doctor 
{
    std::string id;
    std::string speciality;
    int availableFromHour;
    std::vector<Problem> solvedProblems;
};

int main() 
{
    // Read input
    std::ifstream inFile("inputSTL2.txt");

    int numProblems, numDoctors;
    inFile >> numProblems;

    std::vector<Problem> problems(numProblems);
    std::priority_queue<Problem> problemsQueue;
    for (Problem& problem : problems) 
    {
        inFile >> problem.name >> problem.speciality >> problem.duration >> problem.priority;
        problemsQueue.push(problem);
    }

    inFile >> numDoctors;
    std::vector<Doctor> doctors(numDoctors);
    for (Doctor& doctor : doctors) 
    {
        inFile >> doctor.id >> doctor.speciality;
        doctor.availableFromHour = k_hospitalOpenTime;
    }

    inFile.close();

    // Solve
	while (!problemsQueue.empty()) 
    {
		Problem currentProblem = problemsQueue.top();
		problemsQueue.pop();
		std::vector<Doctor>::iterator foundDoctor = find_if(doctors.begin(), doctors.end(), [=](const Doctor& doctor) 
        {
            if (doctor.availableFromHour + currentProblem.duration <= k_hospitalCloseTime
                && doctor.speciality == currentProblem.speciality)
            {
                return true;
            }

			return false;
		});

		if (foundDoctor != doctors.end()) 
        {
			foundDoctor->availableFromHour += currentProblem.duration;
			foundDoctor->solvedProblems.push_back(currentProblem);
		}
	}

    // Print output
    for (const Doctor& doctor : doctors) 
    {
        if (doctor.solvedProblems.size() > 0) 
        {
            std::cout << doctor.id << " " << doctor.solvedProblems.size() << " ";
            for (const Problem& problem : doctor.solvedProblems) 
                std::cout << problem.name << " ";

            std::cout << std::endl;
        }
    }

    return 0;
}