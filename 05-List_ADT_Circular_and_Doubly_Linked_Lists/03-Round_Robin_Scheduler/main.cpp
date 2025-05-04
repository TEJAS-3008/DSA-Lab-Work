/*C. An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list.

Implement the program by including the appropriate header file. It consists of the following operations.

Insert Process
Execute
Exit
The "Insert Process" will get an integer time from the user and add it to the queue.

The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is inserted at the end of the circular linked list.

What is the time complexity of each of the operations? (K4)
*/

#include<iostream>
#include<cstdlib>
using namespace std;

//class for Round-Robin-Schedule
class schedule{
    private:
        struct process{
            int time;
            struct process *link;
        }*head = nullptr, *tail = nullptr;
        int pro_count = 0;
        int timeslice = 0;

    public:
    //Constructor
        schedule(){
            head = nullptr;
            tail = nullptr;
        }
    //member function protoypes
        void getimeslice();
        void insert(int pro_time);
        void delete_process();
        void execute();
        void display();


};


//main function
int main(){
    int selection;
    schedule cpu;
    cpu.getimeslice();
    while(1){
        //Menu-Driven program
        cout << "\n<===== MENU =====>" << endl;
        cout << "1.Insert Process" << endl;
        cout << "2.Execute" << endl;
        cout << "3.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> selection;
        switch(selection){
            case 1:
            //inserting the process
                int process_time;
                cout << "Enter the process time: ";
                cin >> process_time;
                cpu.insert(process_time);
                break;
            case 2:
            //executing the process
                cpu.execute();
                break;
            case 3:
            //exiting the menu
                cout << "Exiting....." << endl;
                return 0;
            default:
                cout << "Selected choice Cease to exist\nplease Try Again" << endl;
        }
    }
}


//member function to get the time alloted for each process
void schedule::getimeslice(){
    cout << "Enter the time slice a process: ";
    cin >> timeslice;
}


//member function for inserting the process
void schedule::insert(int pro_time){
    struct process *newproccess = (struct process *)malloc(sizeof(struct process));
    newproccess->time = pro_time;
    newproccess->link = nullptr;
    if(head == nullptr && tail == nullptr){
        head = newproccess;
        tail = newproccess;
        newproccess->link = head;
    }else{
        tail->link = newproccess;
        tail = newproccess;
        newproccess->link = head;
    }
    pro_count++;
    //display();
}
//Time Complexity is O(1)






//The below display function is to check how to process are running inside the circular linked list

/*void schedule::display(){
    struct process *temp = head;
    cout << "Process times to complete in queue: ";
    while(temp != tail){
        cout << temp->time << " <- ";
        temp = temp->link;
    }
    if(temp == nullptr){
        return;
    }else{
        cout << temp->time << endl;
    }
}
//Time Complexity is O(n)
*/


//member function to delete a process
void schedule::delete_process(){
    if(head == tail){
        head->link = nullptr;
        head = nullptr;
        tail = nullptr;
    }else{
        struct process *temp = head;
        head = temp->link;
        temp->link = nullptr;
        tail->link = head;
        free(temp);
    }
    pro_count--;
}
//Time Complexity is O(1)


//member function to execute a process
void schedule::execute(){
    struct process *temp = head;
    struct process *temp2 = head;
    if(temp == nullptr){
        cout << "There are no process to execute!!" << endl;
    }else{
        temp->time = temp->time - timeslice;
        if(temp->time <= 0){
            delete_process();
        }else{
            head = temp->link;
            while(temp != tail){
                temp = temp->link;
            }
            temp->link->link = temp2;
            tail = temp2;
        }
        
        cout << "Execution Completed!!" << endl;
        cout << "No of process pending --> " << pro_count << endl;
    }
    //display();
}
//Time Complexity is O(n + 1)
//1 form display
//n for the execute function


