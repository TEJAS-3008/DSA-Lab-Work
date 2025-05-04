//Implementation of List ADT using an array of size 5
#include <cstdio>
#include <cstdlib>

class LIST {
private:
    int arr[5]; 
    int current;

public:
    LIST() { current = -1; } 

    void display();
    void insbeg();
    void inspos(int);
    void insend();
    void delbeg();
    void delpos(int);
    void delend();
    int search(int);
    void rotate_v1(int);
    void rotate_v2(int);
    void rotate_v3(int);
};

int main() {
    int choice;
    LIST arr;

    while (true) {
        printf("\n           MENU\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete at Position\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Rotate\n");
        printf("10. Exit\n");
        printf("\nENTER YOUR CHOICE: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                arr.insbeg();
                break;
            case 2:
                arr.insend();
                break;
            case 3: {
                int pos;
                printf("Enter the Position: ");
                scanf("%d", &pos);
                arr.inspos(pos);
                break;
            }
            case 4:
                arr.delbeg();
                break;
            case 5:
                arr.delend();
                break;
            case 6: {
                int pos;
                printf("Enter the Position: ");
                scanf("%d", &pos);
                arr.delpos(pos);
                break;
            }
            case 7: {
                int num;
                printf("Enter the Element: ");
                scanf("%d", &num);
                arr.search(num);
                break;
            }
            case 8:
                arr.display();
                break;
            case 9: {
                int rotations, choi;
                printf("Enter Number of Rotations: ");
                scanf("%d", &rotations);
                printf("If You Want to Do it in 3 different Methods 1 enter 1, Method 2 enter 2, Method 3 enter 3: ");
                scanf("%d", &choi);
                if (choi == 1) {
                    arr.rotate_v1(rotations);
                } else if (choi == 2) {
                    arr.rotate_v2(rotations);
                } else if (choi == 3) {
                    arr.rotate_v3(rotations);
                } else {
                    printf("Invalid");
                }
                break;
            }
            case 10:
                return 0;
            default:
                printf("Invalid Choice! Try again.\n");
        }
    }
}

void LIST::display() {
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    printf("\nThe List is: ");
    for (int i = 0; i <= current; i++) { // Loop to print elements
        printf("%d  ", arr[i]);
    }
    printf("\n");
}

void LIST::insbeg() {
    if (current == 4) {
        printf("The List is Full\n");
        return;
    }

    int temp;
    printf("Enter The Element: ");
    scanf("%d", &temp);

    // Shifting elements to the right to make space at the beginning
    for (int i = current; i >= 0; i--) {
        arr[i + 1] = arr[i];
    }

    arr[0] = temp;
    current++;
}

void LIST::inspos(int pos) {
    if (pos < 0 || pos > current + 1) {
        printf("Invalid Position!\n");
        return;
    }
    if (current == 4) {
        printf("The List is Full\n");
        return;
    }

    int temp;
    printf("Enter The Element: ");
    scanf("%d", &temp);

    // Shift elements right to make space for the new element
    for (int i = current; i >= pos; i--) {
        arr[i + 1] = arr[i];
    }

    arr[pos] = temp;
    current++;
}

void LIST::insend() {
    if (current == 4) {
        printf("The List is Full\n");
        return;
    }

    int temp;
    printf("Enter The Element: ");
    scanf("%d", &temp);

    arr[current + 1] = temp;
    current++;
}

void LIST::delbeg() {
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    for (int i = 0; i < current; i++) {
        arr[i] = arr[i + 1];
    }

    current--;
}

void LIST::delpos(int pos) {
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    if (pos < 0 || pos > current) {
        printf("Invalid Position!\n");
        return;
    }

    // Shift elements left to remove element at given position
    for (int i = pos; i < current; i++) {
        arr[i] = arr[i + 1];
    }

    current--;
}

void LIST::delend() {
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }

    current--; 
}

int LIST::search(int num) {
    for (int i = 0; i <= current; i++) { // Loop to search element
        if (arr[i] == num) {
            printf("The Element '%d' is found at Position '%d'\n", num, i);
            return 1;
        }
    }

    printf("Element not found in the list.\n");
    return 0;
}

void LIST::rotate_v1(int num) {
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    num = num % (current + 1); // Prevent unnecessary rotations
    if (num == 0) return;

    // Rotate right 'num' times
    for (int r = 0; r < num; r++) {
        int temp = arr[current];
        for (int i = current; i > 0; i--) {
            arr[i] = arr[i - 1];
        }
        arr[0] = temp;
    }
}

void LIST::rotate_v2(int num) { 
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    
    num = num % (current + 1);
    if (num == 0) return;
    
    int temp[5];

    // Compute new positions and store in temp
    for (int i = 0; i <= current; i++) {
        temp[(i + num) % (current + 1)] = arr[i];
    }

    // Copy temp back to original array
    for (int i = 0; i <= current; i++) {
        arr[i] = temp[i];
    }
}

void LIST::rotate_v3(int num) { 
    if (current == -1) {
        printf("The List is Empty\n");
        return;
    }
    num = num % (current + 1);
    if (num == 0) return;
    
    // Rotate left 'num' times
    for (int i = 0; i < num; i++) {
        int temp = arr[0];
        for (int j = 0; j < current; j++) {
            arr[j] = arr[j + 1];
        }
        arr[current] = temp;
    }
}
