#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* table[SIZE];
    int hashFunction(int key);

public:
    HashTable();
    void insert(int key);        // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void remove(int key);        // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void search(int key);       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void display();             // Time Complexity: O(SIZE * n) where n is the average chain length
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter number to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter number to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        ht.display();  // Show table after each operation
    }

    return 0;
}


HashTable::HashTable() {        // Time Complexity: O(SIZE) → Initializes all buckets to nullptr
    for (int i = 0; i < SIZE; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int key) {  // Time Complexity: O(1) → Simple modulo operation
    return key % SIZE;
}

void HashTable::insert(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
    cout << "Inserted " << key << " at index " << index << endl;
}

void HashTable::remove(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == key) {
            if (prev == nullptr)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "Deleted " << key << " from index " << index << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Key " << key << " not found." << endl;
}

void HashTable::search(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* curr = table[index];

    while (curr != nullptr) {
        if (curr->data == key) {
            cout << "Found " << key << " at index " << index << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Key " << key << " not found." << endl;
}

void HashTable::display() {             // Time Complexity: O(SIZE * n) where n is the average chain length
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Index " << i << ": ";
        Node* curr = table[i];
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}