#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task {
private:
    string description;
    bool completed;

public:
    Task(const string& desc) : description(desc), completed(false) {}

    void markAsComplete() {
        completed = true;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        tasks.emplace_back(description);
    }

    void removeTask(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks.erase(tasks.begin() + index);
        } else {
            cout << "Invalid task index!" << endl;
        }
    }

    void displayTasks() const {
        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].isCompleted()) {
                cout << "[\u2714︎] "; 
            } else {
                cout << "[ ] ";
            }
            cout << tasks[i].getDescription() << endl;
        }
    }

    void markTaskComplete(int index) {
        if (index >= 0 && index < tasks.size()) {
            tasks[index].markAsComplete();
        } else {
            cout << "Invalid task index!" << endl;
        }
    }
};

int main() {
    ToDoList myToDoList;

    int option = 0;

    while (option != 5) {
        cout << "\nOptions:\n1. Add Task\n2. View Tasks\n3. Mark Task as Complete\n4. Remove Task\n5. Exit\nEnter option: ";
        cin >> option;

        switch (option) {
            case 1: {
                string description;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, description);
                myToDoList.addTask(description);
                cout << "Task added!" << endl;
                break;
            }
            case 2:
                myToDoList.displayTasks();
                break;
            case 3: {
                int index;
                cout << "Enter task index to mark as complete: ";
                cin >> index;
                myToDoList.markTaskComplete(index - 1); 
                break;
            }
            case 4: {
                int index;
                cout << "Enter task index to remove: ";
                cin >> index;
                myToDoList.removeTask(index - 1);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid option!" << endl;
                break;
        }
    }

    return 0;
}
