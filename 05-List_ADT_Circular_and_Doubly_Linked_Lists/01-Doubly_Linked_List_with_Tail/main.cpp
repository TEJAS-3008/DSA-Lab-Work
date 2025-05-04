
/*Doubly linked list implementation using head and tail, the menu driven program contains following operations:
1.Insert beginning
2.Insert end
3.insert position
4.delete beginning
5.delete end
6.delete position
7.display
8.search
9.exit
write the time complexities for each operation
*/


#include <iostream>
#include <cstdlib>
using namespace std;


//Declaring the class for the list
class doubly{
    private:
        //declaring the structure , head and tail pointers
        struct node{
            int data;
            struct node *next;
            struct node *prev;
        }*head = nullptr, *tail = nullptr;
        int count = 0;

    public:
        //Member functions
        doubly(){
            head = nullptr;
            tail = nullptr;
        }
        void insert_beginning(int value);
        void insert_end(int value);
        void delete_beginning();
        void delete_end();
        void insert_position(int value);
        void delete_position();
        void search();
        void display();
};



int main(){
    int selection;
    int value;
    doubly list;
    //Menu Program
    while(1){
        cout << "\n<======= MENU =======>" << endl;
        cout << "1 -> Insert at the beginning" << endl;
        cout << "2 -> Insert at the end" << endl;
        cout << "3 -> Insert at position" << endl;
        cout << "4 -> Delete at beginning" << endl;
        cout << "5 -> Delete at end" << endl;
        cout << "6 -> Delete at position" << endl;
        cout << "7 -> Search" << endl;
        cout << "8 -> Display" << endl;
        cout << "9 -> Exit" << endl;
        cout << "Enter your choice:";
        cin >> selection;
        switch(selection){
            case 1:
                cout << "Enter the value to insert:";
                cin >> value;
                list.insert_beginning(value);
                break;
            case 2:
                cout << "Enter the value to insert:";
                cin >> value;
                list.insert_end(value);
                break;
            case 3:
                cout << "Enter the value to insert:";
                cin >> value;
                list.insert_position(value);
                break;
            case 4:
                list.delete_beginning();
                break;
            case 5:
                list.delete_end();
                break;
            case 6:
                list.delete_position();
                break;
            case 7:
                list.search();
                break;
            case 8:
                list.display();
                break;
            case 9:
                cout << "Exiting....." << endl;
                return 0;
            default:
                cout << "The option selected CEASE to exist\nTry Again!!" << endl;
        }
    }
}


//Function to insert at beginning
void doubly::insert_beginning(int value){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    if(head == nullptr && tail == nullptr){
        head = newnode;
        tail = newnode;
    }else{
        head->prev = newnode;
        newnode->next = head;
        head = newnode;
    }
    count++;
}
//Time Complexity of this function is O(1)



//function to display the Linked List By traversing
void doubly::display(){
    struct node *temp = head;
    cout << "Doubly Linked List: NULL <-> ";
    while(temp != nullptr){
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
//Time Complexity of this function is O(n)


//function for insertion at end
void doubly::insert_end(int value){
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = nullptr;
    newnode->prev = nullptr;
    struct node *temp = tail;
    newnode->prev = temp;
    temp->next = newnode;
    tail = newnode;
    count++;
}
//Time Complexity of this function is O(1)



//function for deletion ar beginning
void doubly::delete_beginning(){
    struct node *temp = head;
    if(head == tail){
        head = nullptr;
        tail = nullptr;
    }else{
        head = temp->next;
        temp->next = nullptr;
        head->prev = nullptr;
    }
    if(count <= 0){
        count = 0;
    }else{
        count--;
    }
}
//Time Complexity of this function is O(1)



//function for Deletion at the End
void doubly::delete_end(){
    struct node *temp = tail;
    if(head == tail){
        head = nullptr;
        tail = nullptr;
    }else{
        tail = temp->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
    }
    if(count <= 0){
        count = 0;
    }else{
        count--;
    }
}
//Time Complexity of this function is O(1)



//Function for Insertion at a position
void doubly::insert_position(int value){
    int pos;
    cout << "Enter teh position to insert: ";
    cin >> pos;

    if(pos < 1 || pos > count){
        cout << "Warning position exceeds limits" << endl;
    }else if(pos == 1){
        insert_beginning(value);
    }else if(pos == count + 1){
        insert_end(value);
    }else{
        struct node *newnode = (struct node *)malloc(sizeof(struct node));
        newnode->data = value;
        newnode->next = nullptr;
        newnode->prev = nullptr;

        struct node *temp = head;

        for(int i = 1; i < pos - 1; i++){
            temp = temp->next;
        }
        struct node *temp2 = temp->next;
        temp->next = newnode;
        temp2->prev = newnode;
        newnode->prev = temp;
        newnode->next = temp2;
        count++;
    }
}
//Time Complexity for this function is O(n)



//Function to Delete at a position
void doubly::delete_position(){
    int pos;
    cout << "Enter posiion to delete:";
    cin >> pos;

    if(pos < 1 || pos > count){
        cout << "Warning position exceeds limits" << endl;
    }else if(pos == 1){
        delete_beginning();
    }else if(pos == count + 1){
        delete_end();
    }else{
        struct node *temp = head;
        struct node *temp2 = tail;

        for(int i = 1;i < pos - 1;i++){
            temp = temp->next;
        }
        struct node *temp3 = temp->next;
        temp3->next = nullptr;
        temp3->prev = nullptr;
        for(int i = count; i > pos + 1; i--){
            temp2 = temp2->prev;
        }
        temp->next = temp2;
        temp2->prev = temp;
        count--;
    }
}
//Time Complexity for the function is O(2n)



//Function to Search for an element
void doubly::search(){
    int value;
    cout << "Enter the value: ";
    cin >> value;
    int flag = 0;
    struct node *temp = head;
    while(temp != nullptr){
        if(value == temp->data){
            flag = 1;
            break;
        }
        temp = temp->next;
    }

    if(flag == 1){
        cout << "Element found!!" << endl;
    }else{
        cout << "Element not found!!" << endl; 
    }
}
//Time Complexity for the function is O(n)


