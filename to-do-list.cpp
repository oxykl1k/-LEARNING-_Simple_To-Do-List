#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "Your list is empty!" << endl;
        return;
    }

    cout << "Your tasks: " << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". " << tasks[i] << endl;
    }
}

void addTask(vector<string>& tasks) {
    cout << "Enter the new task: ";
    string task;
    getline(cin, task);
    tasks.push_back(task);
    cout << "The task has been added!" << endl;
}

void deleteTask(vector<string>& tasks) {
    cout << "Enther the number of task to delete: ";
    size_t index;
    cin >> index;

    // '-1', b.c. index starts from '0', but user enters the numbers from '1'
    if (index == 0 || index > tasks.size()) {
        cout << "Incorrect number of task!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "The task has been deleted!" << endl;
    cin.ignore(); // ignoring the symbol of new line after entering the number
}

int main() {
    vector<string> tasks;
    int choice;

    while (true) {
        cout << "\nTo-Do List Menu:\n";
        cout << "1. Show the list of tasks\n";
        cout << "2. Add a task\n";
        cout << "3. Delete a task\n";
        cout << "4. Exit\n";
        cout << "Enter the number (1-4): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
        case 1:
            displayTasks(tasks);
            break;
        case 2:
            addTask(tasks);
            break;
        case 3:
            deleteTask(tasks);
            break;
        case 4:
            cout << "Closing..." << endl;
            return 0;
        default:
            cout << "Incorrect syntax, try to type again" << endl;
        }
    }

    return 0;
}