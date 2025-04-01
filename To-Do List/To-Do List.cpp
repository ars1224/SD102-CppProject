#include <iostream>
#include <vector>
#include <string>
#include <cctype>  // Needed for tolower()
#include <limits>  // Needed for clearing input buffer

using namespace std;

struct Task {
    string name;
    string deadline;
    bool isDone;
};

vector<Task> tasks;

void displayMenu() {
    cout << "\nTask Manager" << endl;
    cout << "1. Add Task" << endl;
    cout << "2. Show Task List" << endl;
    cout << "3. Mark Task as Done" << endl;
    cout << "4. Remove Task" << endl;
    cout << "5. Exit" << endl;
    cout << "Enter your choice: ";
}

void addTask() {
    char addMore;
    do {
        Task newTask;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Clears buffer before getline()

        cout << "Enter task name: ";
        getline(cin, newTask.name);

        cout << "Enter deadline: ";
        getline(cin, newTask.deadline);

        newTask.isDone = false;

        char confirm;
        cout << "Save this task? (y/n): ";
        cin >> confirm;

        if (tolower(confirm) == 'y') {
            tasks.push_back(newTask);
            cout << "Task added successfully!" << endl;
        }
        else {
            cout << "Task not saved." << endl;
        }

        cout << "Do you want to add another task? (y/n): ";
        cin >> addMore;

    } while (tolower(addMore) == 'y');
}

void showTasks() {
    if (tasks.empty()) {
        cout << "No tasks available." << endl;
        return;
    }

    cout << "\nTask List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].name << " (Deadline: " << tasks[i].deadline << ")";
        if (tasks[i].isDone) cout << " [DONE]";
        cout << endl;
    }
}

void markTaskDone() {
    showTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to mark as done: ";
    cin >> index;

    if (cin.fail() || index < 1 || index > tasks.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid task number!" << endl;
        return;
    }

    tasks[index - 1].isDone = true;
    cout << "Task marked as done!" << endl;
}

void removeTask() {
    showTasks();
    if (tasks.empty()) return;

    int index;
    cout << "Enter task number to remove: ";
    cin >> index;

    if (cin.fail() || index < 1 || index > tasks.size()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid task number!" << endl;
        return;
    }

    tasks.erase(tasks.begin() + index - 1);
    cout << "Task removed successfully!" << endl;
}

int main() {
    int choice;

    do {
        displayMenu();
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice) {
        case 1: addTask(); break;
        case 2: showTasks(); break;
        case 3: markTaskDone(); break;
        case 4: removeTask(); break;
        case 5: cout << "Exiting program..." << endl; return 0;
        default: cout << "Invalid choice! Try again." << endl;
        }

    } while (true);

    return 0;
}
