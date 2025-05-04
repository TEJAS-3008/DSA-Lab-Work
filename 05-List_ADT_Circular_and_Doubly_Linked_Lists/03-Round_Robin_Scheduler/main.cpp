/*C. An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be 
initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list.
Implement the program by including the appropriate header file. It consists of the following operations.
Insert Process
Execute
Exit
The "Insert Process" will get an integer time from the user and add it to the queue.
The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process.
 If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining
 time after subtraction is inserted at the end of the circular linked list.
What is the time complexity of each of the operations? (K4)
*/
#include<iostream>
#include<cstdlib>
using namespace std;

class schedule {
private:
    struct process {
        int time;
        struct process *link;
    }*head = nullptr, *tail = nullptr;

    int pro_count = 0;
    int timeslice = 0;

public:
    schedule() { head = nullptr; tail = nullptr; }

    void getimeslice();   // O(1)
    void insert(int pro_time);   // O(1)
    void delete_process();   // O(1)
    void execute();   // O(n) in worst case
};

int main() {
    int selection;
    schedule cpu;
    cpu.getimeslice();

    while (1) {
        cout << "\n       MENU        " << endl;
        cout << "1. Insert Process" << endl;
        cout << "2. Execute" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> selection;

        switch (selection) {
            case 1:
                int process_time;
                cout << "Enter the process time: ";
                cin >> process_time;
                cpu.insert(process_time);
                break;
            case 2:
                cpu.execute();
                break;
            case 3:
                cout << "Exiting....." << endl;
                return 0;
            default:
                cout << "Selected choice Cease to exist\nplease Try Again" << endl;
        }
    }
}

// O(1)
void schedule::getimeslice() {
    cout << "Enter the time slice for a process: ";
    cin >> timeslice;
}

// O(1)
void schedule::insert(int pro_time) {
    struct process *newprocess = (struct process *)malloc(sizeof(struct process));
    newprocess->time = pro_time;
    newprocess->link = nullptr;

    if (head == nullptr && tail == nullptr) {
        head = newprocess;
        tail = newprocess;
        newprocess->link = head;
    } else {
        tail->link = newprocess;
        tail = newprocess;
        newprocess->link = head;
    }
    pro_count++;
}

// O(1)
void schedule::delete_process() {
    if (head == tail) {
        head->link = nullptr;
        head = nullptr;
        tail = nullptr;
    } else {
        struct process *temp = head;
        head = temp->link;
        temp->link = nullptr;
        tail->link = head;
        free(temp);
    }
    pro_count--;
}

// O(n) in worst case (when the process needs to be moved to the end)
void schedule::execute() {
    struct process *temp = head;
    struct process *temp2 = head;

    if (temp == nullptr) {
        cout << "There are no processes to execute!!" << endl;
    } else {
        temp->time = temp->time - timeslice;

        if (temp->time <= 0) {
            delete_process();  // O(1)
        } else {
            head = temp->link;
            
            // Find the last process in the list to update the tail
            while (temp != tail) {
                temp = temp->link;
            }
            temp->link->link = temp2;
            tail = temp2;
        }

        cout << "Execution Completed!!" << endl;
        cout << "No of processes pending --> " << pro_count << endl;
    }
}
