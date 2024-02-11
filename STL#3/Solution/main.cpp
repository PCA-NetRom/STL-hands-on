#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <queue>
#include <map>
#include <set>

static const int k_hospitalOpenTime = 9;
static const int k_hospitalCloseTime = 17;

struct Problem 
{
    std::string name;
    std::string speciality;
    int arrivalHour;
    int duration;
    int priority;

    bool operator< (const Problem& other) const 
    {
        // Order by arrival hour, then priority, then duration
        if (arrivalHour != other.arrivalHour)
            return (arrivalHour > other.arrivalHour);

        if (priority != other.priority) 
            return (priority < other.priority);

        return (duration > other.duration);
    }
};

struct Doctor 
{
    std::string id;
    std::set<std::string> specialities;

    int availableFromHour;
    std::vector<Problem> solvedProblems;
};

int main() 
{
    // Read input
    std::ifstream inFile("HandsOn-Input.txt");

    int numProblems;
    inFile >> numProblems;

    std::priority_queue<Problem> problemsQueue;
    for (int problemIdx = 0; problemIdx < numProblems; problemIdx++)
    {
        Problem problem;
        inFile >> problem.name >> problem.speciality >> problem.arrivalHour
                >> problem.duration >> problem.priority;
        problemsQueue.push(problem);
    }

    int numDoctors;
    inFile >> numDoctors;

    std::map<std::string, Doctor> doctorsById;
    std::map<std::string, std::set<std::string>> doctorIdsBySpeciality;
    for (int doctorIdx = 0; doctorIdx < numDoctors; doctorIdx++)
    {
        Doctor doctor;
        inFile >> doctor.id;
        
        int numSpecialities;
        inFile >> numSpecialities;

        for (int idx = 0; idx < numSpecialities; idx++)
        {
            std::string speciality;
            inFile >> speciality;
            doctor.specialities.insert(speciality);

            doctorIdsBySpeciality[speciality].insert(doctor.id);
        }

        doctor.availableFromHour = k_hospitalOpenTime;

        doctorsById[doctor.id] = doctor;
    }

    inFile.close();

    // Solve
	while (!problemsQueue.empty()) 
    {
		Problem currentProblem = problemsQueue.top();
		problemsQueue.pop();

        // Find available doctor
        const auto& doctorsIt = doctorIdsBySpeciality.find(currentProblem.speciality);
        if (doctorsIt == doctorIdsBySpeciality.end())
            continue;       // No doctor for this speciality

        const std::set<std::string>& doctorIdsSet = doctorsIt->second;
        for (const std::string& doctorId : doctorIdsSet)
        {
            Doctor& doctor = doctorsById[doctorId];

            if (doctor.availableFromHour <= currentProblem.arrivalHour
                && currentProblem.arrivalHour + currentProblem.duration <= k_hospitalCloseTime)
            {
                // Assign problem to doctor
                doctor.availableFromHour = currentProblem.arrivalHour + currentProblem.duration;
                doctor.solvedProblems.push_back(currentProblem);
                break;
            }
        }
	}

    // Print output
    for (auto& doctorEntry : doctorsById)
    {
        Doctor& doctor = doctorEntry.second;
        if (doctor.solvedProblems.size() > 0) 
        {
            std::cout << doctor.id << " " << doctor.solvedProblems.size() << " ";
            for (const Problem& problem : doctor.solvedProblems) 
                std::cout << problem.name << " " << problem.arrivalHour << " ";

            std::cout << std::endl;
        }
    }

    std::getchar();

    return 0;
}