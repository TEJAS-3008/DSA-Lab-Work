/* menu-driven C++ program to implement a Hash ADT using Linear Probing, followed by the time complexity analysis of each operation.
with operations:
    1.Insert
    2.Delete
    3.Search
    4.Display
    5.Exit*/


    #include<iostream>
    #include<vector>
    using namespace std;
    
    const int SIZE = 10;
    
    
    
    class hashtable{
        private:
            struct slot{
                int value;
                bool isoccupied;
                bool isdeleted;
            };
    
            slot table[SIZE];
    
            int hashfunction(int key){
                return key % SIZE;
            }
    
        public:
            hashtable(){
                for(int i = 0;i < SIZE;i++){
                    table[i].isoccupied = false;
                    table[i].isdeleted = false;
                }
            }
    
            void insert(int val);
            void display();
            void remove(int key);
            void search(int key);
    
    };
    
    
    
    
    int main(){
        int choice;
        int val;
        hashtable obj;
        while(1){
            cout << "\n<======== MENU ========>" << endl;
            cout << "1.Insert " << endl;
            cout << "2.Delete" << endl;
            cout << "3.Search" << endl;
            cout << "4.Display" << endl;
            cout << "5.Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;
            switch(choice){
                case 1:
                    cout << "Enter a value to insert: ";
                    cin >> val;
                    obj.insert(val);
                    break;
                case 2:
                    cout << "Enter a value to remove: ";
                    cin >> val;
                    obj.remove(val);
                    break;
                case 3:
                    cout << "Enter the value to search: ";
                    cin >> val;
                    obj.search(val);
                    break;
                case 4:
                    obj.display();
                    break;
                case 5:
                    cout << "Exiting...." << endl;
                    return 0;
                default:
                    cout << "Selected choice cease to exist\nPlease Try Again" << endl;
            }
        }
    }
    
    
    
    void hashtable::insert(int key){
        int index = hashfunction(key);
        int start = index;
        while(table[index].isoccupied || table[index].isdeleted){
            index = (index + 1) % SIZE;
            if(index == start){
                cout << "The hash table is full" << endl;
                return;
            }
        }
        table[index].value = key;
        table[index].isoccupied = true;
        table[index].isdeleted = false;
        cout << "Inserted " << key << " at index " << index << endl;
    }
    
    
    void hashtable::display(){
        cout << "Hashtable: " << endl;
        for(int i = 0;i < SIZE;i++){
            if(table[i].isoccupied == true && table[i].isdeleted == false){
                cout << i << " ---> " << table[i].value << endl;
            }else{
                cout << i << " ---> " << endl;
            }
        }
    }
    
    void hashtable::remove(int key){
        int index = hashfunction(key);
        int start = index;
    
        while(table[index].isdeleted || table[index].isoccupied){
            if(key == table[index].value){
                table[index].isoccupied = false;
                table[index].isdeleted = true;
                cout << "Deleted" << key << " at index " << index << endl;
                return;
            }
            index = (index + 1)%SIZE;
            if(index == start){
                cout << "The hashtable is Empty" << endl;
                return;
            }
        }
    }
    
    
    void hashtable::search(int key){
        int index = hashfunction(key);
        int start = index;
    
        while(table[index].isoccupied == true){
            if(key == table[index].value){
                cout << "Found Element " << key << " at index " << index << endl;
                return; 
            }
            index = (index + 1)%SIZE;
            if(index == start){
                break;
            }
        }
        cout << "The element " << key << " not found !" << endl; 
    }