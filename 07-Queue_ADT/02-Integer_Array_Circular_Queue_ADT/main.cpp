/*B. Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Circular Queue ADT has the following operations,

Enqueue
Dequeue
Peek
Exit
What is the time complexity of each of the operations? (K4)

*/

#include <iostream>
#include <vector>
using namespace std;

#define SIZE 5  // Fixed size for the circular queue

// Circular Queue Class
class CircularQueue {
private:
    vector<int> arr;
    int front, rear;

public:
    // Constructor
    CircularQueue() {
        arr.resize(SIZE, 0); // Initialize vector with fixed size
        front = -1;
        rear = -1;
    }

    bool isEmpty();  // Check if queue is empty
    bool isFull();   // Check if queue is full
    void enqueue(int val); // Insert element
    void dequeue();        // Remove element
    void peek();           // Get front element
    void display();        // Display queue elements
};

// Main Menu Function
int main() {
    CircularQueue obj;
    int choice, value;

    while (true) {
        cout << "\n\n<===== MENU =====>" << endl;
        cout << "1. Enqueue" << endl;
        cout << "2. Dequeue" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Exit" << endl;
        cout << "Select your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a value to enqueue: ";
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
                cout << "Invalid choice! Please try again." << endl;
        }
    }
}

// Check if queue is empty
bool CircularQueue::isEmpty() {
    return front == -1;
}

// Check if queue is full
bool CircularQueue::isFull() {
    return (rear + 1) % SIZE == front;
}

// Enqueue function
void CircularQueue::enqueue(int val) {
    if (isFull()) {
        cout << "Queue is Full! Cannot enqueue " << val << endl;
        return;
    }
    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    arr[rear] = val;
    cout << val << " enqueued successfully." << endl;
    display();
}

// Dequeue function
void CircularQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is Empty! Cannot dequeue." << endl;
        return;
    }
    cout << arr[front] << " dequeued successfully." << endl;
    if (front == rear) { // Only one element was present
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
    display();
}

// Peek function
void CircularQueue::peek() {
    if (isEmpty()) {
        cout << "Queue is Empty! No front element." << endl;
    } else {
        cout << "Front element: " << arr[front] << endl;
    }
}

// Display function
void CircularQueue::display() {
    if (isEmpty()) {
        cout << "Queue is Empty!" << endl;
        return;
    }
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << arr[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << endl;
}
