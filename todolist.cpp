/*TO-DO LIST
 Build a simple console-based to-do list
 manager that allows users to add, view, and
 delete tasks
 Task Input: Allow users to input tasks they want to add to the list.
 Add Task: Implement a function to add tasks to the list.
 View Tasks: Display the list of tasks with their status (completed or pending).
 Mark Task as Completed: Allow users to mark tasks as completed.
 Remove Task: Provide an option to remove tasks from the list.
*/

#include <iostream>
#include <string>
using namespace std;

string task[10] = {""};
bool completed[10] = {false}; // Array to keep track of completed tasks
int task_count = 0;

void add();
void view();
void mark();
void remove_task();

int main() {
    int option;
    do {
        cout << "1 ----- Add a task to the list" << endl;
        cout << "2 ----- View tasks" << endl;
        cout << "3 ----- Mark a task as completed" << endl;
        cout << "4 ----- Remove a task from the list" << endl;
        cout << "0 ----- End the program" << endl;
        cout << "Enter your option: ";
        cin >> option;

        switch (option) {
            case 1:
                add();
                break;
            case 2:
                view();
                break;
            case 3:
                view();
                mark();
                break;
            case 4:
                remove_task();
                break;
            case 0:
                cout << "Program ended." << endl;
                return 0;
            default:
                cout << "Invalid input. Please try again." << endl;
                break;
        }
    } while (option != 0);

    return 0;
}

void add() {
    if (task_count > 9) {
        cout << "To-Do List is Full" << endl;
    } else {
        cout << "Enter the task: ";
        cin.ignore();
        getline(cin, task[task_count]);
        task_count++;
    }
}

void view() {
    cout << "------------------------------" << endl;
    cout << "Tasks To-Do:" << endl;
    for (int i = 0; i < task_count; i++) {
        cout << "Task " << i + 1 << ": " << task[i];
        if (completed[i]) {
            cout << " [Completed]";
        }
        cout << endl;
    }
    cout << "------------------------------" << endl;
}

void mark() {
    int task_number;
    cout << "Enter the task number to mark as completed: ";
    cin >> task_number;
    if (task_number > 0 && task_number <= task_count) {
        completed[task_number - 1] = true;
        cout << "Task " << task_number << " marked as completed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}

void remove_task() {
    int task_number;
    cout << "Enter the task number to remove: ";
    cin >> task_number;
    if (task_number > 0 && task_number <= task_count) {
        for (int i = task_number - 1; i < task_count - 1; i++) {
            task[i] = task[i + 1];
            completed[i] = completed[i + 1];
        }
        task_count--;
        cout << "Task " << task_number << " removed." << endl;
    } else {
        cout << "Invalid task number." << endl;
    }
}
