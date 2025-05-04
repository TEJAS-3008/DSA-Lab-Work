/*Write a C++ menu-driven program to determine whether a number is a Palindrome, Armstrong, or Perfect Number. Normal variable and array declarations are not allowed. Utilize dynamic memory allocation (DMA). Design proper functions, maintain boundary conditions, and follow coding best practices. The menu is as follows,

a. Palindrome
b. Armstrong Number
c. Perfect Number
d. Exit

files to be submitted in pointer cpp file*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// Function prototypes
void check_Palindrome(int* num);
void check_Armstrong(int* num);
void check_Perfect(int* num);
int count_digits(int* num);

int main() {
    // Dynamically allocating memory for number input
    int* number = (int*)malloc(sizeof(int));

    if (!number) {
        cout << "Memory allocation failed!" << endl;
        return 1;
    }

    cout << "Enter the number: ";
    cin >> *number;

    int* selection = (int*)malloc(sizeof(int));

    if (!selection) {
        cout << "Memory allocation failed!" << endl;
        free(number);
        return 1;
    }

    while (true) {
        cout << "\n<===== MENU =====>\n";
        cout << "1. Palindrome\n";
        cout << "2. Armstrong Number\n";
        cout << "3. Perfect Number\n";
        cout << "4. Exit\n";
        cout << "Select a choice: ";
        cin >> *selection;
        cout << endl;

        switch (*selection) {
            case 1:
                check_Palindrome(number);
                break;
            case 2:
                check_Armstrong(number);
                break;
            case 3:
                check_Perfect(number);
                break;
            case 4:
                cout << "Exiting program.\n";
                free(number);
                free(selection);
                return 0;
            default:
                cout << "Selected option does not exist!!\nPlease Try Again\n";
        }
    }
}

// Function to check if a number is a palindrome
void check_Palindrome(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* reversed_num = (int*)malloc(sizeof(int));
    int* digit = (int*)malloc(sizeof(int));

    if (!original || !reversed_num || !digit) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    *original = *num;
    *reversed_num = 0;
    
    while (*num > 0) {
        *digit = (*num) % 10;
        *reversed_num = (*reversed_num) * 10 + (*digit);
        *num /= 10;
    }

    if (*reversed_num == *original) {
        cout << *original << " is a Palindrome" << endl;
    } else {
        cout << *original << " is not a Palindrome" << endl;
    }

    free(original);
    free(reversed_num);
    free(digit);
}

// Function to check if a number is an Armstrong number
void check_Armstrong(int* num) {
    int* original = (int*)malloc(sizeof(int));
    int* sum = (int*)malloc(sizeof(int));
    int* digit = (int*)malloc(sizeof(int));

    if (!original || !sum || !digit) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    *original = *num;
    *sum = 0;
    int* count = (int*)malloc(sizeof(int));
    *count = count_digits(num);

    int* temp = (int*)malloc(sizeof(int));
    *temp = *num;

    while (*temp > 0) {
        *digit = *temp % 10;
        *sum += pow(*digit, *count);
        *temp /= 10;
    }

    if (*sum == *original) {
        cout << *original << " is an Armstrong number" << endl;
    } else {
        cout << *original << " is not an Armstrong number" << endl;
    }

    free(original);
    free(sum);
    free(digit);
    free(count);
    free(temp);
}

// Function to check if a number is a perfect number
void check_Perfect(int* num) {
    int* sum = (int*)malloc(sizeof(int));
    int* i = (int*)malloc(sizeof(int));

    if (!sum || !i) {
        cout << "Memory allocation failed!" << endl;
        return;
    }

    *sum = 0;
    *i = 1;

    while (*i < *num) {
        if (*num % *i == 0) {
            *sum += *i;
        }
        (*i)++;
    }

    if (*sum == *num) {
        cout << *num << " is a Perfect number" << endl;
    } else {
        cout << *num << " is not a Perfect number" << endl;
    }

    free(sum);
    free(i);
}

// Function to count the number of digits in a number
int count_digits(int* num) {
    int* count = (int*)malloc(sizeof(int));
    int* temp = (int*)malloc(sizeof(int));

    if (!count || !temp) {
        cout << "Memory allocation failed!" << endl;
        return 0;
    }

    *count = 0;
    *temp = *num;

    while (*temp > 0) {
        (*count)++;
        *temp /= 10;
    }

    int result = *count;
    free(count);
    free(temp);
    return result;
}
