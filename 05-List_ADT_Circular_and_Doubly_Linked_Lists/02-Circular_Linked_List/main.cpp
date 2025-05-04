/*B. Write a C++ menu-driven program to implement List ADT using a circular linked list.
Maintain proper boundary conditions and follow good coding practices. The List ADT has
the following operations,
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit*/
#include <iostream>
#include <cstdlib> 
using namespace std;

class SCLL {
private:
    struct node {
        int data;
        struct node* next;
    };
    struct node* head;

public:
    SCLL() { head = nullptr; }

    void insbeg(int);     // O(1)
    void insend(int);     // O(n)
    int inspos(int, int); // O(n)
    void delbeg();        // O(n) 
    void delend();        // O(n)
    void delpos(int);     // O(n)
    int search(int);      // O(n)
    void display();       // O(n)
};

int main() {
    SCLL arr;
    int choice, num, pos;

    while (1) {
        cout << "\n           MENU\n";
        cout << "1. Insert Beginning\n";
        cout << "2. Insert End\n";
        cout << "3. Insert Position\n";
        cout << "4. Delete Beginning\n";
        cout << "5. Delete End\n";
        cout << "6. Delete Position\n";
        cout << "7. Search\n";
        cout << "8. Display\n";
        cout << "9. Exit\n";
        cout << "ENTER YOUR CHOICE: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter the value: ";
            cin >> num;
            arr.insbeg(num);
            break;
        case 2:
            cout << "Enter the value: ";
            cin >> num;
            arr.insend(num);
            break;
        case 3:
            cout << "Enter the value: ";
            cin >> num;
            cout << "Enter the position: ";
            cin >> pos;
            arr.inspos(num, pos);
            break;
        case 4:
            arr.delbeg();
            break;
        case 5:
            arr.delend();
            break;
        case 6:
            cout << "Enter the position: ";
            cin >> pos;
            arr.delpos(pos);
            break;
        case 7:
            cout << "Enter the value to search: ";
            cin >> num;
            pos = arr.search(num);
            if (pos != -1)
                cout << "Element " << num << " found at position " << pos << ".\n";
            else
                cout << "Element " << num << " not found.\n";
            break;
        case 8:
            arr.display();
            break;
        case 9:
            cout << "Exiting program...\n";
            return 0;
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    }
}

// Insert at Beginning
void SCLL::insbeg(int num) { // O(1)
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Find last node
            temp = temp->next;
        }
        ptr->next = head;
        head = ptr;
        temp->next = head; // Update last node’s next pointer
    }
}

// Insert at End
void SCLL::insend(int num) { // O(n)
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Traverse to last node
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head; // Circular link
    }
}

// Insert at Position (0-based index)
int SCLL::inspos(int num, int pos) { // O(n)
    if (head == nullptr || pos == 0) {
        insbeg(num);
        return 0;
    }

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    struct node* temp = head;
    int count = 0;

    while (temp->next != head && count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if (count < pos - 1) {
        cout << "Invalid position.\n";
        free(ptr);
        return -1;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    return 0;
}

// Delete from Beginning
void SCLL::delbeg() { //  O(n)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    struct node* ptr = head;

    if (head->next == head) { // Only one node
        head = nullptr;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Find last node
            temp = temp->next;
        }
        head = head->next;
        temp->next = head; // Maintain circular link
    }
    free(ptr);
}

// Delete from End
void SCLL::delend() { // O(n)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = nullptr;
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;

    while (temp->next != head) { // Traverse to last node
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; // Maintain circular link
    free(temp);
}

// Delete from Position
void SCLL::delpos(int pos) { // O(n)
    if (!head || pos < 0) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;
    int count = 0;

    if (pos == 0) { // Delete first node
        delbeg();
        return;
    }

    while (temp->next != head && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos) {
        cout << "Position out of range.\n";
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// Search for an element
int SCLL::search(int num) { // O(n)
    struct node* temp = head;
    int pos = 0;

    if (head == nullptr)
        return -1;

    do {
        if (temp->data == num)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

// Display the list
void SCLL::display() { // O(n)
    if (head == nullptr) {
        cout << "The List is Empty\n";
        return;
    }

    struct node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD (circular)\n";
}
