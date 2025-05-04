/*B. Write a separate C++ menu-driven program to implement stack ADT using a character singly linked list. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations,

Push
Pop
Peek
Exit
What is the time complexity of each of the operations? (K4)*/



#include <iostream>
#include <cstdlib>
using namespace std;


//Creatuing a class for stack using singly linked list
class singlystack{
    private:
        //data members
        struct node{
            char ch;
            struct node *link;
        }*head = nullptr, *tail = nullptr;
        int count = 0;

    public:
        //Constructor
        singlystack(){
            head = nullptr;
            tail = nullptr;
        }
        //member functions
        void push(char c);
        void pop();
        void peek();
        void reverse_link();
        void display();
};




int main(){
    int choice;
    singlystack stack;
    //Menu Program
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
                char ch;
                cout << "Enter a character to push into the stack: ";
                cin >> ch;
                stack.push(ch);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting...." << endl;
                return 0;
            default:
                cout << "Selected Option Cease to exist\nPlease Try Again" << endl;
        }
    }
}


//function to push character into a stack
void singlystack::push(char c){
    struct node *chnode = (struct node*)malloc(sizeof(struct node));
    chnode->ch = c;
    chnode->link = nullptr;
    struct node *temp = tail;
    if(head == nullptr){
        head = chnode;
        tail = chnode;
    }else{
        temp->link = chnode;
        tail = chnode;
    }
    count++;
    display();
}
//Time complexity is O(1)without display, It is O(n + 1)with display



//defining the pop function
void singlystack::pop(){
    if((head == nullptr && tail == nullptr)){
        cout << "The Stack is empty\n" << endl;
        return;
    }else{
        if(count == 1){
            head->link = nullptr;
            head = nullptr;
            tail = nullptr;
            count--;
        }else{
            struct node *temp = head;
            while(temp->link != tail){
                temp = temp->link;
            }
            temp->link = nullptr;
            tail = temp;
            count--;
        }
        display();
    }
}
//Time complexity is O(n)


//Defining the function for peek
void singlystack::peek(){
    if(count == 0){
        cout << "The stack is empty" << endl;
    }else{
        struct node *temp = head;
        while(temp->link != nullptr){
            temp = temp->link;
        }
        cout << "Top element of the stack is " << temp->ch << endl;
    }
}
//TIme complexity is O(n)


//Defining the function for display
void singlystack::display(){
    reverse_link();
    struct node *temp = head;
    cout << "Current stack :\n" << endl;
    while(temp != nullptr){
        cout << "|" << temp->ch << "|" << endl;
        cout << "---" << endl;
        temp = temp->link;
    }
    reverse_link();
}
//Time complexity if O(n)


//Defining the function to reverse a link
void singlystack::reverse_link(){
    struct node *current = head;
    struct node *prev = nullptr;
    struct node *next = nullptr;
    head = tail;
    tail = current;
    while(current != nullptr){
        next = current->link;
        current->link = prev;
        prev = current;
        current = next;
    }
    head = prev;
}
//TIme complexity is O(n)
