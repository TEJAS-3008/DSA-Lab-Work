/*A. Write a separate C++ menu-driven program to implement stack ADT using a character array of size 5. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations,

1.Push
2.Pop
3.Peek
4.Exit
What is the time complexity of each of the operations? (K4)

*/

#include <iostream>
using namespace std;

#define size 5//making a fixed size of 5

//creating the stack class
class stack{
    private:
        //data members
        char arr[size];
        int count;
        public:
        //Constructor of the stack
        stack(){
            count = 0;
        }
        //member functions:
        void push(char ch);
        void pop();
        void peek();
        void display();
};

int main(){
    int choice;
    stack s;
    while(1){
        cout << "\n<===== MENU =====>" << endl;
        cout << "1.Push" << endl;
        cout << "2.Pop" << endl;
        cout << "3.Peek" << endl;
        cout << "4.Exit" << endl;
        cout << "Select your choice" << endl;
        cin >> choice;
        switch(choice){
            case 1:
                char c;
                cout << "Enter a character to push into the stack: ";
                cin >> c;
                s.push(c);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                s.peek();
                break;
            case 4:
                cout << "Exiting...." << endl;
                return 0;
            default:
                cout << "Selected Option Cease to exist\nPlease Try Again" << endl;
        }
    }
}

//Defining the push function
void stack::push(char ch){
    if(count == size){
        cout << "This action causes stack overflow\nProcess terminated" << endl;
    }else{
        arr[count] = ch;
        count++;
        cout << "The element " << ch << "pushed into the stack" << endl;
    }
    display();
}
//Time complexity of the push function is O(1)



//defining the pop function
void stack::pop(){
    if(count <= 0){
        cout << "The Stack is Empty\nPush elements and Try Again" << endl;
    }else{
        arr[count] = 0;
        count--;
        cout << "Top element of the stack is removed/poped" << endl;
    }
    display();
}
//Time complexity if the pop function is O(1)



//Defining the peek function
void stack::peek(){
    if(count <= 0){
        cout << "The stack is empty \n" << endl;
    }else{
        cout << "Top element of the stack is " << arr[count - 1] << endl;
    }
}
//Time complexity of the peek function is O(1)



//Defining the Display function
void stack::display(){
    int loopcount = count;
    cout << "STACK --->" << endl << endl;
    while(loopcount--){
        cout << "|" << arr[loopcount] << "|" << endl;
        cout << "---" << endl;
    }
}
//TIme complexity of the display function is O(1)






