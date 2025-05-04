/*
1. Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions, maintain boundary conditions and follow coding best practices. The menus are as follows:

a. Bubble Sort
b. Selection Sort
c. Insertion Sort
d. Exit

*/


#include <iostream>
#include <vector>
using namespace std;

//function prototypes
void display(const vector<int>& arr);
void bubblesort(vector<int>& arr);
void selectionsort(vector<int>& arr);
void insertionsort(vector<int>& arr);
void ExitMenu();


int main(){
    vector<int> arr;
    int size;
    int choice;

    cout << "Enter the size of the array:";
    cin >> size;
    for(int i = 0; i < size; i++){
        int element;
        cout << "enter element no " << i + 1 << ":" << endl;
        cin >> element;
        arr.push_back(element);
    }
    
    while(1){
        //defining the menu
        cout << "<===== MENU =====>" << endl;
        cout << "1.Bubblesort the array" << endl;
        cout << "2.Selection sort the array" << endl;
        cout << "3.Insertion sort the array" << endl;
        cout << "4.Exit Menu" << endl;
        cout << "\n";
        cout << "select your options in menu within 1 to 4:" << endl;
        cin >> choice;
        cout << endl;
        switch(choice){
            case 1:
                bubblesort(arr);
                break;
            case 2:
                selectionsort(arr);
                break;
            case 3:
                insertionsort(arr);
                break;
            case 4:
                ExitMenu();
                return 0;
            default:
                cout << "Selected option not in the menu!!\nPLEASE try again!\n\n" << endl;
        }
    }
    
}

//defining the functions

void display(const vector<int>& arr){

    cout << "SORTED ARRAY: | ";
    for(int num : arr){
        cout << num << " | ";
    }
    cout << endl;
}

void bubblesort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(arr[j] > arr[j + 1]){
                int temp;
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    display(arr);
}

void selectionsort(vector<int>& arr){
    int n = arr.size();
    for(int i = 0; i < n - 1; i++){
        int minindex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minindex]){
                minindex = j;
            }
        }
        int temp;
        temp = arr[i];
        arr[i] = arr[minindex];
        arr[minindex] = temp;
    }

    display(arr);
}

void insertionsort(vector<int>& arr){
    int n = arr.size();
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    display(arr);
}



void ExitMenu(){
    cout << "Menu Exited!!" << endl;
}
