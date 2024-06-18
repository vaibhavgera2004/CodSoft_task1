// C++ Program to implement the to do list
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Define Task class
class Task {
private:
    string name; // Task name
    string description; // Task description
    string dueDate; // Task due date
    bool completed; // Task completion status

public:
    // Constructor to initialize a task
    Task(const string& n, const string& d, const string& dd)
        {
        name = n; 
        description = d;
        dueDate = dd;
        completed = false;
    }

    // Getter for task name
    string getName() const { 
        return name; 
        }

    // Getter for task description
    string getDescription() const { 
        return description; 
        }

    // Getter for task due date
    string getDueDate() const { 
        return dueDate; 
        }

    // Getter for task completion status
    bool isCompleted() const { 
        return completed; 
        }

    // Setter for task name
    void setName(const string& n) { 
        name = n; 
        }

    // Setter for task description
    void setDescription(const string& d)
    {
        description = d;
    }

    // Setter for task due date
    void setDueDate(const string& dd)
    {
        dueDate = dd;
    }

    // Mark the task as completed
    void markCompleted() { 
        completed = true; 
        }

    // Display task details
    void displayTask() const
    {
        cout << name << " ("<< (completed ? "Completed" : "Pending")<< ") - Due: " << dueDate << endl;
        cout << "   Description: " << description << endl;
    }
};

// Define to_do_list class
class to_do_list {
private:
    vector<Task> tasks; // List of tasks

public:
    // Add a new task
    void add_Task()
    {
        string name, description, dueDate;
        cout << "Enter task name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter task description: ";
        getline(cin, description);
        cout << "Enter task due date (DD-MM-YYYY): ";
        getline(cin, dueDate);

        tasks.emplace_back(name, description, dueDate);
        cout << "Task added successfully!" << endl;
    }

    // Delete a task
    void delete_Task()
    {
        if (tasks.empty()) {
            cout << "No tasks to delete!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to delete: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks.erase(tasks.begin() + taskNumber - 1);
            cout << "Task deleted successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Display all tasks
    void display_Task()
    {
        if (tasks.empty()) {
            cout << "No tasks to display!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            tasks[i].displayTask();
        }
    }

    // Mark a task as completed
    void mark_Task_Complet()
    {
        if (tasks.empty()) {
            cout << "No tasks to mark as completed!"
                 << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to mark as "
                "completed: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            tasks[taskNumber - 1].markCompleted();
            cout << "Task marked as completed!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }

    // Edit a task
    void edit_Task()
    {
        if (tasks.empty()) {
            cout << "No tasks to edit!" << endl;
            return;
        }
        cout << "Tasks:" << endl;
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i].getName()
                 << endl;
        }
        cout << "Enter the task number to edit: ";
        int taskNumber;
        cin >> taskNumber;
        if (taskNumber >= 1 && taskNumber <= tasks.size()) {
            Task& task = tasks[taskNumber - 1];
            string name, description, dueDate;
            cout << "Enter new task name (current: "
                 << task.getName() << "): ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter new task description (current: "
                 << task.getDescription() << "): ";
            getline(cin, description);
            cout << "Enter new task due date (current: "
                 << task.getDueDate() << "): ";
            getline(cin, dueDate);

            task.setName(name); 
            task.setDescription(description);
            task.setDueDate(dueDate);
            cout << "Task updated successfully!" << endl;
        }
        else {
            cout << "Invalid task number!" << endl;
        }
    }
        
};

// Main function
int main()
{
    // Create a to_do_list
    to_do_list to_do_list;
    int choice;
        do {
            cout<< "\n========== To-Do List Menu ==========\n";
            cout << "Enter 1 to Add Task\n";
            cout << "Enter 2 to Delete Task\n";
            cout << "Enter 3 to Display Tasks\n";
            cout << "Enter 4 to Mark Task as Completed\n";
            cout << "Enter 5 to Edit Task\n";
            cout << "Enter 6 to Exit\n";
            cout << "=====================================""\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                to_do_list.add_Task();
                break;
            case 2:
                to_do_list.delete_Task();
                break;
            case 3:
                to_do_list.display_Task();
                break;
            case 4:
                to_do_list.mark_Task_Complet();
                break;
            case 5:
                to_do_list.edit_Task();
                break;
            case 6:
                cout << "Thanks! for using our To Do List." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter right choice!"
                     << endl;
            }
        } while (choice != 6);
    return 0;
}