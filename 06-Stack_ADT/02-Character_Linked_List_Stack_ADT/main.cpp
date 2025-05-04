#include <iostream>
#include <cstdlib>  
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* top; // Pointer to the top of the stack

public:
    Stack(){
        top = nullptr;
    };           // Constructor
    void push(char ch); 
    void pop();        
    void peek();       
    void clear();      
};

// Main function with a menu-driven interface
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
                stack.clear(); // Manually clear memory before exiting
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}


// Push operation Time Complexity O(1)
void Stack::push(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (!newNode) {
        cout << "Heap Overflow! Cannot push " << ch << "." << endl;
        return;
    }
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
    cout << ch << " pushed onto stack." << endl;
}

// Pop operation Time Complexity O(1)
void Stack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    Node* temp = top;
    cout << top->data << " popped from stack." << endl;
    top = top->next;
    free(temp);
}

// Peek operation Time Complexity O(1)
void Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty! No element to peek." << endl;
        return;
    }
    cout << "Top element: " << top->data << endl;
}

// Manual memory cleanup function Time Complexity O(n)
void Stack::clear() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        free(temp); 
    }
}
