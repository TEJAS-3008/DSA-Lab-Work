#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;  // Initialize front on first enqueue
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) front = rear = -1;  // Reset when queue becomes empty
    }

    // Peek operation
    void peek() {
        if (count == 0) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";

        }
    }
}