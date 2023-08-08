#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Task {
public:
    Task(const string& description) : description(description), completed(false) {}

    void markCompleted() {
        completed = true;
    }

    void markPending() {
        completed = false;
    }

    bool isCompleted() const {
        return completed;
    }

    string getDescription() const {
        return description;
    }

private:
    string description;
    bool completed;
};

class ToDoList {
public:
    void addTask(const Task& task) {
        tasks.push_back(task);
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].isCompleted()) {
                cout << "[Completed] ";
            }
            cout << tasks[i].getDescription() << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks[index - 1].markCompleted();
            cout << "Task marked as completed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

    void removeTask(size_t index) {
        if (index >= 1 && index <= tasks.size()) {
            tasks.erase(tasks.begin() + index - 1);
            cout << "Task removed." << endl;
        } else {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main() {
    ToDoList toDoList;
    int choice;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                string taskDescription;
                cout << "Enter task description: ";
                cin.ignore();
                getline(cin, taskDescription);
                Task newTask(taskDescription);
                toDoList.addTask(newTask);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                size_t index;
                toDoList.viewTasks();
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                toDoList.markTaskCompleted(index);
                break;
            }
            case 4: {
                size_t index;
                toDoList.viewTasks();
                cout << "Enter task index to remove: ";
                cin >> index;
                toDoList.removeTask(index);
                break;
            }
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
