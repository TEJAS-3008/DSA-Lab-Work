#include <iostream>
using namespace std;

#define size 10

class Hash {
private:
    int table[size];
    bool check[size];

public:
    Hash();

    int index(int key);

    void insert(int key);          // Average: O(1), Worst: O(n)
    void display();                // O(n)
    void search(int key);          // Average: O(1), Worst: O(n)
    void del(int key);             // Average: O(1), Worst: O(n)
};

int main() {
    Hash temp;
    int choice;

    while (1) {
        cout << "\nMENU\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter Number You Want to Insert: ";
                cin >> num;
                temp.insert(num);
                break;
            }
            case 2: {
                int num;
                cout << "Enter Number You Want to Delete: ";
                cin >> num;
                temp.del(num);
                break;
            }
            case 3: {
                int num;
                cout << "Enter Number You Want to Search: ";
                cin >> num;
                temp.search(num);
                break;
            }
            case 4:
                temp.display();
                break;
            case 5:
                cout << "Exiting ..." << endl;
                return 0;
            default:
                cout << "Invalid Input. TRY again." << endl;
        }
    }

    return 0;
}

Hash::Hash() {                     // O(n)
    for (int i = 0; i < size; i++) {
        check[i] = false;
    }
}

int Hash::index(int key) {         // O(1)
    return key % size;
}

void Hash::insert(int key) {       // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (!check[temp]) {
        table[temp] = key;
        check[temp] = true;
        cout << "The Number " << key << " was inserted at index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (!check[newIdx]) {
                table[newIdx] = key;
                check[newIdx] = true;
                cout << "The Number " << key << " was inserted at index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "The Hash Table is Full" << endl;
    }
}

void Hash::display() {             // O(n)
    for (int i = 0; i < size; i++) {
        if (check[i]) {
            cout << "Index " << i << " => " << table[i] << endl;
        } else {
            cout << "Index " << i << " => Empty" << endl;
        }
    }
}

void Hash::del(int key) {          // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (check[temp] && table[temp] == key) {
        check[temp] = false;
        cout << "The Number " << key << " was deleted from index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (check[newIdx] && table[newIdx] == key) {
                check[newIdx] = false;
                cout << "The Number " << key << " was deleted from index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "There is No Number " << key << " in the Hash Table" << endl;
    }
}

void Hash::search(int key) {       // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (check[temp] && table[temp] == key) {
        cout << "The Number " << key << " is found at index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (check[newIdx] && table[newIdx] == key) {
                cout << "The Number " << key << " is found at index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "The Number " << key << " is not found in the Hash Table" << endl;
    }
}