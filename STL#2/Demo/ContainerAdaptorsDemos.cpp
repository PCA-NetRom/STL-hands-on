#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <functional>
#include <stack>
#include <queue>

using namespace std;


struct Task {
    int priority;
    string description;

    bool operator<(const Task& other) const {
        return priority < other.priority;
    }
};

priority_queue<Task> taskQueue;

void addTask(int priority, const string& description) {
    Task task = { priority, description };
    taskQueue.push(task);
}

void executeHighestPriorityTask() {
    if (!taskQueue.empty()) {
        Task task = taskQueue.top();
        taskQueue.pop();
        cout << task.description << " with priority: " << task.priority << '\n';
    }
    else {
        cout << "No tasks available!" << '\n';
    }
}

/// <summary>
/// Demo3 - Priority_queue
/// </summary>
void demo3()
{
    addTask(5, "Fix bug");
    addTask(3, "Implement feature");
    addTask(10, "Clean-up database");

    executeHighestPriorityTask();
    executeHighestPriorityTask();
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

string currentText;
stack<string> history;

void write(const string& text) {
    history.push(currentText);
    currentText += text;
}

void undo() {
    if (!history.empty()) {
        currentText = history.top();
        history.pop();
    }
}

string read() {
    return currentText;
}

/// <summary>
/// Demo2 - Stack
/// </summary>
void demo2()
{
    write("Hello");
    cout << read() << '\n';

    write(" World");
    cout << read() << '\n';

    undo();
    cout << read() << '\n';
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

void demo_lambda()
{
    vector<int> numbers = { 11, 6, 2, 4, 9, 5, 3, 8, 10, 7, 1, 13, 15, 12, 14, 2 };
    int evenNumbersCount = count_if(numbers.begin(), numbers.end(), [](const int n) {
        return n % 2;
    });
    cout << evenNumbersCount << " even numbers!\n";

    int d = 3;
    auto firstDiv3 = find_if(numbers.begin(), numbers.end(), [d](const int n) {
        return n % d == 0;
    });
    cout << "First number divisible by 3 is " << *firstDiv3 << "\n";

    vector<int> evenNumbers;
    for_each(numbers.begin(), numbers.end(), [&evenNumbers](const int n) {
        if (n % 2 == 0)
        {
            evenNumbers.push_back(n);
        }
    });
    cout << "Even numbers are:\n";
    for (int n : evenNumbers)
    {
        cout << n << " ";
    }
    cout << "\n";
}

//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//
//

/// <summary>
/// Demo1 - Algorithms
/// </summary>
void demo1()
{
    vector<pair<int, int>> ids = {
        {1920512, 4},
        {7612341, 1},
        {9182852, 2},
        {8172341, 5},
        {1086754, 3}
    };

    sort(ids.begin(), ids.end(), [](const auto& a, const auto& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
        });

    for (const auto& [id, place] : ids) {
        cout << id << " with place " << place << std::endl;
    }

    auto it = upper_bound(ids.begin(), ids.end(), make_pair(0, 5),
        [](const auto& a, const auto& b) {
            return less<int>()(b.second, a.second);
        });

    if (it != ids.end()) {
        cout << "\nId \"" << it->first << "\" with place " << it->second << " is the last accepted." << endl;
    }
    else {
        cout << "\nNo id is declined." << endl;
    }
}

int main()
{
    // demo_lambda();
    //demo1();
    // demo2();
    demo3();
    return 0;
}
