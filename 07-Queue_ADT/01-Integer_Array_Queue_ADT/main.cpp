/*A. Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

Enqueue
Dequeue
Peek
Exit
What is the time complexity of each of the operations? (K4)

*/

#include<iostream>
#include<vector>
using namespace std;


//Defining the class for Queue
class queue{
    private:
        //Data members
        vector<int> arr;
        int front;
        int rear;

    public:
        //CONSTRUCTOR
        queue(){
            front = -1;
            rear = -1;
        }
        bool isempty();//Function to check if queue is Empty
        bool isfull();//Funtion to check if the queue is Full
        void enqueue(int val);//Enqueue element into the list
        void dequeue();//Dequeue element from the list
        void peek();//Info about first element
        void display();//Display funtion to see the queue
};


//Main Function for Menu Program
int main(){
    int choice;
    queue obj;
    while(1){
        cout << "\n\n<===== MENU =====>" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Exit" << endl;
        cout << "Select your choice: " << endl;
        cin >> choice;
        switch(choice){
            case 1:
                int value;
                cout << "Enter a value to enqueue!" << endl;
                cin >> value;
                obj.enqueue(value);
                break;
            case 2:
                obj.dequeue();
                break;
            case 3:
                obj.peek();
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0; 
            default:
                cout << "The selelcted choice cease to Exist\nPlease Try Again" << endl;
        }
    }
}



//DEFINING THE FUNCTION

bool queue::isempty(){
    if(rear == -1 && front == -1){
        return true;
    }else{
        return false;
    }
}

bool queue::isfull(){
    if(rear >= 4){
        return true;
    }else{
        return false;
    }
}

void queue::enqueue(int val){
    if(isfull()){
        cout << "The queue is Full!, Dequeue and Try Again!!" << endl;
    }else{
        arr.push_back(val);
        rear++;
    }
    display();
}

void queue::display(){
    for(int i = 0;i <= rear;i++){
        cout << arr[i]<< " | ";
    }
}

void queue::dequeue(){
    if(isempty()){
        cout << "The queue is empty! Enqueue and Try Again!!" << endl;
    }else{
        int temp = arr[0];
        for(int i = 0;i < rear; i++){
            arr[i] = arr[i + 1];
        }
        rear--;
        cout << temp << " Dequeued from the queue!!" << endl; 
        display();
    }
}


void queue::peek(){
    if(isempty()){
        cout << "The queue is empty!" << endl;
    }else{
        cout << "Front in the queue is " << arr[0] << endl;
    }
}