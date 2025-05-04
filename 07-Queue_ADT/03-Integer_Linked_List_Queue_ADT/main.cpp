#include <iostream>
using namespace std;

class Queue {
private:
    // Structure for linked list node
    struct Node {
        int data;
        Node* next;
    };

    struct Node* front;   // Pointer to the front of the queue
    struct Node* rear;    // Pointer to the rear of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // Reset when queue becomes empty
        }

        cout << temp->data << " dequeued.\n";
        delete temp;
    }

    // Peek operation
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}