//program to search a element in an array
#include "head.h"
#include <cstdio>


void linearsearch(int arr[], int num, int num2);
int binarySearch(int arr[], int num, int key);

int main() {
    int num, element, num2, choice;

    printf("Enter the number of elements: ");
    scanf("%d", &num);

    int arr[num], arr2[num];
    printf("Enter the elements: ");
    for (int i = 0; i < num; i++) {
        scanf("%d", &element);
        arr[i] = element;
        arr2[i] = element;
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &num2);

    while (1) {
        printf("\n           MENU\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Display Array\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearsearch(arr, num, num2);
                break;
            case 2: {
                int position = binarySearch(arr, num, num2);
                if (position != -1) {
                    printf("The element %d is FOUND at position %d\n", num2, position+1);
                } else {
                    printf("The element %d is NOT FOUND\n", num2);
                }
                break;
            }
            case 3:
                 printf("The Sorted Array is : ");
                    for (int i = 0; i<num; i++)
                        {
                            printf("%d  ",arr2[i]);
                        }
                break;
            case 4:
                return 0;
            default:
                printf("INVALID CHOICE. Please try again.\n");
        }
    }
}

void linearsearch(int arr[], int num, int num2) {
    int found = 0;
    for (int i = 0; i < num; i++) {
        if (num2 == arr[i]) {
            printf("The element %d is FOUND at position %d\n", num2, i+1);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("The element %d is NOT FOUND\n", num2);
    }
}

int binarySearch(int arr[], int num, int key) {
    Bubblesort(arr, num);  
    int left = 0, right = num - 1;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (arr[mid] == key) {
            return mid;  
        }   
        if (arr[mid] < key) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;  
}
