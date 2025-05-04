/*C. Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations,

Insert

Preorder

Inorder

Postorder

Search

Exit

What is the time complexity of each of the operations? (K4)*/


#include<iostream>
using namespace std;


class tree{
    private:
        struct node{
            int data;
            node* left;
            node* right;
        }*root = nullptr;

        node* insert(node* newroot, int value);
        node* createnewnode(int val);
        void preorder(node* current);
        void inorder(node* current);
        void postorder(node* current);
        
    public:
        tree(){
            root = nullptr;
        }
        void inserthelper(int val);
        void preorderhelper();
        void inorderhelper();
        void postorderhelper();
        void search(int value);


};




int main(){
    tree adt;
    int choice;
    while(1){
        cout << "\n<===== MENU =====>" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Preorder" << endl;
        cout << "3.Inorder" << endl;
        cout << "4.Postorder" << endl;
        cout << "5.Search" << endl;
        cout << "6.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                int value;
                cout << "Enter the value to insert: ";
                cin >> value;
                adt.inserthelper(value);
                break;
            case 2:
                adt.preorderhelper();
                break;
            case 3:
                adt.inorderhelper();
                break;
            case 4:
                adt.postorderhelper();
                break;
            case 5:
                int v;
                cout << "Enter the value you want to search: ";
                cin >> v;
                adt.search(v);
                break;
            case 6:
                cout << "Exiting...." << endl;
                return 0;
            default:
                cout << "The selected choice cease to Exist\nPlease Try Again" << endl;
        }
    }
}




tree::node* tree::insert(node* newroot, int value){
    if(newroot == nullptr){
        newroot = createnewnode(value);
        return newroot;
    }


    if(value < newroot->data){
        newroot->left = insert(newroot->left, value);
    }else{
        newroot->right = insert(newroot->right, value);
    }

    return newroot;
}

void tree::inserthelper(int val){
    root = insert(root, val);
}


tree::node* tree::createnewnode(int val){
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = val;
    newnode->left = newnode->right = nullptr;
    return newnode;
}


void tree::preorder(node* current){
    if(current != nullptr){
        cout << current->data << " ";
        preorder(current->left);
        preorder(current->right);
    }
}

void tree::preorderhelper(){
    cout << "Preorder Traversal: ";
    preorder(root);
    cout << endl;
}

void tree::inorder(node* current){
    if(current != nullptr){
        inorder(current->left);
        cout << current->data << " ";
        inorder(current->right);
    }
}

void tree::inorderhelper(){
    cout << "Inorder Traversal: ";
    inorder(root);
    cout << endl;
}


void tree::postorder(node* current){
    if(current != nullptr){
        postorder(current->left);
        postorder(current->right);
        cout << current->data << " ";
    }
}



void tree::postorderhelper(){
    cout << "Postorder Traversal: ";
    postorder(root);
    cout << endl;
}


void tree::search(int value){
    struct node* temp = root;
    int flag = 0;
    while(temp != nullptr){
        if(value == temp->data){
            flag = 1;
            break;
        }else{
            if(value < temp->data){
                temp = temp->left;
            }else if(value > temp->data){
                temp = temp->right;
            }
        }
    }

    if(flag){
        cout << value << " is found in the tree" << endl;
    }else{
        cout << value << " is not found in the tree" << endl;
    }

}