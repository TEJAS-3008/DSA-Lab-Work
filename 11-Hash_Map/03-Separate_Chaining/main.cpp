#include<iostream>
#include<vector>
using namespace std;

#define SIZE 10


class hashtable{
    private:

        struct slot{
            vector<int> v;
        };

        slot table[SIZE];
        
        int hashfunction(int key){
            return key % SIZE;
        }

    public:
        void insert(int key);
        void display();
        void search(int key);
        void remove(int key);
};




int main(){
    int choice;
    int value;
    hashtable obj;

    while(1){
        cout << "\n<====== MENU ======>" << endl;
        cout << "1.Insert" << endl;
        cout << "2.Delete" << endl;
        cout << "3.Search" << endl;
        cout << "4.Display" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter the value for insertion: ";
                cin >> value;
                obj.insert(value);
                break;
            case 2:
                cout << "Enter the value to delete: ";
                cin >> value;
                obj.remove(value);
                break;
            case 3:
                cout << "Enter the value to search: ";
                cin >> value;
                obj.search(value);
                break;
            case 4:
                obj.display();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Selected choice cease to Exist\nPlease Try Again" << endl;
        }
    }
}




void hashtable::insert(int key){
    int index = hashfunction(key);
    table[index].v.push_back(key);
    cout << "Inserted element " << key << endl;
}


void hashtable::display(){
    for(int i = 0;i < SIZE;i++){
        cout << i;
        for(int each : table[i].v){
            cout << " ---> " << each;
        }
        cout << endl;
    }
}


void hashtable::search(int key){
    int index = hashfunction(key);
    for(int i = 0;i < table[index].v.size() - 1;i++){
        if(table[index].v[i] == key){
            cout << "Element found at chain " << index << " at index " << i + 1 << endl;
            return; 
        }
    }

    cout << "Element not found in any chains !!" << endl;
}


void hashtable::remove(int key){
    int chain = hashfunction(key);
    int chainsize = table[chain].v.size();
    int keyindex = -1;

    for(int i = 0;i < chainsize;i++){
        if(table[chain].v[i] == key){
            keyindex = i;
            break;
        }
    }

    if(keyindex == -1){
        cout << "The Element is not in the hashtable" << endl;
        return;
    }else{
        for(int i = keyindex;i < chainsize - 1;i++){
            table[chain].v[i] = table[chain].v[i + 1];
        }

        table[chain].v.erase(table[chain].v.end() - 1);
    }
}