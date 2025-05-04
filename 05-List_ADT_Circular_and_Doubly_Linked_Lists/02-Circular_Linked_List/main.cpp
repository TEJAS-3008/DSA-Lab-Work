/*Circular linked list*/

#include <iostream>
#include <cstdlib>
using namespace std;

//class for circular linked list
class circular{
    private:
        struct node{
            int data;
            struct node* link;
        }*head = nullptr;
        int count = 0;

    public:
        circular(){
            head = nullptr;
        }
        //member functions
        void insert_beginning(int value);
        void insert_end(int value);
        void insert_position(int value);
        void delete_beginning();
        void delete_end();
        void delete_position();
        void search();
        void display();

};

int main(){
    int selection;
    int value;
    circular list;
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


//Function for Insertion at beginning
void circular::insert_beginning(int value){
    int num = value;
    struct node *cnode = (struct node*)malloc(sizeof(struct node));
    cnode->data = num;
    cnode->link = nullptr;
    if(head == nullptr){
        head = cnode;
        cnode->link = head;
        count++;
    }else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        cnode->link = temp;
        while(temp->link != head){
            temp = temp->link;
        }
        temp->link = cnode;
        head = cnode;
        count++;
    }
}
//Time Complexity = O(n)


//Function for insertion at end
void circular::insert_end(int value){
    int num = value;
    struct node *cnode = (struct node*)malloc(sizeof(struct node));
    cnode->data = num;
    cnode->link = nullptr;
    if(head == nullptr){
        head = cnode;
        cnode->link = head;
        count++;
    }else{
        struct node *temp = (struct node*)malloc(sizeof(struct node));
        temp = head;
        while(temp->link != head){
            temp = temp ->link;
        }
        temp->link = cnode;
        cnode->link = head;
        count++;
    }
}
//Time complexity = O(n)


//function for insertion at position
void circular::insert_position(int value){
    int pos;
    cout << "Enter the position for insertion:";
    cin >> pos;
    if(pos <= 0 || pos > count + 1){
        cout << "Position entered exceeds Limits\nTry Again" << endl;
    }else{
        if(pos == 1){
            insert_beginning(value);
            return;
        }
        int num = value;
        struct node *cnode = (struct node*)malloc(sizeof(struct node));
        cnode->data = num;
        cnode->link = nullptr;
        struct node *temp = head;
        struct node *temp2;
        for(int i = 1; i < pos - 1; i++) {  
            temp = temp->link;
        }        
        temp2 = temp->link;
        temp->link = cnode;
        cnode->link = temp2;
        count++;
    }
}
//Time complexity = O(n)


//Function to Delete at beginning
void circular::delete_beginning(){
    if(count <= 0){
        cout << "The list is empty" << endl;
    }else{
        struct node *temp3 = head;
        struct node *temp = head;
        struct node *temp2 = temp->link;
        while(temp3->link != temp){
            temp3 = temp3->link;
        }
        temp3->link = temp2;
        head = temp2;
        temp->link = nullptr;
        count--;
    }
}
//Time complexity is O(n)

//function for deletion at the end
void circular::delete_end(){
    if(count <= 0){
        cout << "The list is empty" << endl;
    }else{
        struct node *temp = head;
        struct node *temp2 = head;
        while(temp->link != head){
            temp = temp->link;
        }
        temp->link = nullptr;
        for(int i = 1;i < count; i++ ){
            temp2 = temp2->link;
        }
        temp2->link = head;
        count--;
    }
}
//Time complexity is O(n)

//Function for deletion at position
void circular::delete_position(){
    int pos;
    cout << "Enter the position to delete:";
    cin >> pos;
    if(pos <= 0 || pos > count){
        cout << "Position entered exceeds Limits\nPlease Try again" << endl;
    }else if(pos == 1){
        delete_beginning();
    }else if(pos == count){
        delete_end();
    }else{
        struct node *temp = head;
        struct node *prev = nullptr;
        for(int i = 1; i < pos; i++){
            prev = temp;
            temp = temp->link;
        }
        prev->link = temp->link;
        temp->link = nullptr;
        free(temp);
        count--;
    }
}
//Time complexity is O(n)


//Function for displaying the linked list
void circular::display(){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp = head;
    int tcount = count;
    cout << "Circular List";
    while(temp ->link != nullptr && tcount--){
        cout << " -> " << temp->data ;
        temp = temp ->link; 
    }
}
//time complexity for the display is O(n)


//Function for searching
void circular::search() {
    if (head == nullptr) {  
        cout << "List is empty!" << endl;
        return;
    }

    struct node *temp = head;
    int value;
    cout << "Enter the value to search: ";
    cin >> value;

    while (true) {
        if (temp->data == value) {  
            cout << "Element found in the list!!" << endl;
            return;
        }
        temp = temp->link;

        if (temp == head)
            break;
    }

    cout << "Element not found in the list!!" << endl;
}
//time complexity is O(n)