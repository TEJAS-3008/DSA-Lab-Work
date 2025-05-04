/*C. Write a separate C++ menu-driven program to implement Queue ADT using an integer-linked list. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

Enqueue
Dequeue
Peek
Exit*/

#include <iostream>
using namespace std;

//Class for implementing Queue using linked list
class queue{
    private:
        //Data Memebers
        struct node{
            int data;
            struct node *link;
        }*front, *rear;

    public:
        //Constructor
        queue(){
            front = nullptr;
            rear = nullptr;
        }
        void Enqueue(int val);//FUnction to Enqueue an element
        void Dequeue();//Function to Dequeue an element
        void peek();//Function to show the Element at front
        void display();//Function to dispaly the Queue
        bool isempty();//Function to check is the Queue is Empty
};


//Main code Block for Menu Program
int main(){
    int choice;
    queue obj;// creating an Instance of a class named obj
    while(1){
        cout << "\n\n<===== MENU =====>" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Exit" << endl;
        cout << "Select an option:";
        cin >> choice;

        switch(choice){
            case 1:
                //Asking user for val to Enqueue in the Queue
                int val;
                cout << "Enter value to enqueue: ";
                cin >> val;
                obj.Enqueue(val);
                break;
            case 2:
                obj.Dequeue();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                cout << "Exiting...." << endl;
                return 0;
            default:
                cout << "The selected choice Cease to Exist!!Please Try Again" << endl;
        }
    }
}


//Defining The Member Functions

bool queue::isempty(){//Defining the Factor for boundary Condition
    if(front == nullptr){
        return true;
    }else{
        return false;
    }
}

void queue::Enqueue(int val){
    if(isempty()){//Boundary conditions
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->link = nullptr;
        front = newnode;
        rear = newnode;
    }else{
        struct node * newnode = (struct node*)malloc(sizeof(struct node));
        newnode->data = val;
        newnode->link = nullptr;
        struct node *temp = rear;
        temp->link = newnode;
        rear = newnode;
    }
    display();
}

void queue::display(){
    struct node *temp = front;
    cout << "QUEUE:)>    ";
    while(temp != nullptr){
        cout << temp->data << " | ";
        temp = temp->link;
    }
}

void queue::Dequeue(){
    if(isempty()){//Boundary conditions
        cout << "The queue is Empty! Enqueue and Try Again!!" << endl;
    }else{
        struct node *temp = front;
        front = temp->link;
        temp->link = nullptr;
        display();
    }
}

void queue::peek(){
    if(isempty()){//Boundary conditions
        cout << "The queue is Empty!" << endl;
    }else{
        struct node *temp = front;
        cout << "Front Element: " << temp->data << endl;
    }
}