#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the stack

class Stack {
private:
    char arr[SIZE];  
    int top;         

public:
    Stack() { top = -1; } 

    void push(char ch);
    void pop();
    void peek();
};

int main() {
    Stack stack;
    int choice;
    char value;

    while (true) {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}

 // Push operation Time Complexity O(1)
 void Stack :: push(char ch) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << ch << "." << endl;
        return;
    }
    arr[++top] = ch;
    cout << ch << " pushed onto stack." << endl;
}

// Pop operation Time Complexity O(1)
void Stack :: pop() {
    if (top == -1) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    cout << arr[top] << " popped from stack." << endl;
    top--;
}

 // Peek operation (View the top element) Time Complexity O(1)
 void Stack :: peek() {
    if (top == -1) {
        cout << "Stack is empty! No element to peek." << endl;
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}