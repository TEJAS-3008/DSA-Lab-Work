/*
A. Write a menu-driven program to implement List ADT using a doubly linked list with a
tail. Maintain proper boundary conditions and follow good coding practices. The List ADT has
the following operations,
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
*/

#include <iostream>
#include <cstdlib>
using namespace std;

class DLL {
private:
    struct node {
        int data;
        struct node* previous;
        struct node* next;
    };
    struct node* head;
    struct node* tail;

public:
    DLL() { head = nullptr; tail = nullptr; }

    void insbeg(int);
    void insend(int);
    int inspos(int, int);
    void delbeg();
    void delend();
    void delpos(int);
    int search(int);
    void display();
};

int main() {
    DLL arr;
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
void DLL::insbeg(int num) {//O(1)
    struct node* ptr = new node;
    ptr->data = num;
    ptr->previous = nullptr;
    ptr->next = head;

    if (head == nullptr) {
        head = tail = ptr;
    } else {
        head->previous = ptr;
        head = ptr;
    }
}

// Insert at End
void DLL::insend(int num) {//O(1)
    struct node* ptr = new node;
    ptr->data = num;
    ptr->previous = tail;
    ptr->next = nullptr;

    if (head == nullptr) {
        head = tail = ptr;
    } else {
        tail->next = ptr;
        tail = ptr;
    }
}

// Insert at Position (0-based index)
int DLL::inspos(int num, int pos) {//O(n)
    if (head == nullptr || pos == 0) {
        insbeg(num);
        return 0;
    }

    struct node* ptr = new node;
    ptr->data = num;

    struct node* temp = head;
    int count = 0;

    while (temp->next != nullptr && count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if (count < pos - 1) {
        cout << "Invalid position.\n";
        delete ptr;
        return -1;
    }

    ptr->next = temp->next;
    ptr->previous = temp;
    if (temp->next)
        temp->next->previous = ptr;
    temp->next = ptr;
    if (ptr->next == nullptr)
        tail = ptr;

    return 0;
}

// Delete from Beginning
void DLL::delbeg() {//O(1)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    struct node* ptr = head;
    head = head->next;

    if (head) {
        head->previous = nullptr;
    } else {
        tail = nullptr;
    }
    delete ptr;
}

// Delete from End
void DLL::delend() {//O(1)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }
    struct node* ptr = tail;

    if (head == tail) {
        head = tail = nullptr;
    } else {
        tail = tail->previous;
        tail->next = nullptr;
    }
    delete ptr;
}

// Delete from Position
void DLL::delpos(int pos) {//O(n)
    if (!head || pos < 0) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    struct node* temp = head;
    int count = 0;

    while (temp && count < pos) {
        temp = temp->next;
        count++;
    }

    if (!temp) {
        cout << "Position out of range.\n";
        return;
    }

    if (temp == head) {
        head = head->next;
        if (head) head->previous = nullptr;
        else tail = nullptr;
    } else if (temp == tail) {
        tail = tail->previous;
        tail->next = nullptr;
    } else {
        temp->previous->next = temp->next;
        temp->next->previous = temp->previous;
    }

    delete temp;
}

// Search for an element
int DLL::search(int num) {//O(n)
    struct node* temp = head;
    int pos = 0;

    while (temp) {
        if (temp->data == num)
            return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

// Display the list
void DLL::display(){//O(n)
    struct node* temp = head;
    if(head == nullptr){
        cout<<"The List is Empty\n";
        return;
    }
    else{
        while (temp!=nullptr)
    {
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL\n";
    }
}
   