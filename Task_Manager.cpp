#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

using namespace std;

class Task {
public:
    int id;
    string description;
    bool completed;

    Task(int id, const string& description, bool completed = false)
        : id(id), description(description), completed(completed) {}
};

class TaskManager {
private:
    vector<Task> tasks;
    int nextId = 1;

    void saveToFile() {
        ofstream file("tasks.txt");
        for (const auto& task : tasks) {
            file << task.id << "|" << task.description << "|" << task.completed << "\n";
        }
        file.close();
    }

    void loadFromFile() {
        ifstream file("tasks.txt");
        if (!file.is_open()) return;

        tasks.clear();
        string line;
        while (getline(file, line)) {
            size_t pos1 = line.find('|');
            size_t pos2 = line.rfind('|');
            int id = stoi(line.substr(0, pos1));
            string description = line.substr(pos1 + 1, pos2 - pos1 - 1);
            bool completed = (line.substr(pos2 + 1) == "1");

            tasks.emplace_back(id, description, completed);
            nextId = max(nextId, id + 1);
        }
        file.close();
    }

public:
    TaskManager() {
        loadFromFile();
    }

    ~TaskManager() {
        saveToFile();
    }

    void addTask(const string& description) {
        tasks.emplace_back(nextId++, description);
        cout << "Task added successfully!\n";
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "No tasks available.\n";
            return;
        }
        cout << "\nTasks:\n";
        cout << setw(5) << "ID" << setw(20) << "Description" << setw(15) << "Completed\n";
        for (const auto& task : tasks) {
            cout << setw(5) << task.id
                 << setw(20) << task.description
                 << setw(15) << (task.completed ? "Yes" : "No") << "\n";
        }
    }

    void completeTask(int id) {
        for (auto& task : tasks) {
            if (task.id == id) {
                task.completed = true;
                cout << "Task marked as completed!\n";
                return;
            }
        }
        cout << "Task with ID " << id << " not found.\n";
    }

    void deleteTask(int id) {
        auto it = remove_if(tasks.begin(), tasks.end(),
                            [id](const Task& task) { return task.id == id; });
        if (it != tasks.end()) {
            tasks.erase(it, tasks.end());
            cout << "Task deleted successfully!\n";
        } else {
            cout << "Task with ID " << id << " not found.\n";
        }
    }
};

int main() {
    TaskManager manager;
    int choice;

    do {
        cout << "\n--- Task Manager ---\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Complete Task\n";
        cout << "4. Delete Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            cout << "Enter task description: ";
            cin.ignore();
            string description;
            getline(cin, description);
            manager.addTask(description);
            break;
        }
        case 2:
            manager.viewTasks();
            break;
        case 3: {
            cout << "Enter task ID to mark as completed: ";
            int id;
            cin >> id;
            manager.completeTask(id);
            break;
        }
        case 4: {
            cout << "Enter task ID to delete: ";
            int id;
            cin >> id;
            manager.deleteTask(id);
            break;
        }
        case 5:
            cout << "Exiting Task Manager. Goodbye!\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
