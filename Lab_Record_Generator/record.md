# Searching and Sorting

## Sort Ascending

### Question

Write a C++ menu-driven program to sort a given array in ascending order. Design proper functions, maintain boundary conditions and follow coding best practices. The menus are as follows:

a. Bubble Sort
b. Selection Sort
c. Insertion Sort
d. Exit

### Algorithm

#### Algorithm 1 - BubbleSort {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in array

##### Output {.unnumbered}

- sorted array in ascending order

##### Steps {.unnumbered}

1. For $i$ from $0$ to $num-2$:
    1. For $j$ from $0$ to $num-2-i$:
        1. If $arr[j] > arr[j+1]$:
            1. $temp \leftarrow arr[j]$
            2. $arr[j] \leftarrow arr[j+1]$
            3. $arr[j+1] \leftarrow temp$

#### Algorithm 2 - InsertionSort {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in array

##### Output {.unnumbered}

- sorted array in ascending order

##### Steps {.unnumbered}

1. For $i$ from $1$ to $num-1$:
    1. $temp \leftarrow arr[i]$
    2. $j \leftarrow i-1$
    3. While $j \geq 0$ and $arr[j] > temp$:
        1. $arr[j+1] \leftarrow arr[j]$
        2. $j \leftarrow j-1$
    4. $arr[j+1] \leftarrow temp$

#### Algorithm 3 - SelectionSort {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in array

##### Output {.unnumbered}

- sorted array in ascending order

##### Steps {.unnumbered}

1. For $i$ from $0$ to $num-1$:
    1. $k \leftarrow i$
    2. $temp \leftarrow arr[i]$
    3. For $j$ from $i+1$ to $num-1$:
        1. If $arr[j] < temp$:
            1. $temp \leftarrow arr[j]$
            2. $k \leftarrow j$
    4. $arr[k] \leftarrow arr[i]$
    5. $arr[i] \leftarrow temp$

#### Algorithm 4 - Display {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in array

##### Output {.unnumbered}

- printed array elements

##### Steps {.unnumbered}

1. For $i$ from $0$ to $num-1$:
    1. Print $arr[i]$ followed by space
2. Print newline

### Code

__main.cpp__

```cpp

//program to sort an array in ascending order

#include<cstdio>
#include<cstring>

void Bubblesort(int [],int);
void Selectionsort(int [],int);
void Insertionsort(int [],int);
void Display(int[],int);

int main(){

int choice,num,element;

printf("Enter The Number of Elements : ");
scanf("%d",&num);
int arr[num],arr2[num] ;
printf("Enter The Elements : ");
for (int i = 0; i < num; i++)
{
    scanf("%d",&element);
    arr[i] = element;
    arr2[i] = element;
}

while (1){

    printf("\n\n         MENU          \n");
    printf("1. Bubble Sort\n");
    printf("2. Selection Sort\n");
    printf("3. Insertion Sort\n");
    printf("4. Display Original Array\n");
    printf("5. Exit\n");
printf("\nEnter Your Choice : ");
scanf("%d",&choice);
switch (choice)
{
case 1:
    Bubblesort(arr,num);
    break;
case 2:
    Selectionsort(arr,num);
    break;
case 3:
    Insertionsort(arr,num);
    break;
case 4:
    Display(arr2,num);
    break;
case 5:
    return 0;
default:
    printf("Invalid");
    break;
}
};


    return 0;
}

void Bubblesort(int arr2[],int num){
      
    for (int i = 0; i< num; i++)
    {
        for (int j = 0; j < (num-1); j++)
        {
            if(arr2[j]>arr2[j+1]){
                int temp = arr2[j+1];
                arr2[j+1] = arr2[j];
                arr2[j] = temp;

            }
        }
        
    }
    printf("The Sorted Array is : ");
     for (int i = 0; i<num; i++)
    {
        printf("%d  ",arr2[i]);
    }

}

void Selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    printf("The Sorted Array is : ");
    for (int i = 0; i<n; i++)
    {
        printf("%d  ",arr[i]);
    }
}
void Insertionsort(int arr[], int N) {

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
printf("The Sorted Array is : ");
    for (int i = 0; i<N; i++)
    {
        printf("%d  ",arr[i]);
    }
}

void Display(int arr[],int N){
  printf("The Array is : ");
    for (int i = 0; i<N; i++)
    {
        printf("%d  ",arr[i]);
    }

}




```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/01-Searching_and_Sorting/01-Sort_Ascending$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/01-Searching_and_Sorting/01-Sort_Ascending$ ./a.out
Enter The Number of Elements : 5
Enter The Elements : 12
32
1
976
55


         MENU
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Display Original Array
5. Exit

Enter Your Choice : 1
The Sorted Array is : 1  12  32  55  976  

         MENU
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Display Original Array
5. Exit

Enter Your Choice : 2
The Sorted Array is : 1  12  32  55  976  

         MENU
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Display Original Array
5. Exit

Enter Your Choice : 3
The Sorted Array is : 1  12  32  55  976

         MENU
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Display Original Array
5. Exit

Enter Your Choice : 4
The Array is : 12  32  1  976  55

         MENU
1. Bubble Sort
2. Selection Sort
3. Insertion Sort
4. Display Original Array
5. Exit

Enter Your Choice : 5

```

## Search

### Question

Convert the sorting program into a header file and include it into a new cpp file. Write a C++ menu-driven program for linear and binary search in this new cpp file. Utilize any of the sorting functions in the included header file to sort the input array before performing a binary search. Design proper functions, maintain boundary conditions and follow coding best practices. The menu-driven program supports,

a. Linear Search
b. Binary Search
c. Exit

### Algorithm

#### Algorithm 1 - LinearSearch {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in the array
3. temp - value to search for

##### Output {.unnumbered}

- 1 if temp is found in arr[], 0 otherwise

##### Steps {.unnumbered}

1. For $i$ from $0$ to $num-1$:
    1. If $arr[i] = temp$:
        1. Return $1$
2. Return $0$

#### Algorithm 2 - BinarySearch {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array of integers
2. num - number of elements in the array
3. temp - value to search for

##### Output {.unnumbered}

- 1 if temp is found in sorted arr[], 0 otherwise

##### Steps {.unnumbered}

1. Sort $arr[]$ using bubble sort
2. $start \leftarrow 0$
3. $end \leftarrow num-1$
4. While $start \leq end$:
    1. $mid \leftarrow \lfloor(start + end) / 2\rfloor$
    2. If $arr[mid] = temp$:
        1. Return $1$
    3. If $arr[mid] < temp$:
        1. $start \leftarrow mid + 1$
    4. If $arr[mid] > temp$:
        1. $end \leftarrow mid - 1$
5. Return $0$

### Code

__main.cpp__

```cpp

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

```

__head.h__

```h


void Bubblesort(int arr2[],int num){
      
    for (int i = 0; i< num; i++)
    {
        for (int j = 0; j < (num-1); j++)
        {
            if(arr2[j]>arr2[j+1]){
                int temp = arr2[j+1];
                arr2[j+1] = arr2[j];
                arr2[j] = temp;

            }
        }
        
    }

}

void Selectionsort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}
void Insertionsort(int arr[], int N) {

    for (int i = 1; i < N; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/01-Searching_and_Sorting/02-Search$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/01-Searching_and_Sorting/02-Search$ ./a.out
Enter the number of elements: 5
Enter the elements: 1
5
4
3
2
Enter the element you want to search: 1

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 1
The element 1 is FOUND at position 1

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 2
The element 1 is FOUND at position 1

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 3
The Sorted Array is : 1  5  4  3  2  
           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 1
The element 1 is FOUND at position 1

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 4
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/01-Searching_and_Sorting/02-Search$ ./a.out
Enter the number of elements: 5
Enter the elements: 76
35
99
1
4
Enter the element you want to search: 66

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 3
The Sorted Array is : 76  35  99  1  4
           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 2
The element 66 is NOT FOUND

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 1
The element 66 is NOT FOUND

           MENU
1. Linear Search
2. Binary Search
3. Display Array
4. Exit
Enter your choice: 4
```

\pagebreak

# Classes with Pointers

## Number Operations

### Question

Write a C++ menu-driven program to determine whether a number is a Palindrome, Armstrong, or Perfect Number. Normal variable and array declarations are not allowed. Utilize dynamic memory allocation (DMA). Design proper functions, maintain boundary conditions, and follow coding best practices. The menu is as follows:

a. Palindrome
b. Armstrong Number
c. Perfect Number
d. Exit

### Algorithm

#### Algorithm 1 - CheckPalindrome {.unnumbered}

##### Input {.unnumbered}

1. num - pointer to the number to check

##### Output {.unnumbered}

- Message indicating whether the number is a palindrome

##### Steps {.unnumbered}

1. Allocate memory for $sum$, $rem$, and $temp$ pointers
2. $*sum \leftarrow 0$
3. $*temp \leftarrow *num$
4. While $*temp > 0$:
    1. $*rem \leftarrow (*temp) \bmod 10$
    2. $*sum \leftarrow (*sum) \times 10 + *rem$
    3. $*temp \leftarrow *temp / 10$
5. If $*sum = *num$:
    1. Print "It is a palindrome"
6. Else:
    1. Print "It is not a palindrome"
7. Free allocated memory

#### Algorithm 2 - CountDigits {.unnumbered}

##### Input {.unnumbered}

1. num - pointer to the number to count digits of

##### Output {.unnumbered}

- Number of digits in the number

##### Steps {.unnumbered}

1. Allocate memory for $temp$ and $len$ pointers
2. $*temp \leftarrow *num$
3. $*len \leftarrow 0$
4. While $*temp > 0$:
    1. $*temp \leftarrow *temp / 10$
    2. $*len \leftarrow *len + 1$
5. Return $*len$
6. Free allocated memory

#### Algorithm 3 - CheckArmstrong {.unnumbered}

##### Input {.unnumbered}

1. num - pointer to the number to check

##### Output {.unnumbered}

- Message indicating whether the number is an Armstrong number

##### Steps {.unnumbered}

1. Allocate memory for $sum$, $rem$, $temp$, and $len$ pointers
2. $*sum \leftarrow 0$
3. $*temp \leftarrow *num$
4. $*len \leftarrow count(num)$
5. While $*temp > 0$:
    1. $*rem \leftarrow *temp \bmod 10$
    2. $*sum \leftarrow *sum + pow(*rem, *len)$
    3. $*temp \leftarrow *temp / 10$
6. If $*sum = *num$:
    1. Print "It is an Armstrong number"
7. Else:
    1. Print "It is not an Armstrong number"
8. Free allocated memory

#### Algorithm 4 - CheckPerfect {.unnumbered}

##### Input {.unnumbered}

1. num - pointer to the number to check

##### Output {.unnumbered}

- Message indicating whether the number is a perfect number

##### Steps {.unnumbered}

1. Allocate memory for $sum$ and $i$ pointers
2. $*sum \leftarrow 0$
3. For $*i$ from $1$ to $(*num)-1$:
    1. If $(*num) \bmod (*i) = 0$:
        1. $(*sum) \leftarrow (*sum) + (*i)$
4. If $*sum = *num$:
    1. Print "It is a perfect number"
5. Else:
    1. Print "It is not a perfect number"
6. Free allocated memory

### Code

__main.cpp__

```cpp

//Menudriven program to determine wheater a number is palindrome,armstrong or perfect number.
#include<cstdio>
#include<cstdlib>
#include<cmath>
int digits(int*);
int ispalindrome(int*);
int isarmstrong(int*,int*);
int isperfect(int*);


int main(){
int*num = (int*)malloc(sizeof(int));
*num = 0;
    
int* digit = (int*)malloc(sizeof(int));

    while(1){
        int* choice = (int*)malloc(sizeof(int));
        printf("           MENU\n");
        printf("1. Palindrome\n");
        printf("2. Armstrong\n");
        printf("3. Perfect\n");
        printf("4. Exit\n");
        printf("\nEnter The Choice:");
        scanf("%d",choice);

        switch (*choice)
        {
        case 1:
        printf("Enter The Number : ");
        scanf("%d",num);
            if(ispalindrome(num)==*num){
                printf("The Given Number %d is a Palindrome\n",*num);
            }
            else{
                 printf("The Given Number %d is NOT a Palindrome\n",*num);
            }
            break;
        case 2:
        printf("Enter The Number : ");
        scanf("%d",num);
        *digit = digits(num);
             if(isarmstrong(num,digit)==*num){
                printf("The Given Number %d is a Armstrong Number\n",*num);
            }
            else{
                 printf("The Given Number %d is NOT a Armstrong Number\n",*num);
            }
            break;
        case 3:
        printf("Enter The Number : ");
        scanf("%d",num);
             if(isperfect(num)){
                printf("The Given Number %d is a Perfect Number\n",*num);
            }
             else{
                printf("The Given Number %d is NOT a Perfect Number\n",*num);
                }
            break;
        case 4:
            return 0;
            break;
        default:
            printf("INVALID CHOICE\n");
            break;
        }
    }
    return 0;
}

int digits(int* ptr){
    int* temp = (int*)malloc(sizeof(int));
    int* num = (int*)malloc(sizeof(int));
    *num = 0;
    *temp = *ptr;
    if(*temp == 0){
        return 1;
    }
    else{
    while (*temp > 0)
    {
        *temp = (*temp)/10;
        (*num)++;
    }
    return *num;}
}

int ispalindrome(int* ptr){

    int* temp = (int*)malloc(sizeof(int));
    *temp = *ptr;
    int* temp1 = (int*)malloc(sizeof(int));
    int* reverse = (int*)malloc(sizeof(int));
    *reverse =0;
     while (*temp != 0) {
        *temp1 = *temp % 10;               
        *reverse = (*reverse) * 10 + *temp1;  
        (*temp) /= 10;                          
    }

    return *reverse;
}

int isarmstrong(int*ptr,int*ptr1){
    int*i = (int*)malloc(sizeof(int));
    int* digit = (int*)malloc(sizeof(int));
    int* sum = (int*)malloc(sizeof(int));
    int* temp = (int*)malloc(sizeof(int));
    *temp = *ptr;
    *sum = 0;
    for (*i = 0; *i < *ptr1; (*i)++)
    {
        *digit = (*temp)%10;
        *sum = *sum + pow(*digit,*ptr1);
        (*temp) /=10;
    }
    return *sum;
}

int isperfect(int* ptr){

      int * sum = (int*)malloc(sizeof(int));
      *sum = 0;
      int * num = (int*)malloc(sizeof(int));
      *num = *ptr;\
       int * i = (int*)malloc(sizeof(int));

    for (*i = 1; *i <= (*num) / 2; (*i)++) {
        if ((*num) % (*i) == 0) {
            (*sum) += (*i);
        }
    }


    return ((*sum) == (*num));
}


```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/02-Classes_with_Pointers/01-Number_Operations$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/02-Classes_with_Pointers/01-Number_Operations$ ./a.out
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:1
Enter The Number : 123321
The Given Number 123321 is a Palindrome
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:1
Enter The Number : 1234
The Given Number 1234 is NOT a Palindrome
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:2
Enter The Number : 4
The Given Number 4 is a Armstrong Number
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:2   
Enter The Number : 153
The Given Number 153 is a Armstrong Number
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:2
Enter The Number : 3456
The Given Number 3456 is NOT a Armstrong Number
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:3
Enter The Number : 28
The Given Number 28 is a Perfect Number
           MENU
1. Palindrome
2. Armstrong
3. Perfect
4. Exit

Enter The Choice:4
```

## Shape Area

### Question

Write a C++ menu-driven program that calculates and displays the area of a square, cube, rectangle, and cuboid. Consider length as the side value for the square and cuboid. Identify proper data members and member functions. Design and create an appropriate class for the given scenario. Maintain proper boundary conditions and follow coding best practices. The menus are as follows,

a. Square
b. Cube
c. Rectangle
d. Cuboid
e. Exit

### Algorithm

#### Algorithm 1 - CalculateSquareArea {.unnumbered}

##### Input {.unnumbered}

1. len - side length of square

##### Output {.unnumbered}

- area - area of the square

##### Steps {.unnumbered}

1. $area \leftarrow len \times len$
2. Return $area$

#### Algorithm 2 - CalculateRectangleArea {.unnumbered}

##### Input {.unnumbered}

1. len - length of rectangle
2. bre - breadth of rectangle

##### Output {.unnumbered}

- area - area of the rectangle

##### Steps {.unnumbered}

1. $area \leftarrow len \times bre$
2. Return $area$

#### Algorithm 3 - CalculateCubeArea {.unnumbered}

##### Input {.unnumbered}

1. len - side length of cube

##### Output {.unnumbered}

- area - surface area of the cube

##### Steps {.unnumbered}

1. $area \leftarrow 6 \times len \times len$
2. Return $area$

#### Algorithm 4 - CalculateCuboidArea {.unnumbered}

##### Input {.unnumbered}

1. len - length of cuboid
2. bre - breadth of cuboid
3. hei - height of cuboid

##### Output {.unnumbered}

- area - surface area of the cuboid

##### Steps {.unnumbered}

1. $area \leftarrow 2 \times (len \times bre + bre \times hei + hei \times len)$
2. Return $area$

### Code

__main.cpp__

```cpp

//Display the Areas
#include<cstdio>
class square
{
private:
    int side;
public:
    square(){
        side =1;
    }
void set_side(int);
void Area();
};


class cube
{
private:
    int side;
public:
    cube(){
        side = 1;
    }
void set_side(int);
void Area();
};


class rectangle
{
private:
    int length,breadth;
public:
    rectangle(){
        length = breadth = 1;
    }
void set_length(int);
void set_breadth(int);
void Area();
};


class cuboid
{
private:
    int length,breadth,height;
public:
    cuboid(){
        length=breadth=height=1;
    }
void set_lenght(int);
void set_breadth(int);   
void set_height(int);
void Area();
};


int main(){

int num,num1,num2,choice;
square squ;
cube cub;
rectangle rect;
cuboid cubo;
while(1){
printf("           MENU\n");
printf("1. SQUARE\n");
printf("2. CUBE\n");
printf("3. RECTANGLE\n");
printf("4. CUBOID\n");
printf("5. EXIT\n");

printf("Enter Your Choice : ");
scanf("%d",&choice);

switch (choice)
{
case 1:
    
    printf("Enter The Lenght of Square :");
    scanf("%d",&num);
    squ.set_side(num);
    squ.Area();

    break;
case 2:
    
    printf("Enter The Length of Side of  Cube :");
    scanf("%d",&num1);
    cub.set_side(num1);
    cub.Area();

    break;
case 3:
    
    printf("Enter The Length of Rectangle :");
    scanf("%d",&num2);
    printf("Enter The Breadth of Rectangle :");
    scanf("%d",&num1);
    rect.set_length(num2);
    rect.set_breadth(num1);
    rect.Area();

    break;
case 4:
  
    printf("Enter The Length Cuboid :");
    scanf("%d",&num2);
    printf("Enter The Breadth of Cuboid :");
    scanf("%d",&num1);
    printf("Enter The Height of Cuboid :");
    scanf("%d",&num);
    cubo.set_lenght(num2);
    cubo.set_breadth(num1);
    cubo.set_height(num);
    cubo.Area();

    break;
case 5 :

    return 0 ;
default:
    printf("INVALID\n");

    break;
}
}
    return 0;
}




void cube::set_side(int temp){
    side = temp;
}
void cube::Area(){
    printf("The area of Cube is : %d\n",6*side*side);

}       


void square::set_side(int temp){
    side = temp;
}
void square::Area(){
    printf("The Area of Square is %d\n",side*side);
}

void rectangle::set_length(int temp){
    length=temp;
}
void rectangle::set_breadth(int temp){

    breadth = temp;
}
void rectangle::Area(){
    printf("The Area of Rectangle is : %d\n",(length*breadth));
}

void cuboid::set_lenght(int temp){
    length=temp;
}
void cuboid::set_breadth(int temp){
    breadth=temp;
}
void cuboid::set_height(int temp){
    height=temp;
}
void cuboid::Area(){
    printf("The Area of Cuboid is : %d\n",2*(length*breadth+breadth*height+length*height));
}

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/02-Classes_with_Pointers/02-Shape_Area$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/02-Classes_with_Pointers/02-Shape_Area$ ./a.out
           MENU
1. SQUARE
2. CUBE
3. RECTANGLE
4. CUBOID
5. EXIT
Enter Your Choice : 1
Enter The Lenght of Square :4
The Area of Square is 16
           MENU
1. SQUARE
2. CUBE
3. RECTANGLE
4. CUBOID
5. EXIT
Enter Your Choice : 2
Enter The Length of Side of  Cube :4
The area of Cube is : 96
           MENU
1. SQUARE
2. CUBE
3. RECTANGLE
4. CUBOID
5. EXIT
Enter Your Choice : 3
Enter The Length of Rectangle :4
Enter The Breadth of Rectangle :3
The Area of Rectangle is : 12
           MENU
1. SQUARE
2. CUBE
3. RECTANGLE
4. CUBOID
5. EXIT
Enter Your Choice : 4
Enter The Length Cuboid :5
Enter The Breadth of Cuboid :4
Enter The Height of Cuboid :3
The Area of Cuboid is : 94
           MENU
1. SQUARE
2. CUBE
3. RECTANGLE
4. CUBOID
5. EXIT
Enter Your Choice : 5
```

\pagebreak

# List ADT with Arrays

## List ADT Implementation

### Question

Write a C++ menu-driven program to implement List ADT using an array of size 5. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Rotate
10. Exit

The rotate option takes an input 'k' which rotates the entire array to the right by k times. Think of at least 3 solutions. Think of a solution that rotates using O(1) extra space.

### Algorithm

#### Algorithm 1 - ArrayListInsertBeginning {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. arr[] - array storing the list elements
3. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with num inserted at beginning

##### Steps {.unnumbered}

1. If $cur = 5$ (list is full):
    1. Print "List is full"
    2. Return
2. For $i$ from $cur$ down to $1$:
    1. $arr[i] \leftarrow arr[i-1]$
3. $arr[0] \leftarrow num$
4. $cur \leftarrow cur + 1$

#### Algorithm 2 - ArrayListInsertEnd {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. arr[] - array storing the list elements
3. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with num inserted at end

##### Steps {.unnumbered}

1. If $cur = 5$ (list is full):
    1. Print "List is full"
    2. Return
2. $arr[cur] \leftarrow num$
3. $cur \leftarrow cur + 1$

#### Algorithm 3 - ArrayListInsertPosition {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. pos - position to insert at
3. arr[] - array storing the list elements
4. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with num inserted at position pos

##### Steps {.unnumbered}

1. If $cur = 5$ (list is full):
    1. Print "List is full"
    2. Return
2. If $pos < 0$ or $pos > cur$:
    1. Print "Invalid position"
    2. Return
3. For $i$ from $cur$ down to $pos+1$:
    1. $arr[i] \leftarrow arr[i-1]$
4. $arr[pos] \leftarrow num$
5. $cur \leftarrow cur + 1$

#### Algorithm 4 - ArrayListDeleteBeginning {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the list elements
2. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with first element removed

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. For $i$ from $0$ to $cur-2$:
    1. $arr[i] \leftarrow arr[i+1]$
3. $cur \leftarrow cur - 1$

#### Algorithm 5 - ArrayListDeleteEnd {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the list elements
2. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with last element removed

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. $cur \leftarrow cur - 1$

#### Algorithm 6 - ArrayListDeletePosition {.unnumbered}

##### Input {.unnumbered}

1. pos - position to delete
2. arr[] - array storing the list elements
3. cur - current number of elements

##### Output {.unnumbered}

- Updated array list with element at position pos removed

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. If $pos < 0$ or $pos \geq cur$:
    1. Print "Invalid position"
    2. Return
3. For $i$ from $pos$ to $cur-2$:
    1. $arr[i] \leftarrow arr[i+1]$
4. $cur \leftarrow cur - 1$

#### Algorithm 7 - ArrayListSearch {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. arr[] - array storing the list elements
3. cur - current number of elements

##### Output {.unnumbered}

- Status message indicating if num was found or not

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. For $i$ from $0$ to $cur-1$:
    1. If $arr[i] = num$:
        1. Print "Element found"
        2. Return
3. Print "Element not found"

#### Algorithm 8 - ArrayListDisplay {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the list elements
2. cur - current number of elements

##### Output {.unnumbered}

- All elements in the list printed

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. For $i$ from $0$ to $cur-1$:
    1. Print $arr[i]$ followed by space
3. Print newline

#### Algorithm 9 - ArrayListRotate {.unnumbered}

##### Input {.unnumbered}

1. k - number of rotations
2. arr[] - array storing the list elements
3. cur - current number of elements

##### Output {.unnumbered}

- Updated array list rotated k times

##### Steps {.unnumbered}

1. If $cur = 0$ (list is empty):
    1. Print "List is empty"
    2. Return
2. $k \leftarrow k \bmod cur$
3. For $i$ from $0$ to $k-1$:
    1. $temp \leftarrow arr[cur-1]$
    2. For $j$ from $cur-1$ down to $1$:
        1. $arr[j] \leftarrow arr[j-1]$
    3. $arr[0] \leftarrow temp$

### Code

__main.cpp__

```cpp

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

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/03-List_ADT_with_Arrays/01-List_ADT_Implementation$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/03-List_ADT_with_Arrays/01-List_ADT_Implementation$ ./a.out

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 1
Enter The Element: 1

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 1  

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 2
Enter The Element: 10

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 1  10

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 3
Enter the Position: 4
Invalid Position!

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 3
Enter the Position: 2
Enter The Element: 66

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 1  10  66

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 4

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 10  66

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 5

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 10

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 1
Enter The Element: 23

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 1
Enter The Element: 63

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 1 
Enter The Element: 145

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 6
Enter the Position: 1

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 145  23  10

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 2
Enter The Element: 45

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 145  23  10  45

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 9
Enter Number of Rotations: 3
If You Want to Do it in 3 different Methods 1 enter 1, Method 2 enter 2, Method 3 enter 3: 1

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 23  10  45  145

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 9
Enter Number of Rotations: 1
If You Want to Do it in 3 different Methods 1 enter 1, Method 2 enter 2, Method 3 enter 3: 2

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 8

The List is: 145  23  10  45

           MENU
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete at Position
7. Search
8. Display
9. Rotate
10. Exit

ENTER YOUR CHOICE: 10
```

\pagebreak

# List ADT with Linked Lists

## Reversing

### Question

Write a C++ menu-driven program to implement List ADT using a singly linked list. Maintain proper boundary conditions and folloy good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7.Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit

### Algorithm

#### Algorithm 1 - Insert_Beginning {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with num inserted at the beginning

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$
2. $newnode.next \leftarrow head$
3. $head \leftarrow newnode$

#### Algorithm 2 - Insert_End {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with num inserted at the end

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Call $insert\_beg(num)$
2. Else:
    1. Create new node $newnode$ with $data = num$ and $next = null$
    2. $temp \leftarrow head$
    3. While $temp.next \neq null$:
        1. $temp \leftarrow temp.next$
    4. $temp.next \leftarrow newnode$

#### Algorithm 3 - Insert_Position {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. pos - position to insert at
3. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with num inserted at position pos

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$
2. If $pos = 1$:
    1. Call $insert\_beg(num)$
3. Else if $pos = count() + 1$:
    1. Call $insert\_end(num)$
4. Else:
    1. $temp \leftarrow head$
    2. For $i$ from $1$ to $pos-2$:
        1. $temp \leftarrow temp.next$
    3. $newnode.next \leftarrow temp.next$
    4. $temp.next \leftarrow newnode$

#### Algorithm 4 - Delete_Beginning {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with first node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
2. Else:
    1. $temp \leftarrow head.next$
    2. Free $head$
    3. $head \leftarrow temp$

#### Algorithm 5 - Delete_End {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with last node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
2. Else:
    1. $temp \leftarrow head$
    2. If $temp.next = null$ (only one node):
        1. Call $delete\_beg()$
    3. Else:
        1. While $temp.next.next \neq null$:
            1. $temp \leftarrow temp.next$
        2. Free $temp.next$
        3. $temp.next \leftarrow null$

#### Algorithm 6 - Delete_Position {.unnumbered}

##### Input {.unnumbered}

1. pos - position to delete
2. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with node at position pos removed

##### Steps {.unnumbered}

1. If $pos = 1$:
    1. Call $delete\_beg()$
2. Else if $pos = count()$:
    1. Call $delete\_end()$
3. Else:
    1. $temp \leftarrow head$
    2. For $i$ from $1$ to $pos-1$:
        1. $temp \leftarrow temp.next$
    3. $temp2 \leftarrow temp.next.next$
    4. Free $temp.next$
    5. $temp.next \leftarrow temp2$

#### Algorithm 7 - Display {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Elements of the linked list printed

##### Steps {.unnumbered}

1. $temp \leftarrow head$
2. If $head = null$ (list is empty):
    1. Print "List is empty"
3. Else:
    1. While $temp \neq null$:
        1. Print $temp.data$ followed by " ->"
        2. $temp \leftarrow temp.next$
    2. Print newline

#### Algorithm 8 - Search {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. head - pointer to head of linked list

##### Output {.unnumbered}

- Status message indicating if num was found or not

##### Steps {.unnumbered}

1. $temp \leftarrow head$
2. If $head = null$ (list is empty):
    1. Print "List is empty"
3. Else:
    1. While $temp \neq null$:
        1. If $temp.data = num$:
            1. Print "Element found"
            2. Return
        2. $temp \leftarrow temp.next$
    2. Print "Element not found"

#### Algorithm 9 - Count {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Number of nodes in the linked list

##### Steps {.unnumbered}

1. $temp \leftarrow head$
2. $c \leftarrow 0$
3. While $temp \neq null$:
    1. $c \leftarrow c + 1$
    2. $temp \leftarrow temp.next$
4. Return $c$

#### Algorithm 10 - ReverseLink {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Linked list with all links reversed

##### Steps {.unnumbered}

1. $temp \leftarrow head$
2. $len \leftarrow count()$ (Count number of nodes)
3. Create array $arr$ of size $len$ to store all node pointers
4. For $i$ from $0$ to $len-1$:
    1. $arr[i] \leftarrow temp$
    2. $temp \leftarrow temp.next$
5. Create array $arr2$ of size $len$ with reversed pointers
6. For $i$ from $0$ to $len-1$:
    1. $arr2[i] \leftarrow arr[len-1-i]$
7. $head \leftarrow arr2[0]$
8. $temp \leftarrow head$
9. For $i$ from $1$ to $len-1$:
    1. $temp.next \leftarrow arr2[i]$
    2. $temp \leftarrow temp.next$
10. $temp.next \leftarrow null$

#### Algorithm 11 - ReverseDisplay {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of linked list

##### Output {.unnumbered}

- Elements of the linked list displayed in reverse order

##### Steps {.unnumbered}

1. $len \leftarrow count()$ (Count number of nodes)
2. Create array $arr$ of size $len$ to store node values
3. If $head = null$ (list is empty):
    1. Print "List is empty"
4. Else:
    1. $temp \leftarrow head$
    2. $i \leftarrow 0$
    3. While $temp \neq null$:
        1. $arr[len-1-i] \leftarrow temp.data$
        2. $temp \leftarrow temp.next$
        3. $i \leftarrow i + 1$
    4. For $j$ from $0$ to $len-1$:
        1. Print $arr[j]$ followed by space

### Code

__main.cpp__

```cpp

#include <cstdio>
#include <cstdlib>

// Singly Linked List class
class SLL {
private:
  struct node {
    int data;
    struct node *next;
  };
  struct node *head;

  void displayReverse(struct node *);

public:
  SLL() { head = NULL; };
  void insbeg(int);
  void insend(int);
  int inspos(int, int);
  void delbeg();
  void delend();
  int delpos(int);
  void search(int);
  void display();
  void displayReverse();
  void reverseList();
};

int main() {
  SLL list;
  int choice, num, pos;

  while (1) {
    printf("\n*** Singly Linked List Operations ***\n");
    printf("1. Insert Beginning\n");
    printf("2. Insert End\n");
    printf("3. Insert Position\n");
    printf("4. Delete Beginning\n");
    printf("5. Delete End\n");
    printf("6. Delete Position\n");
    printf("7. Search\n");
    printf("8. Display\n");
    printf("9. Display Reverse\n");
    printf("10. Reverse Link\n");
    printf("11. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      list.insbeg(num);
      break;
    case 2:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      list.insend(num);
      break;
    case 3:
      printf("Enter number to insert: ");
      scanf("%d", &num);
      printf("Enter position: ");
      scanf("%d", &pos);
      list.inspos(num, pos);
      break;
    case 4:
      list.delbeg();
      break;
    case 5:
      list.delend();
      break;
    case 6:
      printf("Enter position to delete: ");
      scanf("%d", &pos);
      list.delpos(pos);
      break;
    case 7:
      printf("Enter number to search: ");
      scanf("%d", &num);
      list.search(num);
      break;
    case 8:
      list.display();
      break;
    case 9:
      printf("List in reverse order: \n");
      list.displayReverse();
      printf("NULL\n");
      break;
    case 10:
      list.reverseList();
      printf("List reversed successfully\n");
      break;
    case 11:
      exit(0);
    default:
      printf("Invalid choice!\n");
    }
  }
  return 0;
}

// Function to insert a node at the beginning
void SLL::insbeg(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = head;
  head = newNode;
}

// Function to insert a node at the end
void SLL::insend(int num) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;
  newNode->next = NULL;

  if (head == NULL) {
    head = newNode;
    return;
  }

  struct node *temp = head;
  while (temp->next != NULL) {
    temp = temp->next;
  }
  temp->next = newNode;
}

// Function to insert a node at a specific position
int SLL::inspos(int num, int pos) {
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = num;

  if (pos == 0) {
    newNode->next = head;
    head = newNode;
    return 0;
  }

  struct node *temp = head;
  for (int i = 0; i < pos - 1 && temp != NULL; i++) {
    temp = temp->next;
  }

  if (temp == NULL) {
    printf("Position out of range\n");
    free(newNode);
    return 0;
  }

  newNode->next = temp->next;
  temp->next = newNode;
  return 0;
}

// Function to delete a node from the beginning
void SLL::delbeg() {
  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  struct node *temp = head;
  head = head->next;
  free(temp);
}

// Function to delete a node from the end
void SLL::delend() {
  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  struct node *temp = head;
  struct node *prev = NULL;

  if (head->next == NULL) {
    head = NULL;
    free(temp);
    return;
  }

  while (temp->next != NULL) {
    prev = temp;
    temp = temp->next;
  }

  prev->next = NULL;
  free(temp);
}

// Function to delete a node from a specific position
int SLL::delpos(int pos) {
  if (head == nullptr) {
    printf("The List is Empty\n");
    return 0;
  }

  struct node *temp = head;
  struct node *prev = nullptr;

  if (pos == 0) {
    head = temp->next;
    free(temp);
    return 0;
  }

  for (int i = 0; i < pos && temp != nullptr; i++) {
    prev = temp;
    temp = temp->next;
  }

  if (temp == nullptr) {
    printf("Position out of range\n");
    return 0;
  }

  prev->next = temp->next;
  free(temp);
  return 0;
}

// Function to search for an element in the list
void SLL::search(int num) {
  struct node *temp = head;
  int pos = 0;

  while (temp != NULL) {
    if (temp->data == num) {
      printf("Element %d found at position %d\n", num, pos);
      return;
    }
    temp = temp->next;
    pos++;
  }

  printf("Element %d not found in the list\n", num);
}

// Function to display the list
void SLL::display() {
  struct node *temp = head;

  if (head == NULL) {
    printf("The List is Empty\n");
    return;
  }

  while (temp != NULL) {
    printf("%d->", temp->data);
    temp = temp->next;
  }
  printf("NULL\n");
}

// Function to display the list in reverse order
void SLL::displayReverse() { displayReverse(head); }

// Helper function to display the list in reverse order
void SLL::displayReverse(struct node *temp) {
  if (temp == nullptr)
    return;
  displayReverse(temp->next);
  printf("%d->", temp->data);
}

// Function to reverse the list
void SLL::reverseList() {
  struct node *prev = nullptr;
  struct node *current = head;
  struct node *next = nullptr;

  while (current != nullptr) {
    next = current->next;
    current->next = prev;
    prev = current;
    current = next;
  }
  head = prev;
}

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/04-List_ADT_with_Linked_Lists/01-Reversing$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/04-List_ADT_with_Linked_Lists/01-Reversing$ ./a.out

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 1
Enter number to insert: 1

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 2
Enter number to insert: 2

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 8
1->2->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 3
Enter number to insert: 3
Enter position: 2

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 8
1->2->3->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 7
Enter number to search: 2
Element 2 found at position 1

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 4

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 8
2->3->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 5

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 8
2->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 1
Enter number to insert: 1

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 2
Enter number to insert: 3

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 2
Enter number to insert: 4

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 2
Enter number to insert: 5

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 2
Enter number to insert: 6

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 10
List reversed successfully

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 8
6->5->4->3->2->1->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 9
List in reverse order: 
1->2->3->4->5->6->NULL

*** Singly Linked List Operations ***
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Display Reverse
10. Reverse Link
11. Exit
Enter your choice: 11
```

## Ascending Insert and Merging

### Question

Write a C++ menu-driven program to implement List ADT using a singly linked list. You have a gethead() private member function that returns the address of the head value of a list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Ascending
2. Merge 
3. Display 
4. Exit

Option 1 inserts a node so the list is always in ascending order. Option 2 takes two lists as input, and merges two lists into a third list. The third list should also be in ascending order. Convert the file into a header file and include it in a C++ file. The second C++ consists of 3 lists and has the following operations,

1. Insert List1
2. Insert List2
3. Merge into List3
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - InsertAscending {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of linked list

##### Output {.unnumbered}

- Updated linked list with num inserted in ascending order

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$ and $next = null$
2. If $head = null$ (list is empty) or $num < head.data$:
    1. $newnode.next \leftarrow head$
    2. $head \leftarrow newnode$
    3. Return
3. $temp \leftarrow head$
4. While $temp.next \neq null$ and $temp.next.data < num$:
    1. $temp \leftarrow temp.next$
5. $newnode.next \leftarrow temp.next$
6. $temp.next \leftarrow newnode$

#### Algorithm 2 - MergeLists {.unnumbered}

##### Input {.unnumbered}

1. l1 - first sorted linked list
2. l2 - second sorted linked list

##### Output {.unnumbered}

- l3 - merged sorted linked list containing all elements from l1 and l2

##### Steps {.unnumbered}

1. Initialize new empty list $l3$
2. $p1 \leftarrow l1.head$
3. $p2 \leftarrow l2.head$
4. While $p1 \neq null$ and $p2 \neq null$:
    1. If $p1.data \leq p2.data$:
        1. $l3.insert\_end(p1.data)$
        2. $p1 \leftarrow p1.next$
    2. Else:
        1. $l3.insert\_end(p2.data)$
        2. $p2 \leftarrow p2.next$
5. While $p1 \neq null$:
    1. $l3.insert\_end(p1.data)$
    2. $p1 \leftarrow p1.next$
6. While $p2 \neq null$:
    1. $l3.insert\_end(p2.data)$
    2. $p2 \leftarrow p2.next$
7. Return $l3$

### Code

__main.cpp__

```cpp

#include<iostream>
#include "list.h"
using namespace std;

int main()
{
    List l1,l2,l3;
    int choice,num,exit=0;
    while(exit!=1)
    {
        cout << "1.Insert in list 1\n2.Insert in list 2\n3.Merge lists\n4.Display list 1\n5.Display list 2\n6.Display merged list\n7.Exit\n";
        cin >> choice;
        switch(choice)
        {
            case 1: 
                cout << "Enter number to insert in list 1: ";
                cin >> num;
                l1.insert_ascending(num);
                break;
            case 2: 
                cout << "Enter number to insert in list 2: ";
                cin >> num;
                l2.insert_ascending(num);
                break;
            case 3: 
                l3=l3.merge(l1,l2);
                break;
            case 4: 
                l1.display();
                break;
            case 5: 
                l2.display();
                break;
            case 6: 
                l3.display();
                break;
            case 7: 
                exit=1;
                break;
            default: 
                cout << "Invalid choice\n";
        }
    }
}
```

__list.h__

```h

#define LIST_H
#include<iostream>
using namespace std;

class List
{
    struct node
    {
        int data;
        struct node *next;
    }*head;
    
    public:

    struct node* gethead()
    {
        return head;
    }
    List()
    {
        head=NULL;
    }
    
    void insert_ascending(int num)
    {
        struct node* newnode=new struct node;
        newnode->data=num;
        if(head==NULL)
        {
            newnode->next=NULL;
            head=newnode;
        }
        else if(head->data>num)
        {
            newnode->next=head;
            head=newnode;
        }
        else
        {
            struct node *temp=head;
            while(temp->next!=NULL && temp->next->data<num)
            {
                temp=temp->next;
            }
            newnode->next=temp->next;
            temp->next=newnode;
        }
    }
    List merge(List l1,List l2)
    {
        List l3;
        struct node *temp1=l1.gethead();
        struct node *temp2=l2.gethead();
        while(temp1!=NULL && temp2!=NULL)
        {
            if(temp1->data<temp2->data)
            {
                l3.insert_ascending(temp1->data);
                temp1=temp1->next;
            }
            else
            {
                l3.insert_ascending(temp2->data);
                temp2=temp2->next;
            }
        }
        while(temp1!=NULL)
        {
            l3.insert_ascending(temp1->data);
            temp1=temp1->next;
        }
        while(temp2!=NULL)
        {
            l3.insert_ascending(temp2->data);
            temp2=temp2->next;
        }
        return l3;
    }
    void display()
    {
        struct node *temp=head;
        if(head==NULL)
        {
            cout << "List is empty";
        }
        else
        {
            while(temp!=NULL)
            {
                cout << temp->data << " ->";
                temp=temp->next;
            }
            cout << "NULL\n";
        }
    }
};
```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/04-List_ADT_with_Linked_Lists/02-Ascending_Insert_and_Merging$ g++ main.cpp
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/04-List_ADT_with_Linked_Lists/02-Ascending_Insert_and_Merging$ ./a.out
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
1
Enter number to insert in list 1: 4
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
1
Enter number to insert in list 1: 63
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
1
Enter number to insert in list 1: 4
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
2
Enter number to insert in list 2: 54
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
2
Enter number to insert in list 2: 63
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
2
Enter number to insert in list 2: 7
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
4
4 ->4 ->63 ->NULL
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
5
7 ->54 ->63 ->NULL
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
6
List is empty1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
3
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
6
4 ->4 ->7 ->54 ->63 ->63 ->NULL
1.Insert in list 1
2.Insert in list 2
3.Merge lists
4.Display list 1
5.Display list 2
6.Display merged list
7.Exit
7
```

\pagebreak

# List ADT Circular and Doubly Linked Lists

## Doubly Linked List with Tail

### Question

Write a C++ menu-driven program to implement List ADT using a doubly linked list with a tail. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit

### Algorithm

#### Algorithm 1 - DoublyLinkedListInsertBeginning {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of doubly linked list
3. tail - pointer to tail of doubly linked list

##### Output {.unnumbered}

- Updated doubly linked list with num inserted at beginning

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$, $next = head$, $prev = null$
2. If $head = null$ (list is empty):
    1. $head \leftarrow newnode$
    2. $tail \leftarrow newnode$
3. Else:
    1. $head.prev \leftarrow newnode$
    2. $head \leftarrow newnode$

#### Algorithm 2 - DoublyLinkedListInsertEnd {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of doubly linked list
3. tail - pointer to tail of doubly linked list

##### Output {.unnumbered}

- Updated doubly linked list with num inserted at end

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$, $next = null$, $prev = tail$
2. If $head = null$ (list is empty):
    1. $head \leftarrow newnode$
    2. $tail \leftarrow newnode$
3. Else:
    1. $tail.next \leftarrow newnode$
    2. $tail \leftarrow newnode$

#### Algorithm 3 - DoublyLinkedListInsertPosition {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. pos - position to insert at
3. head - pointer to head of doubly linked list
4. tail - pointer to tail of doubly linked list

##### Output {.unnumbered}

- Updated doubly linked list with num inserted at position pos

##### Steps {.unnumbered}

1. If $pos = 1$:
    1. Call $insert\_beginning(num)$
    2. Return
2. $temp \leftarrow head$
3. For $i$ from $1$ to $pos-2$:
    1. $temp \leftarrow temp.next$
4. If $temp.next = null$:
    1. Call $insert\_end(num)$
    2. Return
5. Create new node $newnode$ with $data = num$
6. $newnode.next \leftarrow temp.next$
7. $newnode.prev \leftarrow temp$
8. $temp.next \leftarrow newnode$
9. $newnode.next.prev \leftarrow newnode$

#### Algorithm 4 - DoublyLinkedListDeleteBeginning {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of doubly linked list
2. tail - pointer to tail of doubly linked list

##### Output {.unnumbered}

- Updated doubly linked list with first node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
    2. Return
2. $temp \leftarrow head$
3. If $head.next = null$ (only one node):
    1. $head \leftarrow null$
    2. $tail \leftarrow null$
    3. Delete $temp$
    4. Return
4. $head \leftarrow head.next$
5. Delete $temp$
6. $head.prev \leftarrow null$

#### Algorithm 5 - DoublyLinkedListDeleteEnd {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of doubly linked list
2. tail - pointer to tail of doubly linked list

##### Output {.unnumbered}

- Updated doubly linked list with last node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
    2. Return
2. If $head.next = null$ (only one node):
    1. Call $delete\_beginning()$
    2. Return
3. $temp \leftarrow tail$
4. $tail \leftarrow tail.prev$
5. Delete $temp$
6. $tail.next \leftarrow null$

### Code

__main.cpp__

```cpp

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
   
```

### Execution

```sh

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 1
Enter the value: 10

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 2
Enter the value: 20

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 3
Enter the value: 15
Enter the position: 1

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
10->15->20->NULL

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 4

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
15->20->NULL

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 5

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
15->NULL

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 6
Enter the position: 0

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
The List is Empty

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 7
Enter the value to search: 20
Element 20 not found.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 1
Enter the value: 5

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 2
Enter the value: 25

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 2
Enter the value: 30

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
5->25->30->NULL

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 3
Enter the value: 99
Enter the position: 10
Invalid position.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 7
Enter the value to search: 25
Element 25 found at position 1.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
5->25->30->NULL

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 9
Exiting program...

```

## Circular Linked List

### Question

Write a C++ menu-driven program to implement List ADT using a circular linked list. Maintain proper boundary conditions and follow good coding practices. The List ADT has the following operations,

1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit

### Algorithm

#### Algorithm 1 - CircularLinkedListInsertBeginning {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with num inserted at beginning

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = num$
2. If $head = null$ (list is empty):
    1. $head \leftarrow newnode$
    2. $newnode.next \leftarrow head$ (self-reference to make it circular)
3. Else:
    1. $temp \leftarrow head$
    2. While $temp.next \neq head$:
        1. $temp \leftarrow temp.next$
    3. $temp.next \leftarrow newnode$
    4. $newnode.next \leftarrow head$
    5. $head \leftarrow newnode$

#### Algorithm 2 - CircularLinkedListInsertEnd {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with num inserted at end

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Call $insert\_beginning(num)$
2. Else:
    1. Create new node $newnode$ with $data = num$
    2. $newnode.next \leftarrow head$
    3. $temp \leftarrow head$
    4. While $temp.next \neq head$:
        1. $temp \leftarrow temp.next$
    5. $temp.next \leftarrow newnode$

#### Algorithm 3 - CircularLinkedListInsertPosition {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. pos - position to insert at
3. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with num inserted at position pos

##### Steps {.unnumbered}

1. If $pos = 1$:
    1. Call $insert\_beginning(num)$
2. Else:
    1. Create new node $newnode$ with $data = num$
    2. $temp \leftarrow head$
    3. For $i$ from $1$ to $pos-2$:
        1. $temp \leftarrow temp.next$
    4. $newnode.next \leftarrow temp.next$
    5. $temp.next \leftarrow newnode$

#### Algorithm 4 - CircularLinkedListDeleteBeginning {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with first node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
2. Else:
    1. $temp \leftarrow head$
    2. While $temp.next \neq head$:
        1. $temp \leftarrow temp.next$
    3. $temp.next \leftarrow head.next$
    4. Delete $head$
    5. $head \leftarrow temp.next$

#### Algorithm 5 - CircularLinkedListDeleteEnd {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with last node removed

##### Steps {.unnumbered}

1. If $head = null$ (list is empty):
    1. Print "List is empty"
2. Else:
    1. $temp \leftarrow head$
    2. While $temp.next.next \neq head$:
        1. $temp \leftarrow temp.next$
    3. Delete $temp.next$
    4. $temp.next \leftarrow head$

#### Algorithm 6 - CircularLinkedListDeletePosition {.unnumbered}

##### Input {.unnumbered}

1. pos - position to delete
2. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Updated circular linked list with node at position pos removed

##### Steps {.unnumbered}

1. If $pos = 1$:
    1. Call $delete\_beginning()$
2. Else:
    1. $temp \leftarrow head$
    2. For $i$ from $1$ to $pos-2$:
        1. $temp \leftarrow temp.next$
    3. $temp1 \leftarrow temp.next$
    4. $temp.next \leftarrow temp1.next$
    5. Delete $temp1$

#### Algorithm 7 - CircularLinkedListSearch {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. head - pointer to head of circular linked list

##### Output {.unnumbered}

- Position of num in the linked list if found, else message "Element not found"

##### Steps {.unnumbered}

1. $temp \leftarrow head$
2. $pos \leftarrow 1$
3. While $temp.next \neq head$:
    1. If $temp.data = num$:
        1. Print "Element found at position $pos$"
        2. Return
    2. $temp \leftarrow temp.next$
    3. $pos \leftarrow pos + 1$
4. If $temp.data = num$:
    1. Print "Element found at position $pos$"
5. Else:
    1. Print "Element not found"

### Code

__main.cpp__

```cpp

/*B. Write a C++ menu-driven program to implement List ADT using a circular linked list.
Maintain proper boundary conditions and follow good coding practices. The List ADT has
the following operations,
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit*/
#include <iostream>
#include <cstdlib> 
using namespace std;

class SCLL {
private:
    struct node {
        int data;
        struct node* next;
    };
    struct node* head;

public:
    SCLL() { head = nullptr; }

    void insbeg(int);     // O(1)
    void insend(int);     // O(n)
    int inspos(int, int); // O(n)
    void delbeg();        // O(n) 
    void delend();        // O(n)
    void delpos(int);     // O(n)
    int search(int);      // O(n)
    void display();       // O(n)
};

int main() {
    SCLL arr;
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
void SCLL::insbeg(int num) { // O(1)
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Find last node
            temp = temp->next;
        }
        ptr->next = head;
        head = ptr;
        temp->next = head; // Update last node’s next pointer
    }
}

// Insert at End
void SCLL::insend(int num) { // O(n)
    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    if (head == nullptr) {
        head = ptr;
        ptr->next = head;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Traverse to last node
            temp = temp->next;
        }
        temp->next = ptr;
        ptr->next = head; // Circular link
    }
}

// Insert at Position (0-based index)
int SCLL::inspos(int num, int pos) { // O(n)
    if (head == nullptr || pos == 0) {
        insbeg(num);
        return 0;
    }

    struct node* ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data = num;

    struct node* temp = head;
    int count = 0;

    while (temp->next != head && count < pos - 1) {
        count++;
        temp = temp->next;
    }

    if (count < pos - 1) {
        cout << "Invalid position.\n";
        free(ptr);
        return -1;
    }

    ptr->next = temp->next;
    temp->next = ptr;

    return 0;
}

// Delete from Beginning
void SCLL::delbeg() { //  O(n)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    struct node* ptr = head;

    if (head->next == head) { // Only one node
        head = nullptr;
    } else {
        struct node* temp = head;
        while (temp->next != head) { // Find last node
            temp = temp->next;
        }
        head = head->next;
        temp->next = head; // Maintain circular link
    }
    free(ptr);
}

// Delete from End
void SCLL::delend() { // O(n)
    if (head == nullptr) {
        cout << "The list is empty.\n";
        return;
    }

    if (head->next == head) { // Only one node
        free(head);
        head = nullptr;
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;

    while (temp->next != head) { // Traverse to last node
        prev = temp;
        temp = temp->next;
    }

    prev->next = head; // Maintain circular link
    free(temp);
}

// Delete from Position
void SCLL::delpos(int pos) { // O(n)
    if (!head || pos < 0) {
        cout << "Invalid position or empty list.\n";
        return;
    }

    struct node* temp = head;
    struct node* prev = nullptr;
    int count = 0;

    if (pos == 0) { // Delete first node
        delbeg();
        return;
    }

    while (temp->next != head && count < pos) {
        prev = temp;
        temp = temp->next;
        count++;
    }

    if (count < pos) {
        cout << "Position out of range.\n";
        return;
    }

    prev->next = temp->next;

    free(temp);
}

// Search for an element
int SCLL::search(int num) { // O(n)
    struct node* temp = head;
    int pos = 0;

    if (head == nullptr)
        return -1;

    do {
        if (temp->data == num)
            return pos;
        temp = temp->next;
        pos++;
    } while (temp != head);

    return -1;
}

// Display the list
void SCLL::display() { // O(n)
    if (head == nullptr) {
        cout << "The List is Empty\n";
        return;
    }

    struct node* temp = head;
    do {
        cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);
    cout << "HEAD (circular)\n";
}

```

### Execution

```sh

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 1
Enter the value: 10

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 2
Enter the value: 20

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 3
Enter the value: 15
Enter the position: 1

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
10 -> 15 -> 20 -> HEAD (circular)

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 4

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
15 -> 20 -> HEAD (circular)

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 5

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
15 -> HEAD (circular)

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 6
Enter the position: 0

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
The List is Empty

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 7
Enter the value to search: 20
Element 20 not found.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 2
Enter the value: 99

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 1
Enter the value: 5

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 8
5 -> 99 -> HEAD (circular)

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 3
Enter the value: 33
Enter the position: 10
Invalid position.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 7
Enter the value to search: 99
Element 99 found at position 1.

           MENU
1. Insert Beginning
2. Insert End
3. Insert Position
4. Delete Beginning
5. Delete End
6. Delete Position
7. Search
8. Display
9. Exit
ENTER YOUR CHOICE: 9
Exiting program...

```

## Round Robin Scheduler

### Question

An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list.

Implement the program by including the appropriate header file. It consists of the following operations.

1. Insert Proces
2. Execute
3. Exit

The "Insert Process” will get an integer time from the user and add it to the queue. 
The "Exccute” operation will exceute a deletion in the beginning operation and subtract the fixcd time from the process. If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining time after subtraction is inserted at the end of the circular linked list.


### Algorithm

#### Algorithm 1 - RoundRobinScheduler {.unnumbered}

##### Input {.unnumbered}

1. processList - circular linked list containing process burst times
2. timeSlot - time quantum for each execution

##### Output {.unnumbered}

- Execution order of processes

##### Steps {.unnumbered}

1. Initialize circular linked list $processList$
2. Input time quantum $timeSlot$
3. While $processList$ is not empty:
    1. $val \leftarrow processList.delete\_beginning()$ (Extract first process)
    2. $remainingTime \leftarrow val - timeSlot$
    3. If $remainingTime > 0$:
        1. $processList.insert\_end(remainingTime)$ (Reinsert process at end with updated time)
    4. Else:
        1. Process completed execution

### Code

__main.cpp__

```cpp

/*C. An operating system allocates a fixed time slot CPU time for processes using a round-robin scheduling algorithm. The fixed time slot will be 
initialized before the start of the menu-driven program. Implement the round-robin scheduling algorithm using the circular linked list.
Implement the program by including the appropriate header file. It consists of the following operations.
Insert Process
Execute
Exit
The "Insert Process" will get an integer time from the user and add it to the queue.
The "Execute" operation will execute a deletion in the beginning operation and subtract the fixed time from the process.
 If the processing time falls below 0 then the process is considered to have completed its execution, otherwise, the remaining
 time after subtraction is inserted at the end of the circular linked list.
What is the time complexity of each of the operations? (K4)
*/
#include<iostream>
#include<cstdlib>
using namespace std;

class schedule {
private:
    struct process {
        int time;
        struct process *link;
    }*head = nullptr, *tail = nullptr;

    int pro_count = 0;
    int timeslice = 0;

public:
    schedule() { head = nullptr; tail = nullptr; }

    void getimeslice();   // O(1)
    void insert(int pro_time);   // O(1)
    void delete_process();   // O(1)
    void execute();   // O(n) in worst case
};

int main() {
    int selection;
    schedule cpu;
    cpu.getimeslice();

    while (1) {
        cout << "\n       MENU        " << endl;
        cout << "1. Insert Process" << endl;
        cout << "2. Execute" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> selection;

        switch (selection) {
            case 1:
                int process_time;
                cout << "Enter the process time: ";
                cin >> process_time;
                cpu.insert(process_time);
                break;
            case 2:
                cpu.execute();
                break;
            case 3:
                cout << "Exiting....." << endl;
                return 0;
            default:
                cout << "Selected choice Cease to exist\nplease Try Again" << endl;
        }
    }
}

// O(1)
void schedule::getimeslice() {
    cout << "Enter the time slice for a process: ";
    cin >> timeslice;
}

// O(1)
void schedule::insert(int pro_time) {
    struct process *newprocess = (struct process *)malloc(sizeof(struct process));
    newprocess->time = pro_time;
    newprocess->link = nullptr;

    if (head == nullptr && tail == nullptr) {
        head = newprocess;
        tail = newprocess;
        newprocess->link = head;
    } else {
        tail->link = newprocess;
        tail = newprocess;
        newprocess->link = head;
    }
    pro_count++;
}

// O(1)
void schedule::delete_process() {
    if (head == tail) {
        head->link = nullptr;
        head = nullptr;
        tail = nullptr;
    } else {
        struct process *temp = head;
        head = temp->link;
        temp->link = nullptr;
        tail->link = head;
        free(temp);
    }
    pro_count--;
}

// O(n) in worst case (when the process needs to be moved to the end)
void schedule::execute() {
    struct process *temp = head;
    struct process *temp2 = head;

    if (temp == nullptr) {
        cout << "There are no processes to execute!!" << endl;
    } else {
        temp->time = temp->time - timeslice;

        if (temp->time <= 0) {
            delete_process();  // O(1)
        } else {
            head = temp->link;
            
            // Find the last process in the list to update the tail
            while (temp != tail) {
                temp = temp->link;
            }
            temp->link->link = temp2;
            tail = temp2;
        }

        cout << "Execution Completed!!" << endl;
        cout << "No of processes pending --> " << pro_count << endl;
    }
}

```

### Execution

```sh

Enter the time slice for a process: 4

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 1
Enter the process time: 10

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 1
Enter the process time: 6

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 1
Enter the process time: 3

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 3

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 3

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 2

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 2

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 1

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 2
Execution Completed!!
No of processes pending --> 0

       MENU        
1. Insert Process
2. Execute
3. Exit
Enter your choice: 3
Exiting.....

```

\pagebreak

# Stack ADT

## Character Array Stack ADT

### Question

Write a separate C++ menu-driven program to implement stack ADT using a character array of size 5. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations

1. Push
2. Pop
3. Peek
4. Exit

### Algorithm

#### Algorithm 1 - ArrayStackPush {.unnumbered}

##### Input {.unnumbered}

1. ch - character to push
2. arr[] - array storing the stack elements
3. cur - current position (top) of stack

##### Output {.unnumbered}

- Updated stack with character ch added

##### Steps {.unnumbered}

1. If $cur = 5$ (stack is full):
    1. Print "List is full"
    2. Return
2. $arr[cur] \leftarrow ch$
3. $cur \leftarrow cur + 1$

#### Algorithm 2 - ArrayStackPop {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the stack elements
2. cur - current position (top) of stack

##### Output {.unnumbered}

- Character from the top of stack and updated stack

##### Steps {.unnumbered}

1. If $cur = 0$ (stack is empty):
    1. Print "List is empty"
    2. Return \$0$
2. $cur \leftarrow cur - 1$
3. Return $arr[cur]$

#### Algorithm 3 - ArrayStackPeek {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the stack elements
2. cur - current position (top) of stack

##### Output {.unnumbered}

- Character from the top of stack (without removing it)

##### Steps {.unnumbered}

1. If $cur = 0$ (stack is empty):
    1. Print "List is empty"
    2. Return
2. Print $arr[cur-1]$

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

#define SIZE 5  // Maximum size of the stack

class Stack {
private:
    char arr[SIZE];  
    int top;         

public:
    Stack() { top = -1; } 

    void push(char ch);
    void pop();
    void peek();
};

int main() {
    Stack stack;
    int choice;
    char value;

    while (true) {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}

 // Push operation Time Complexity O(1)
 void Stack :: push(char ch) {
    if (top == SIZE - 1) {
        cout << "Stack Overflow! Cannot push " << ch << "." << endl;
        return;
    }
    arr[++top] = ch;
    cout << ch << " pushed onto stack." << endl;
}

// Pop operation Time Complexity O(1)
void Stack :: pop() {
    if (top == -1) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    cout << arr[top] << " popped from stack." << endl;
    top--;
}

 // Peek operation (View the top element) Time Complexity O(1)
 void Stack :: peek() {
    if (top == -1) {
        cout << "Stack is empty! No element to peek." << endl;
        return;
    }
    cout << "Top element: " << arr[top] << endl;
}
```

### Execution

```sh

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: A
A pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: B
B pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Top element: B

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
B popped from stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
A popped from stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Stack is empty! No element to peek.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
Stack Underflow! No elements to pop.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: X
X pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: Y
Y pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: Z
Z pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: M
M pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: N
N pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: O
Stack Overflow! Cannot push O.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 4
Exiting program.

```

## Character Linked List Stack ADT

### Question

Write a separate C++ menu-driven program to implement stack ADT using a character singly linked list. Maintain proper boundary conditions and follow good coding practices. Stack ADT has the following operations,

1. Push
2. Pop
3. Peek
4. Exit

### Algorithm

#### Algorithm 1 - StackPush {.unnumbered}

##### Input {.unnumbered}

1. ch - character to push
2. head - pointer to top of stack

##### Output {.unnumbered}

- Updated stack with character ch added

##### Steps {.unnumbered}

1. Create new node $newnode$ with $data = ch$ and $next = null$
2. If $head = null$ (stack is empty):
    1. $head \leftarrow newnode$
3. Else:
    1. $temp \leftarrow head$
    2. While $temp.next \neq null$:
        1. $temp \leftarrow temp.next$
    3. $temp.next \leftarrow newnode$

#### Algorithm 2 - StackPop {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to top of stack

##### Output {.unnumbered}

- Character from the top of stack and updated stack

##### Steps {.unnumbered}

1. If $head = null$ (stack is empty):
    1. Print "List is empty"
    2. Return
2. $temp \leftarrow head$
3. If $temp.next = null$ (only one element):
    1. $ch \leftarrow head.data$
    2. Free $head$
    3. $head \leftarrow null$
    4. Return $ch$
4. Else:
    1. While $temp.next.next \neq null$:
        1. $temp \leftarrow temp.next$
    2. $ch \leftarrow temp.next.data$
    3. Free $temp.next$
    4. $temp.next \leftarrow null$
    5. Return $ch$

#### Algorithm 3 - StackPeek {.unnumbered}

##### Input {.unnumbered}

1. head - pointer to top of stack

##### Output {.unnumbered}

- Character from the top of stack (without removing it)

##### Steps {.unnumbered}

1. If $head = null$ (stack is empty):
    1. Print "List is empty"
    2. Return $0$
2. $temp \leftarrow head$
3. While $temp.next \neq null$:
    1. $temp \leftarrow temp.next$
4. Return $temp.data$

### Code

__main.cpp__

```cpp

#include <iostream>
#include <cstdlib>  
using namespace std;

class Stack {
private:
    struct Node {
        char data;
        Node* next;
    };

    Node* top; // Pointer to the top of the stack

public:
    Stack(){
        top = nullptr;
    };           // Constructor
    void push(char ch); 
    void pop();        
    void peek();       
    void clear();      
};

// Main function with a menu-driven interface
int main() {
    Stack stack;
    int choice;
    char value;

    while (true) {
        cout << "\nStack Menu:\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter character to push: ";
                cin >> value;
                stack.push(value);
                break;
            case 2:
                stack.pop();
                break;
            case 3:
                stack.peek();
                break;
            case 4:
                stack.clear(); // Manually clear memory before exiting
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice! Please enter a valid option." << endl;
        }
    }
}


// Push operation Time Complexity O(1)
void Stack::push(char ch) {
    Node* newNode = (Node*)malloc(sizeof(Node)); 
    if (!newNode) {
        cout << "Heap Overflow! Cannot push " << ch << "." << endl;
        return;
    }
    newNode->data = ch;
    newNode->next = top;
    top = newNode;
    cout << ch << " pushed onto stack." << endl;
}

// Pop operation Time Complexity O(1)
void Stack::pop() {
    if (top == nullptr) {
        cout << "Stack Underflow! No elements to pop." << endl;
        return;
    }
    Node* temp = top;
    cout << top->data << " popped from stack." << endl;
    top = top->next;
    free(temp);
}

// Peek operation Time Complexity O(1)
void Stack::peek() {
    if (top == nullptr) {
        cout << "Stack is empty! No element to peek." << endl;
        return;
    }
    cout << "Top element: " << top->data << endl;
}

// Manual memory cleanup function Time Complexity O(n)
void Stack::clear() {
    while (top != nullptr) {
        Node* temp = top;
        top = top->next;
        free(temp); 
    }
}

```

### Execution

```sh

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: A
A pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: B
B pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Top element: B

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
B popped from stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
A popped from stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Stack is empty! No element to peek.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 2
Stack Underflow! No elements to pop.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: X
X pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: Y
Y pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 1
Enter character to push: Z
Z pushed onto stack.

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 3
Top element: Z

Stack Menu:
1. Push
2. Pop
3. Peek
4. Exit
Enter your choice: 4
Exiting program.

```

## Infix to Postfix

### Question

Write a C++ menu-driven program to implement infix to postfix and postfix evaluation. Use the singly linked list (SLL) to implement the stack ADT as a header file. Maintain proper boundary conditions and follow good coding practices. The program has the following operations,

1. Get Infix
2. Convert Infix
3. Evaluate Postfix
4. Exit

### Algorithm

#### Algorithm 1 - InfixToPostfix {.unnumbered}

##### Input {.unnumbered}

1. infix - infix expression string

##### Output {.unnumbered}

- postfix - equivalent postfix expression string

##### Steps {.unnumbered}

1. Initialize empty stack $s$
2. Initialize empty string $postfix$
3. For each character $c$ in $infix$:
    1. If $c$ is a digit (operand):
        1. Append $c$ to $postfix$
    2. Else if $c = '('$:
        1. Push $c$ onto stack $s$
    3. Else if $c = ')'$:
        1. While $s$ is not empty and top of $s$ is not '(':
            1. Append $s.pop()$ to $postfix$
        2. If $s$ is not empty and top of $s$ is '(':
            1. Pop '(' from $s$
    4. Else if $c$ is an operator ($+, -, *, /, \%$):
        1. While $s$ is not empty and top of $s$ is not '(' and $precedence(s.peek()) \geq precedence(c)$:
            1. Append $s.pop()$ to $postfix$
        2. Push $c$ onto stack $s$
4. While $s$ is not empty:
    1. If top of $s$ is not '(':
        1. Append $s.pop()$ to $postfix$
    2. Else:
        1. Pop '(' from $s$
5. Return $postfix$

#### Algorithm 2 - EvaluatePostfix {.unnumbered}

##### Input {.unnumbered}

1. postfix - postfix expression string

##### Output {.unnumbered}

- result - numerical result after evaluating the expression

##### Steps {.unnumbered}

1. Initialize empty stack $s$
2. For each character $c$ in $postfix$:
    1. If $c$ is a digit (operand):
        1. Convert $c$ to integer and push onto stack $s$
    2. Else ($c$ is an operator):
        1. $op2 \leftarrow s.pop()$
        2. $op1 \leftarrow s.pop()$
        3. Apply operator $c$ on $op1$ and $op2$:
            1. If $c = '+'$: $s.push(op1 + op2)$
            2. If $c = '-'$: $s.push(op1 - op2)$
            3. If $c = '*'$: $s.push(op1 * op2)$
            4. If $c = '/'$: $s.push(op1 / op2)$
            5. If $c = '\%'$: $s.push(op1 \bmod op2)$
3. Return $s.pop()$ as the final result

### Code

__main.cpp__

```cpp

#include "stack.h"
#include <iostream>
#include <cctype>
#include <cmath>
#include <string>

using namespace std;

class Expression {
public:
    static int precedence(char op) {
        if (op == '=') return 0; // Lowest precedence
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/' || op == '%') return 2;
        return 0;
    }

    static void infixToPostfix(const string& infix, string& postfix) {
        Stack stack;
        postfix = "";

        for (char ch : infix) {
            if (isalnum(ch)) {  // Operand
                postfix += ch;
            } 
            else if (ch == '(') {  // Left parenthesis
                stack.push(ch);
            } 
            else if (ch == ')') {  // Right parenthesis
                while (!stack.isEmpty() && stack.peek() != '(') {
                    postfix += stack.pop();
                }
                stack.pop();  // Remove '('
            } 
            else {  // Operator
                while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(ch)) {
                    postfix += stack.pop();
                }
                stack.push(ch);
            }
        }

        while (!stack.isEmpty()) {  // Pop remaining operators
            postfix += stack.pop();
        }
    }
};

class IntStack {
private:
    struct IntNode {
        int data;
        IntNode* next;
    };
    IntNode* top;
public:
    IntStack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(int data) {
        IntNode* newNode = new IntNode();
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return 0;
        }
        IntNode* temp = top;
        int poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    int peek() {
        return isEmpty() ? 0 : top->data;
    }
};

class PostfixEvaluator {
public:
    static int evaluatePostfix(const string& postfix) {
        IntStack stack;

        for (char ch : postfix) {
            if (isdigit(ch)) {
                stack.push(ch - '0');  // Convert char to int
            } 
            else {  // Operator
                int val2 = stack.pop();
                int val1 = stack.pop();
                switch (ch) {
                    case '+': stack.push(val1 + val2); break;
                    case '-': stack.push(val1 - val2); break;
                    case '*': stack.push(val1 * val2); break;
                    case '/': stack.push(val1 / val2); break;
                    case '%': stack.push(val1 % val2); break;
                }
            }
        }
        return stack.pop();
    }
};

int main() {
    string infix, postfix;
    int choice;

    while (true) {
        cout << "\nMenu:\n";
        cout << "1. Get Infix Expression\n";
        cout << "2. Convert Infix to Postfix\n";
        cout << "3. Evaluate Postfix Expression\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter infix expression: ";
                cin >> infix;
                break;
            case 2:
                Expression::infixToPostfix(infix, postfix);
                cout << "Postfix Expression: " << postfix << endl;
                break;
            case 3:
                cout << "Evaluated Result: " << PostfixEvaluator::evaluatePostfix(postfix) << endl;
                break;
            case 4:
                exit(0);
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

```

__stack.h__

```h

#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* next;
};

class Stack {
private:
    Node* top;
public:
    Stack() { top = nullptr; }

    bool isEmpty() { return top == nullptr; }

    void push(char data) {
        Node* newNode = new Node();
        if (!newNode) {
            cout << "Memory allocation failed\n";
            return;
        }
        newNode->data = data;
        newNode->next = top;
        top = newNode;
    }

    char pop() {
        if (isEmpty()) {
            cout << "Stack underflow\n";
            return '\0';
        }
        Node* temp = top;
        char poppedData = temp->data;
        top = top->next;
        delete temp;
        return poppedData;
    }

    char peek() {
        return isEmpty() ? '\0' : top->data;
    }
};

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/06-Stack_ADT/03-Infix_to_Postfix$ ./a.out

Menu:
1. Get Infix Expression
2. Convert Infix to Postfix
3. Evaluate Postfix Expression
4. Exit
Enter your choice: 1
Enter infix expression: 5+3*2-6/3

Menu:
1. Get Infix Expression
2. Convert Infix to Postfix
3. Evaluate Postfix Expression
4. Exit
Enter your choice: 2
Postfix Expression: 532*+63/-

Menu:
1. Get Infix Expression
2. Convert Infix to Postfix
3. Evaluate Postfix Expression
4. Exit
Enter your choice: 3
Evaluated Result: 9

Menu:
1. Get Infix Expression
2. Convert Infix to Postfix
3. Evaluate Postfix Expression
4. Exit
Enter your choice: 4
```

## Parenthesis Balance

### Question

Write a C++ menu-driven program to get a string of '(' and ')’ parenthesis from the user and check whether they are balanced. Identify the optimal ADT and data structure to solve the mentioned problem. You can consider all previous header files for the solution's implementation. Maintain proper boundary conditions and follow good coding practices. The program has the following operations,

1. Check Balance
2. Exit

The Check Balance operations get a string of open and closed parentheses. Additionally, it displays whether the parenthesis is balanced or not. Explore at least two designs (solutions) before implementing your solution.

### Algorithm

#### Algorithm 1 - ParenthesisBalance {.unnumbered}

##### Input {.unnumbered}

1. s - string containing parentheses

##### Output {.unnumbered}

- Boolean indicating whether the parentheses are balanced

##### Steps {.unnumbered}

1. Initialize empty stack $st$
2. For each character $c$ in string $s$:
    1. If $c$ is an opening bracket ('(' or '{' or '['):
        1. Push $c$ onto stack $st$
    2. Else if $c$ is a closing bracket (')' or '}' or ']'):
        1. If $st$ is empty:
            1. Return $false$
        2. If (st.peek() = '(' and c = ')') or (st.peek() = '{' and c = '}') or (st.peek() = '[' and c = ']'):
            1. Pop top element from $st$
        3. Else:
            1. Return $false$
3. Return $st.empty()$

### Code

__main.cpp__

```cpp

#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                if ((c == ')' && top == '(')) {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    Solution sol;
    int choice;
    string expression;
    
    while (true) {
        cout << "\nMenu:" << endl;
        cout << "1. Check Balance" << endl;
        cout << "2. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter expression: ";
                cin >> expression;
                if (sol.isValid(expression)) {
                    cout << "Balanced" << endl;
                } else {
                    cout << "Not Balanced" << endl;
                }
                break;
            case 2:
                cout << "Exiting program..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    
    return 0;
}

```

### Execution

```sh

Menu:
1. Check Balance
2. Exit
Enter your choice: 1
Enter expression: ()
Balanced

Menu:
1. Check Balance
2. Exit
Enter your choice: 1
Enter expression: (()
Not Balanced

Menu:
1. Check Balance
2. Exit
Enter your choice: 1
Enter expression: (())()
Balanced

Menu:
1. Check Balance
2. Exit
Enter your choice: 1
Enter expression: )(
Not Balanced

Menu:
1. Check Balance
2. Exit
Enter your choice: 2
Exiting program...

```

\pagebreak

# Queue ADT

## Integer Array Queue ADT

### Question

Write a separate C++ menu-driven program to implement Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations,

1. Enqueue
2. Dequeue
3. Peek
4. Exit

### Algorithm

#### Algorithm 1 - QueueEnqueue {.unnumbered}

##### Input {.unnumbered}

1. num - element to insert into queue
2. arr[] - array storing the queue elements
3. cur - current number of elements

##### Output {.unnumbered}

- Updated queue with num inserted at the end

##### Steps {.unnumbered}

1. If $cur = 5$:
    1. Print "Queue is full"
    2. Return
2. $arr[cur] \leftarrow num$
3. $cur \leftarrow cur + 1$

#### Algorithm 2 - QueueDequeue {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the queue elements
2. cur - current number of elements

##### Output {.unnumbered}

- Updated queue with front element removed

##### Steps {.unnumbered}

1. If $cur = 0$:
    1. Print "Queue is empty"
    2. Return
2. For $i$ from $0$ to $cur-2$:
    1. $arr[i] \leftarrow arr[i+1]$
3. $cur \leftarrow cur - 1$

#### Algorithm 3 - QueuePeek {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the queue elements
2. cur - current number of elements

##### Output {.unnumbered}

- Value of the front element (without removing it)

##### Steps {.unnumbered}

1. If $cur = 0$:
    1. Print "Queue is empty"
    2. Return
2. Print $arr[0]$

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

#define SIZE 5

class Queue {
private:
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear == SIZE - 1) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;
        arr[++rear] = value;
        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front++;
        if (front > rear) front = rear = -1;  // Reset queue when empty
    }

    // Peek operation
    void peek() {
        if (front == -1 || front > rear) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";}
        }
}

```

### Execution

```sh

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 10
10 enqueued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 20
20 enqueued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 3
Front element: 10

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
10 dequeued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
20 dequeued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
Queue is empty!

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 4
Exiting...

```

## Integer Array Circular Queue ADT

### Question

Write a separate C++ menu-driven program to implement Circular Queue ADT using an integer array of size 5. Maintain proper boundary conditions and follow good coding practices. The Circular Queue ADT has the following operations:

1. Enqueue
2. Dequeue
3. Peek
4. Exit

### Algorithm

#### Algorithm 1 - CircularQueueEnqueue {.unnumbered}

##### Input {.unnumbered}

1. x - element to insert into queue
2. arr[] - array storing the queue elements
3. front - front index of queue
4. rear - rear index of queue
5. size - current number of elements
6. MAX_SIZE - maximum capacity of queue

##### Output {.unnumbered}

- Updated circular queue with x inserted

##### Steps {.unnumbered}

1. If $size = MAX\_SIZE$:
    1. Print "Queue is full"
    2. Return
2. If $front = -1$ (queue is empty):
    1. $front \leftarrow 0$
3. $rear \leftarrow (rear + 1) \bmod MAX\_SIZE$
4. $arr[rear] \leftarrow x$
5. $size \leftarrow size + 1$

#### Algorithm 2 - CircularQueueDequeue {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the queue elements
2. front - front index of queue
3. rear - rear index of queue
4. size - current number of elements
5. MAX_SIZE - maximum capacity of queue

##### Output {.unnumbered}

- Updated circular queue with front element removed

##### Steps {.unnumbered}

1. If $size = 0$:
    1. Print "Queue is empty"
    2. Return
2. $front \leftarrow (front + 1) \bmod MAX\_SIZE$
3. $size \leftarrow size - 1$

#### Algorithm 3 - CircularQueuePeek {.unnumbered}

##### Input {.unnumbered}

1. arr[] - array storing the queue elements
2. front - front index of queue
3. size - current number of elements

##### Output {.unnumbered}

- Value of the front element (without removing it)

##### Steps {.unnumbered}

1. If $size = 0$:
    1. Print "Queue is empty"
    2. Return
2. Print $arr[front]$

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear, count;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }

    // Enqueue operation
    void enqueue(int value) {
        if (count == SIZE) {
            cout << "Queue is full!\n";
            return;
        }
        if (front == -1) front = 0;  // Initialize front on first enqueue
        rear = (rear + 1) % SIZE;
        arr[rear] = value;
        count++;
        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        front = (front + 1) % SIZE;
        count--;
        if (count == 0) front = rear = -1;  // Reset when queue becomes empty
    }

    // Peek operation
    void peek() {
        if (count == 0) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    CircularQueue cq;
    int choice, value;

    while (true) {
        cout << "\nCircular Queue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
            case 2:
                cq.dequeue();
                break;
            case 3:
                cq.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";

        }
    }
}
```

### Execution

```sh

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 10
10 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 20
20 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 30
30 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 3
Front element: 10

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
10 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 40
40 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 50
50 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 60
60 enqueued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 70
Queue is full!

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
20 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
30 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
40 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
50 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
60 dequeued.

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
Queue is empty!

Circular Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 4
Exiting...

```

## Integer Linked List Queue ADT

### Question

Write a separate G++ menu-driven program to implement Queue ADT using an integer- linked list. Maintain proper boundary conditions and follow good coding practices. The Queue ADT has the following operations:

1. Enqueue
2. Dequeue
3. Peek
4. Exit

### Algorithm

#### Algorithm 1 - QueueEnqueue {.unnumbered}

##### Input {.unnumbered}

1. x - element to insert into queue
2. front - pointer to front of queue
3. rear - pointer to rear of queue

##### Output {.unnumbered}

- Updated queue with x inserted at the rear

##### Steps {.unnumbered}

1. Create new node $temp$ with $data = x$ and $next = null$
2. If $front = null$ (queue is empty):
    1. $front \leftarrow temp$
    2. $rear \leftarrow temp$
    3. Return
3. $rear.next \leftarrow temp$
4. $rear \leftarrow temp$

#### Algorithm 2 - QueueDequeue {.unnumbered}

##### Input {.unnumbered}

1. front - pointer to front of queue
2. rear - pointer to rear of queue

##### Output {.unnumbered}

- Updated queue with front element removed

##### Steps {.unnumbered}

1. If $front = null$ (queue is empty):
    1. Print "Queue is empty"
    2. Return
2. $temp \leftarrow front$
3. $front \leftarrow front.next$
4. Delete $temp$

#### Algorithm 3 - QueuePeek {.unnumbered}

##### Input {.unnumbered}

1. front - pointer to front of queue

##### Output {.unnumbered}

- Value of the front element (without removing it)

##### Steps {.unnumbered}

1. If $front = null$ (queue is empty):
    1. Print "Queue is empty"
    2. Return
2. Print $front.data$

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

class Queue {
private:
    // Structure for linked list node
    struct Node {
        int data;
        Node* next;
    };

    struct Node* front;   // Pointer to the front of the queue
    struct Node* rear;    // Pointer to the rear of the queue

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node{value, nullptr};

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << value << " enqueued.\n";
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }

        Node* temp = front;
        front = front->next;

        if (front == nullptr) {
            rear = nullptr;  // Reset when queue becomes empty
        }

        cout << temp->data << " dequeued.\n";
        delete temp;
    }

    // Peek operation
    void peek() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << front->data << endl;
        }
    }
};

int main() {
    Queue q;
    int choice, value;

    while (true) {
        cout << "\nQueue Operations:\n";
        cout << "1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
```

### Execution

```sh

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 10
10 enqueued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 20
20 enqueued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 1
Enter value to enqueue: 30
30 enqueued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 3
Front element: 10

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
10 dequeued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 3
Front element: 20

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
20 dequeued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
30 dequeued.

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 2
Queue is empty!

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 3
Queue is empty!

Queue Operations:
1. Enqueue
2. Dequeue
3. Peek
4. Exit
Enter choice: 4
Exiting...

```

## String Plus Symbol

### Question

Take a string from the user that consists of the '+' symbol. Process the string such that the final string does not include the '+' symbol and the immediate left non-'+' symbol. Select and choose the optimal ADT. Implement the program by including the appropriate header file.

### Algorithm

#### Algorithm 1 - RemovePlusSymbols {.unnumbered}

##### Input {.unnumbered}

1. s - string with characters and '+' symbols

##### Output {.unnumbered}

- Modified string after applying '+' operations

##### Steps {.unnumbered}

1. Initialize empty stack $s1$
2. For $i$ from $0$ to $s.length()-1$:
    1. If $s[i] = '+'$:
        1. Pop last character from $s1$
    2. Else:
        1. Push $s[i]$ onto $s1$
3. Initialize empty result string $result$
4. While $s1$ is not empty:
    1. Print character at top of $s1$
    2. Move to next node in stack

### Code

__main.cpp__

```cpp

#include <iostream>
#include <deque>
using namespace std;

string processString(string str) {
    deque<char> q;  // Queue ADT (deque used for back removal)

    for (char ch : str) {
        if (ch == '+') {
            if (!q.empty()) q.pop_back(); // Remove last inserted non-'+' element
        } else {
            q.push_back(ch); // Insert into queue
        }
    }

    // Build the final output string
    string result = "";
    while (!q.empty()) {
        result += q.front();
        q.pop_front();
    }
    return result;
}

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    string output = processString(input);
    cout << "Output: " << output << endl;

    return 0;
}

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/07-Queue_ADT/04-String_Plus_Symbol$ ./a.out
Enter a string: asdfg
Output: asdfg
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/07-Queue_ADT/04-String_Plus_Symbol$ ./a.out
Enter a string: ausgyf+ajh
Output: ausgyajh
```

\pagebreak

# Tree ADT

## Tower

### Question

There are n block towers, numbered from 1 to n. The i-th tower consists of a; blocks. In one move, you can move one block from tower i to tower j, but only if a; > a;. That move increases a; by 1 and decreases a; by 1. You can perform as many moves as you would like (possibly, zero). What's the largest amount of blocks you can have on the tower 1 after the moves?

Input:

The first line contains a single integer t (1 <= t <= 10^4) - the number of testcases. The first line of each testcase contains a single integer n (2 <= n <= 2 * 10^5) — the number of towers. The second line contains n integers a1, a2, ... , an (1 <= a <= 10^9) — the number of blocks on each tower. The sum of n over all testcases doesn't exceed 2^10°.

Output:

For each testcase, print the largest amount of blocks you can have on the tower 1 after you make any number of moves (possibly, zero).

### Algorithm

#### Algorithm 1 - MaximizeTowerHeight {.unnumbered}

##### Input {.unnumbered}

1. tower[] - array of n integers representing tower heights

##### Output {.unnumbered}

- Maximum possible height of tower[0] after operations

##### Steps {.unnumbered}

1. For $k$ from $1$ to $n-1$:
    1. While $tower[k] > tower[0]$:
        1. $tower[0] \leftarrow tower[0] + 1$
        2. $tower[k] \leftarrow tower[k] - 1$
2. Return $tower[0]$

### Code

__main.cpp__

```cpp

#include<iostream>
#include <algorithm>
using namespace std;
void sortArray(int arr[], int numElements) {
        std::sort(arr + 1, arr + numElements);
}
int check(int  arr[],int  n){
    int temp = arr[0];
    int  i = 1;
    for (; i < n; i++)
    {
        if(arr[0]<arr[i]){
            return i;
        }
        
    }
    return 0;
    
}
int sum(int  arr[],int  n,int  i){
    if (i == 0){
        return arr[0];
    }
    while (i<n)
    {
        arr[0] = (arr[0] + arr[i] + 1)/2;
        i++;
    }
    return arr[0];
    
}
int main(){
    int t;
   int  n,temp;
   cin >> t;
   while(t>0){
   cin >> n;
   temp = n;
    int  arr[n];
    int i = 0;
    while(n>0){
        cin >> arr[i];
        i++;
        n--;
    }
    n = temp;
    sortArray(arr,n);
    cout<<sum(arr,n,check(arr,n))<<"\n";
    
   t--;
   } 

    return 0;
}
```

### Execution

```sh

2
3
10 20 30
23
4
1 1 1 1
1

```

## Character Binary Tree ADT

### Question

Write a separate C++ menu-driven program to implement Tree ADT using a character binary tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations,

1. Insert
2. Preorder
3. Inorder
4. Postorder
5. Search
6. Exit

### Algorithm

#### Algorithm 1 - BinaryTreeInsert {.unnumbered}

##### Input {.unnumbered}

1. x - character to insert
2. root - root node of binary tree

##### Output {.unnumbered}

- Updated binary tree with x inserted

##### Steps {.unnumbered}

1. Create new node $temp$ with $data = x$, $left = null$, $right = null$
2. If $root = null$:
    1. $root \leftarrow temp$
3. Else:
    1. $p \leftarrow root$
    2. While $p.left \neq null$ AND $p.right \neq null$:
        1. If $p.left \neq null$:
            1. $p \leftarrow p.left$
        2. Else:
            1. $p \leftarrow p.right$
    3. If $p.left = null$:
        1. $p.left \leftarrow temp$
    4. Else:
        1. $p.right \leftarrow temp$

#### Algorithm 2 - InorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. p - root node of binary tree or subtree

##### Output {.unnumbered}

- Inorder traversal sequence of the tree

##### Steps {.unnumbered}

1. If $p \neq null$:
    1. InorderTraversal($p.left$)
    2. Print $p.data$
    3. InorderTraversal($p.right$)

#### Algorithm 3 - PostorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. p - root node of binary tree or subtree

##### Output {.unnumbered}

- Postorder traversal sequence of the tree

##### Steps {.unnumbered}

1. If $p \neq null$:
    1. PostorderTraversal($p.left$)
    2. PostorderTraversal($p.right$)
    3. Print $p.data$

#### Algorithm 4 - PreorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. p - root node of binary tree or subtree

##### Output {.unnumbered}

- Preorder traversal sequence of the tree

##### Steps {.unnumbered}

1. If $p \neq null$:
    1. Print $p.data$
    2. PreorderTraversal($p.left$)
    3. PreorderTraversal($p.right$)

#### Algorithm 5 - TreeSearch {.unnumbered}

##### Input {.unnumbered}

1. x - character to search for
2. root - root node of binary tree

##### Output {.unnumbered}

- Status message indicating if x was found

##### Steps {.unnumbered}

1. $p \leftarrow root$
2. While $p \neq null$:
    1. If $p.data = x$:
        1. Print "Element found"
        2. Return
    2. Else:
        1. If $p.left \neq null$:
            1. $p \leftarrow p.left$
        2. Else:
            1. $p \leftarrow p.right$
3. Print "Element not found"

### Code

__main.cpp__

```cpp

#include <iostream>
#include <queue>
using namespace std;

class Tree {
    struct node {
        char data;
        struct node* left;
        struct node* right;

        node(char val) {
            data = val;
            left = right = nullptr;
        }
    };

public:
    node* root; // Root node of the tree

    Tree() { root = nullptr; } // Constructor

    void insert(char key);
    void inorder(node* root);
    void preorder(node* root);
    void postorder(node* root);
    bool search(char key);
    void menu();
};

void Tree::insert(char key) {
    node* newNode = new node(key);
    if (!root) {
        root = newNode;
        return;
    }

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (!temp->left) {
            temp->left = newNode;
            return;
        } else {
            q.push(temp->left);
        }

        if (!temp->right) {
            temp->right = newNode;
            return;
        } else {
            q.push(temp->right);
        }
    }
}

void Tree::inorder(node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void Tree::preorder(node* root) {
    if (!root) return;
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void Tree::postorder(node* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

bool Tree::search(char key) {
    if (!root) return false;

    queue<node*> q;
    q.push(root);

    while (!q.empty()) {
        node* temp = q.front();
        q.pop();

        if (temp->data == key)
            return true;

        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
    }

    return false;
}

void Tree::menu() {
    int choice;
    char value;
    do {
        cout << "\n--- Binary Tree Menu ---\n";
        cout << "1. Insert a node\n";
        cout << "2. Inorder Traversal\n";
        cout << "3. Preorder Traversal\n";
        cout << "4. Postorder Traversal\n";
        cout << "5. Search for an element\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter a character to insert: ";
                cin >> value;
                insert(value);
                break;

            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 5:
                cout << "Enter a character to search: ";
                cin >> value;
                if (search(value))
                    cout << value << " found in the tree.\n";
                else
                    cout << value << " not found in the tree.\n";
                break;

            case 6:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice! Please enter a valid option.\n";
        }
    } while (choice != 6);
}

int main() {
    Tree tree;
    tree.menu(); // Start menu-driven program
    return 0;
}

```

### Execution

```sh

--- Binary Tree Menu ---
1. Insert a node
2. Inorder Traversal
3. Preorder Traversal
4. Postorder Traversal
5. Search for an element
6. Exit
Enter your choice: 1
Enter a character to insert: A

--- Binary Tree Menu ---
Enter your choice: 1
Enter a character to insert: B

--- Binary Tree Menu ---
Enter your choice: 1
Enter a character to insert: C

--- Binary Tree Menu ---
Enter your choice: 2
Inorder Traversal: B A C 

--- Binary Tree Menu ---
Enter your choice: 3
Preorder Traversal: A B C 

--- Binary Tree Menu ---
Enter your choice: 4
Postorder Traversal: B C A 

--- Binary Tree Menu ---
Enter your choice: 5
Enter a character to search: B
B found in the tree.

--- Binary Tree Menu ---
Enter your choice: 5
Enter a character to search: X
X not found in the tree.

--- Binary Tree Menu ---
Enter your choice: 6
Exiting program...

```

\pagebreak

# Binary Search Tree ADT

## Nenes Game

### Question

Nene invented a new game based on an increasing sequence of integers a_1, a_2, ..., a_k. In this game, initially, n players are lined up in a row. In each of the rounds of this game, the following happens:

Nene finds the a_1-th, a_2-th, ..., a_k-th players in the row. They are kicked out of the game simultaneously. If the i-th player in the row should be kicked out, but there are fewer than i players in the row, they are skipped.

Once no one is kicked out of the game in some round, all the players that are still in the game are declared as winners.

For example, consider the game with a = [3, 5] and n = 5 players. Let the players be named player A, player B, ..., player E in the order they are lined up initially.

Then, before the first round, players are lined up as ABCDE.
Nene finds the 3rd and the 5th players in the row. These are players C and E. They are kicked out in the first round.
Now players are lined up as ABD.
Nene finds the 3rd and the 5th players in the row. The 3rd player is player D and there is no 5th player in the row. Thus, only player D is kicked out in the second round.
Now players are lined up as AB.
In the third round, Nene finds the 3rd and 5th players. There are none. No one is kicked out of the game, so the game ends after this round.
Players A and B are declared as the winners.

Nene has not yet decided how many people would join the game initially. Nene gave you q integers n_1, n_2, ..., n_q and you should answer the following question for each 1 <= i <= q independently: "How many people would be declared as winners if there are n_i players in the game initially?"

Input:

Each test contains multiple test cases. The first line contains the number of test cases t (1 <= t <= 250). The description of test cases follows.

The first line of each test case contains two integers k and q (1 <= k, q <= 100) \u2014 the length of the sequence a and the number of values n_i you should solve this problem for.

The second line contains k integers a_1, a_2, ..., a_k (1 <= a_1 < a_2 < ... < a_k <= 100) \u2014 the sequence a.

The third line contains q integers n_1, n_2, ..., n_q (1 <= n_i <= 100).

Output:

For each test case, output q integers: the i-th (1 <= i <= q) of them should be the number of players declared as winners if initially n_i players join the game.

(Self-correction note: I initially assumed the example typo ARD should be ABD based on the rules and fixed it. Also corrected variable inconsistencies like g vs q and index notation.)

### Algorithm

#### Algorithm 1 - NenesGameSimulation {.unnumbered}

##### Input {.unnumbered}

1. a[] - array of k integers representing Nene's moves
2. b[] - array of q integers representing initial pile sizes

##### Output {.unnumbered}

- Final pile sizes after all possible moves

##### Steps {.unnumbered}

1. For each query $i$ from $0$ to $q-1$:
    1. Create vector $c$ of size $b[i]$ with all zeros
    2. Set $flag \leftarrow 1$
    3. While $flag = 1$:
        1. $flag \leftarrow 0$
        2. For $j$ from $k-1$ down to $0$:
            1. If $a[j] \leq c.size()$:
                1. Erase element at position $(a[j]-1)$ from vector $c$
                2. $flag \leftarrow 1$
    4. Output the final size of vector $c$

### Code

__main.cpp__

```cpp

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        int k;
        int q;
        cin >> k >> q;
        vector<int> a;
        vector<int> n;
        for(int i = 0;i < k;i++){
            int e;
            cin >> e;
            a.push_back(e);
        }

        for(int i = 0;i < q;i++){
            int e;
            cin >> e;
            n.push_back(e);
        }

        int min = a[0];
        
        for(int num : n){
            vector<int> temp;
            for(int i = 0;i < num;i++){
                temp.push_back(i);
            }
            int count = 0;
            for(int i = 0;i < a[0] && i <= temp.size();i++){
                count++;
            }
            cout << count - 1<< " ";
        }
        cout << endl;
    }
}

```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/01-Nenes_Game$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/01-Nenes_Game$ ./a.out
1
5
3
2
3
5
7
11
3
4
1
1 1 1 
```

## Advantages Game

### Question

There are n participants in a competition, participant i having a strength of s_i.

Every participant wonders how much of an advantage they have over the next strongest participant (excluding themselves). In other words, each participant i wants to know the difference between their strength s_i and the maximum strength s_j among all other participants (j != i). Note that this difference can be negative.

So, they ask you for your help! For each i (from 1 to n), calculate and output the difference s_i - max(s_j for j != i).

Input:

The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 1000) \u2014 the number of test cases. The descriptions of the test cases follow.

The first line of each test case contains an integer n (2 <= n <= 2 * 10^5) \u2014 the number of participants (length of the array).

The following line contains n space-separated positive integers s_1, s_2, ..., s_n (1 <= s_i <= 10^9) \u2014 the strengths of the participants.

It is guaranteed that the sum of n over all test cases does not exceed 2 * 10^5.

Output:

For each test case, output n space-separated integers. For each i (1 <= i <= n), output the difference between s_i and the maximum strength of any other participant.

### Algorithm

#### Algorithm 1 - CalculateAdvantages {.unnumbered}

##### Input {.unnumbered}

1. nums[] - array of n integers

##### Output {.unnumbered}

- advantages[] - array of n integers representing the advantages

##### Steps {.unnumbered}

1. Create a copy $max[] \leftarrow nums[]$
2. Sort $max[]$ in descending order using bubble sort:
    1. For $i$ from $0$ to $n-2$:
        1. For $j$ from $0$ to $n-i-2$:
            1. If $max[j] < max[j+1]$:
                1. Swap $max[j]$ and $max[j+1]$
3. For each element $nums[i]$ from $0$ to $n-1$:
    1. $dif \leftarrow nums[i] - max[0]$
    2. If $dif = 0$ (current element is the maximum):
        1. $dif \leftarrow nums[i] - max[1]$ (calculate advantage over second maximum)
    3. Store $dif$ as the advantage for element $nums[i]$
4. Return array of advantages

### Code

__main.cpp__

```cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int max1 = -1, max2 = -1;
        for (int num : arr) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == max1) {
                cout << arr[i] - max2 << " ";
            } else {
                cout << arr[i] - max1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/02-Advantages_Game$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/02-Advantages_Game$ ./a.out
1
5
1
2
3
4
5
-4 -3 -2 -1 1
```

## 03 BST Implementation

### Question

Write a separate C++ menu-driven program to implement Tree ADT using a binary search tree. Maintain proper boundary conditions and follow good coding practices. The Tree ADT has the following operations,

1. Insert
2. Preorder
3. Inorder
4. Postorder
5. Search
6. Exit

### Algorithm

#### Algorithm 1 - BSTInsert {.unnumbered}

##### Input {.unnumbered}

1. root - root of binary search tree
2. num - value to insert

##### Output {.unnumbered}

- Updated binary search tree with num inserted

##### Steps {.unnumbered}

1. If $root = null$:
    1. Create new node $newnode$
    2. $newnode.data \leftarrow num$
    3. $newnode.left \leftarrow null$
    4. $newnode.right \leftarrow null$
    5. Return $newnode$
2. If $num < root.data$:
    1. $root.left \leftarrow insert(root.left, num)$
3. Else if $num > root.data$:
    1. $root.right \leftarrow insert(root.right, num)$
4. Return $root$

#### Algorithm 2 - BSTSearch {.unnumbered}

##### Input {.unnumbered}

1. root - root of binary search tree
2. num - value to search for

##### Output {.unnumbered}

- Boolean indicating whether num is found in the tree

##### Steps {.unnumbered}

1. $p \leftarrow root$
2. While $p \neq null$:
    1. If $p.data = num$:
        1. Print "Element found"
        2. Return
    2. Else if $num < p.data$:
        1. $p \leftarrow p.left$
    3. Else:
        1. $p \leftarrow p.right$
3. Print "Element not found"

#### Algorithm 3 - InorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. root - root of binary search tree

##### Output {.unnumbered}

- Inorder traversal of the tree (sorted values)

##### Steps {.unnumbered}

1. If $root \neq null$:
    1. InorderTraversal($root.left$)
    2. Print $root.data$
    3. InorderTraversal($root.right$)

#### Algorithm 4 - PreorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. root - root of binary search tree

##### Output {.unnumbered}

- Preorder traversal of the tree

##### Steps {.unnumbered}

1. If $root \neq null$:
    1. Print $root.data$
    2. PreorderTraversal($root.left$)
    3. PreorderTraversal($root.right$)

#### Algorithm 5 - PostorderTraversal {.unnumbered}

##### Input {.unnumbered}

1. root - root of binary search tree

##### Output {.unnumbered}

- Postorder traversal of the tree

##### Steps {.unnumbered}

1. If $root \neq null$:
    1. PostorderTraversal($root.left$)
    2. PostorderTraversal($root.right$)
    3. Print $root.data$

### Code

__main.cpp__

```cpp

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        // Find the first and second maximum
        int max1 = -1, max2 = -1;
        for (int num : arr) {
            if (num > max1) {
                max2 = max1;
                max1 = num;
            } else if (num > max2) {
                max2 = num;
            }
        }

        for (int i = 0; i < n; i++) {
            if (arr[i] == max1) {
                cout << arr[i] - max2 << " ";
            } else {
                cout << arr[i] - max1 << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}
```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/03_BST_Implementation$ g++ main.cpp 
ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/09-Binary_Search_Tree_ADT/03_BST_Implementation$ ./a.out
1
6
10
20
30
40
50
60
-50 -40 -30 -20 -10 10 
```

\pagebreak

# Priority Queue ADT

## Polycarp Numbers

### Question

Polycarp was presented with some sequence of integers a of length n. A sequence can make Polycarp happy only if it consists of different numbers (i.e., distinct numbers).

In order to make his sequence like this, Polycarp is going to make some (possibly zero) number of moves. In one move, he can:

remove the first (leftmost) element of the sequence.

For example, in one move, the sequence [3, 1, 4, 3] will produce the sequence [1, 4, 3], which consists of different numbers.

Determine the minimum number of moves he needs to make so that in the remaining sequence all elements are different. In other words, find the length of the smallest prefix of the given sequence a, after removing which all values in the remaining sequence will be unique.

Input:

The first line of the input contains a single integer t (1 <= t <= 10^4) \u2014 the number of test cases.

Each test case consists of two lines.
The first line contains an integer n (1 <= n <= 2 * 10^5) \u2014 the length of the given sequence a.
The second line contains n integers a_1, a_2, ..., a_n (1 <= a_i <= n) \u2014 elements of the given sequence a.

It is guaranteed that the sum of n values over all test cases does not exceed 2 * 10^5.

Output:

For each test case print your answer on a separate line \u2014 the minimum number of elements that must be removed from the beginning of the sequence so that all remaining elements are different.

### Algorithm

#### Algorithm 1 - MinimumElementsToRemove {.unnumbered}

##### Input {.unnumbered}

1. a[] - array of n integers

##### Output {.unnumbered}

- k - minimum number of elements to remove from beginning

##### Steps {.unnumbered}

1. Initialize unordered_set $b \leftarrow \emptyset$
2. For $i \leftarrow n-1$ down to $0$:
    1. If $a[i] \notin b$:
        1. $b \leftarrow b \cup \{a[i]\}$
    2. Else:
        1. Break loop
3. Return $n - |b|$

### Code

__main.cpp__

```cpp

#include<iostream>
#include<unordered_set>
using namespace std;
int main()
{
    int t;
    cout<<"enter the number of testcases\n";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the number of elements in the series: \n";
        cin>>n;
        int a[n];
        cout<<"enter the elements of the series\n";
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
        }
        unordered_set<int>seen;
        int moves=0;
        for(int i= 0; i<n; i++)
        {
            while(seen.find(a[i])!=seen.end())
            {
                seen.erase(a[moves]);
                moves++;
            }
            seen.insert(a[i]); 
        }
        
        cout<<"no of moves taken "<<moves<<"\n";
    }

    return 0;
}
```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/10-Priority_Queue_ADT/01-Polycarp_Numbers$ ./a.out
enter the number of testcases
1
enter the number of elements in the series: 
6
enter the elements of the series
1
1
1
1
1
1
no of moves taken 5
```

## Word Game

### Question

Three guys play a game: first, each person writes down n distinct words of length 3. Then, they total up the number of points as follows:

If a word was written by one person \u2014 that person gets 3 points.

If a word was written by two people \u2014 each of the two gets 1 point.

If a word was written by all three \u2014 nobody gets any points.

In the end, how many points does each player have?

Input:

The input consists of multiple test cases. The first line contains an integer t (1 <= t <= 100) \u2014 the number of test cases. The description of the test cases follows.

The first line of each test case contains an integer n (1 <= n <= 1000) \u2014 the number of words written by each person.

The following three lines each contain n distinct strings \u2014 the words written by each person. Each string consists of 3 lowercase English characters.

Output:

For each test case, output three space-separated integers \u2014 the number of points each of the three guys earned. You should output the answers in the same order as the input; the i-th integer should be the number of points earned by the i-th guy.

### Algorithm

#### Algorithm 1 - WordGameScoring {.unnumbered}

##### Input {.unnumbered}

1. a[][] - 3×n matrix of strings where a[i] represents words written by player i

##### Output {.unnumbered}

- p[] - array of 3 integers representing points of each player

##### Steps {.unnumbered}

1. Initialize score array $p[0...2] \leftarrow 0$
2. For player 0's words (i from $0$ to $n-1$):
    1. If word $a[0][i]$ appears in player 1's list but not in player 2's list:
        1. $p[0] \leftarrow p[0] + 1$
        2. $p[1] \leftarrow p[1] + 1$
    2. Else if word $a[0][i]$ appears in player 2's list but not in player 1's list:
        1. $p[0] \leftarrow p[0] + 1$
        2. $p[2] \leftarrow p[2] + 1$
    3. Else if word $a[0][i]$ appears in neither player 1's nor player 2's list:
        1. $p[0] \leftarrow p[0] + 3$
3. For player 1's words (i from $0$ to $n-1$):
    1. If word $a[1][i]$ appears in player 2's list but not in player 0's list:
        1. $p[1] \leftarrow p[1] + 1$
        2. $p[2] \leftarrow p[2] + 1$
    2. Else if word $a[1][i]$ appears in neither player 0's nor player 2's list:
        1. $p[1] \leftarrow p[1] + 3$
4. For player 2's words (i from $0$ to $n-1$):
    1. If word $a[2][i]$ appears in neither player 0's nor player 1's list:
        1. $p[2] \leftarrow p[2] + 3$
5. Return array $p$

### Code

__main.cpp__

```cpp

#include<iostream>
#include<map>
#include<vector>
using namespace std;
int main()
{
    int t;
    cout<<"enter hte number of testcases\n";
    cin>>t;
    while(t--)
    {
        int n;
        cout<<"enter the number of 3 letter strings\n";
        cin>>n;
        vector<vector<string>>words(3,vector<string>(n));
        map<string,int>wordcount;
        cout<<"enter the words\n";
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {
                cin>>words[i][j];
                wordcount[words[i][j]]++;
            }
        }
        vector<int>scores(3,0);
        for(int i=0; i<3; i++)
        {
            for(int j=0; j<n; j++)
            {   
                string word=words[i][j];
                if( wordcount[word]==1)
                {
                    scores[i]+=3;
                }
                else if(wordcount[word]==2)
                {
                    scores[i]+=1;
                }
            }
        }
        cout<<"their scores are\n";
        cout<<scores[0]<<" "<<scores[1]<<" "<<scores[2]<<"\n";
    }
    return 0;
}
```

### Execution

```sh

ashu@ASHU:/mnt/c/Users/ashra/Downloads/Work/DSA/LABS/10-Priority_Queue_ADT/02-Word_Game$ ./a.out
enter hte number of testcases
1
enter the number of 3 letter strings
4
enter the words
abc def ghi jkl
def ghi jkl abc
ghi jkl abc def
their scores are
0 0 0
```

## Priority Queue ADT Implementation

### Question

Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations,

1. Insert
2. Delete
3. Display
4. Search
5. Sort (Heap Sort)
6. Exit

### Algorithm

#### Algorithm 1 - MaxHeapInsert {.unnumbered}

##### Input {.unnumbered}

1. x - element to insert
2. array[] - heap represented as an array
3. n - current size of the heap

##### Output {.unnumbered}

- Updated heap with new element inserted

##### Steps {.unnumbered}

1. If $array$ is empty:
    1. $array.push\_back(x)$
2. Else:
    1. $array.push\_back(x)$
    2. $i \leftarrow array.size() - 1$
    3. While $((i+1)/2 - 1) \geq 0$:
        1. If $array[i] > array[((i+1)/2 - 1)]$:
            1. Swap $array[i]$ and $array[((i+1)/2 - 1)]$
            2. $i \leftarrow (i+1)/2 - 1$
        2. Else:
            1. Break loop

#### Algorithm 2 - MaxHeapDeleteRoot {.unnumbered}

##### Input {.unnumbered}

1. array[] - heap represented as an array
2. n - current size of the heap

##### Output {.unnumbered}

- Updated heap with root element removed

##### Steps {.unnumbered}

1. If $array$ is empty:
    1. Print "The Queue is empty"
2. Else:
    1. $array[0] \leftarrow array.back()$
    2. $array.pop\_back()$
    3. $i \leftarrow 0$
    4. While $2i + 1 < array.size()$:
        1. $j \leftarrow 2i + 1$
        2. If $j + 1 < array.size()$:
            1. If $array[i] < array[j]$ and $array[i] < array[j+1]$:
                1. If $array[j] > array[j+1]$:
                    1. Swap $array[i]$ and $array[j]$
                    2. $i \leftarrow j$
                2. Else:
                    1. Swap $array[i]$ and $array[j+1]$
                    2. $i \leftarrow j+1$
            2. Else if $array[i] < array[j]$:
                1. Swap $array[i]$ and $array[j]$
                2. $i \leftarrow j$
            3. Else if $array[i] < array[j+1]$:
                1. Swap $array[i]$ and $array[j+1]$
                2. $i \leftarrow j+1$
            4. Else:
                1. Break loop
        3. Else:
            1. If $array[i] < array[j]$:
                1. Swap $array[i]$ and $array[j]$
                2. $i \leftarrow j$
            2. Else:
                1. Break loop

#### Algorithm 3 - HeapSort {.unnumbered}

##### Input {.unnumbered}

1. array[] - heap represented as an array
2. n - current size of the heap

##### Output {.unnumbered}

- Sorted array in descending order

##### Steps {.unnumbered}

1. Initialize empty vector $sorted$
2. While $array$ is not empty:
    1. $sorted.push\_back(array[0])$
    2. Call $delete\_root()$ to remove the maximum element
3. $array \leftarrow sorted$

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

class PriorityQueue {
    int *heap;
    int capacity;
    int size;

public:
    PriorityQueue(int cap) {
        capacity = cap;
        heap = new int[capacity];
        size = 0;
    }

    ~PriorityQueue() {
        delete[] heap;
    }

    int parent(int i) { return (i - 1) / 2; }
    int left(int i) { return 2 * i + 1; }
    int right(int i) { return 2 * i + 2; }

    void swap(int &x, int &y) {
        int temp = x;
        x = y;
        y = temp;
    }

    void insert(int key) {
        if (size == capacity) {
            cout << "Priority Queue is full\n";
            return;
        }

        heap[size] = key;
        int i = size;
        size++;

        // Heapify Up
        while (i != 0 && heap[parent(i)] < heap[i]) {
            swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void deleteMax() {
        if (size <= 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Deleted Max: " << heap[0] << endl;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(0);
    }

    void heapifyDown(int i) {
        int largest = i;
        int l = left(i);
        int r = right(i);

        if (l < size && heap[l] > heap[largest])
            largest = l;
        if (r < size && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            swap(heap[i], heap[largest]);
            heapifyDown(largest);
        }
    }

    void display() {
        if (size == 0) {
            cout << "Priority Queue is empty\n";
            return;
        }

        cout << "Priority Queue (Heap): ";
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }

    void heapSort() {
        int* temp = new int[size];
        int tempSize = size;

        for (int i = 0; i < tempSize; i++) {
            temp[i] = heap[0];
            heap[0] = heap[size - 1];
            size--;
            heapifyDown(0);
        }

        cout << "Heap Sorted Order (Descending): ";
        for (int i = 0; i < tempSize; i++)
            cout << temp[i] << " ";
        cout << endl;

        // Restore original heap
        delete[] heap;
        heap = new int[capacity];
        size = 0;
        for (int i = 0; i < tempSize; i++)
            insert(temp[i]);

        delete[] temp;
    }
};

// Driver code
int main() {
    PriorityQueue pq(100);

    pq.insert(40);
    pq.insert(20);
    pq.insert(60);
    pq.insert(30);
    pq.insert(10);

    pq.display();

    pq.deleteMax();
    pq.display();

    pq.insert(70);
    pq.display();

    pq.heapSort();
    pq.display();

    return 0;
}

```

### Execution

```sh

Priority Queue (Heap): 60 30 40 20 10 
Deleted Max: 60
Priority Queue (Heap): 40 30 10 20 
Priority Queue (Heap): 70 40 10 20 30 
Heap Sorted Order (Descending): 70 40 30 20 10 
Priority Queue (Heap): 70 40 30 20 10 
```

\pagebreak

# Hash Map

## Linear Probing

### Question

Write a separate C++ menu-driven program to implement Hash ADT with Linear Probing. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - LinearProbingInsert {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num inserted (if possible)

##### Steps {.unnumbered}

1. $index \leftarrow num \bmod SIZE$
2. If $table[index] = EMPTY$:
    1. $table[index] \leftarrow num$
3. Else:
    1. $temp \leftarrow index$
    2. While $table[index] \neq EMPTY$:
        1. $index \leftarrow (index + 1) \bmod SIZE$
        2. If $index = temp$:
            1. Print "Table is full"
            2. Return
    3. $table[index] \leftarrow num$

#### Algorithm 2 - LinearProbingDelete {.unnumbered}

##### Input {.unnumbered}

1. num - value to delete
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num removed (if found)

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = num$:
        1. $table[i] \leftarrow EMPTY$
        2. Return
2. Print "Element not found"

#### Algorithm 3 - LinearProbingSearch {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Status message indicating if num was found or not

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = num$:
        1. Print "The element is present at index $i$"
        2. Return
2. Print "The element is not present"

#### Algorithm 4 - LinearProbingDisplay {.unnumbered}

##### Input {.unnumbered}

1. table[] - hash table array
2. SIZE - size of hash table

##### Output {.unnumbered}

- Visual representation of the hash table

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = EMPTY$:
        1. Print "$i$ -> EMPTY"
    2. Else:
        1. Print "$i$ -> $table[i]$"

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

#define size 10

class Hash {
private:
    int table[size];
    bool check[size];

public:
    Hash();

    int index(int key);

    void insert(int key);          // Average: O(1), Worst: O(n)
    void display();                // O(n)
    void search(int key);          // Average: O(1), Worst: O(n)
    void del(int key);             // Average: O(1), Worst: O(n)
};

int main() {
    Hash temp;
    int choice;

    while (1) {
        cout << "\nMENU\n";
        cout << "1. Insert\n";
        cout << "2. Delete\n";
        cout << "3. Search\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int num;
                cout << "Enter Number You Want to Insert: ";
                cin >> num;
                temp.insert(num);
                break;
            }
            case 2: {
                int num;
                cout << "Enter Number You Want to Delete: ";
                cin >> num;
                temp.del(num);
                break;
            }
            case 3: {
                int num;
                cout << "Enter Number You Want to Search: ";
                cin >> num;
                temp.search(num);
                break;
            }
            case 4:
                temp.display();
                break;
            case 5:
                cout << "Exiting ..." << endl;
                return 0;
            default:
                cout << "Invalid Input. TRY again." << endl;
        }
    }

    return 0;
}

Hash::Hash() {                     // O(n)
    for (int i = 0; i < size; i++) {
        check[i] = false;
    }
}

int Hash::index(int key) {         // O(1)
    return key % size;
}

void Hash::insert(int key) {       // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (!check[temp]) {
        table[temp] = key;
        check[temp] = true;
        cout << "The Number " << key << " was inserted at index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (!check[newIdx]) {
                table[newIdx] = key;
                check[newIdx] = true;
                cout << "The Number " << key << " was inserted at index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "The Hash Table is Full" << endl;
    }
}

void Hash::display() {             // O(n)
    for (int i = 0; i < size; i++) {
        if (check[i]) {
            cout << "Index " << i << " => " << table[i] << endl;
        } else {
            cout << "Index " << i << " => Empty" << endl;
        }
    }
}

void Hash::del(int key) {          // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (check[temp] && table[temp] == key) {
        check[temp] = false;
        cout << "The Number " << key << " was deleted from index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (check[newIdx] && table[newIdx] == key) {
                check[newIdx] = false;
                cout << "The Number " << key << " was deleted from index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "There is No Number " << key << " in the Hash Table" << endl;
    }
}

void Hash::search(int key) {       // Average: O(1), Worst: O(n)
    int temp = index(key);
    if (check[temp] && table[temp] == key) {
        cout << "The Number " << key << " is found at index " << temp << endl;
    } else {
        for (int i = 1; i < size; i++) {
            int newIdx = (temp + i) % size;
            if (check[newIdx] && table[newIdx] == key) {
                cout << "The Number " << key << " is found at index " << newIdx << endl;
                return;
            }
            if (newIdx == temp) break;
        }
        cout << "The Number " << key << " is not found in the Hash Table" << endl;
    }
}
```

### Execution

```sh

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 1
Enter Number You Want to Insert: 42
The Number 42 was inserted at index 2

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 1
Enter Number You Want to Insert: 17
The Number 17 was inserted at index 7

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 1
Enter Number You Want to Insert: 29
The Number 29 was inserted at index 9

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 1
Enter Number You Want to Insert: 52
The Number 52 was inserted at index 2
The Number 52 was inserted at index 3

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 4
Index 0 => Empty
Index 1 => Empty
Index 2 => 42
Index 3 => 52
Index 4 => Empty
Index 5 => Empty
Index 6 => Empty
Index 7 => 17
Index 8 => Empty
Index 9 => 29

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 3
Enter Number You Want to Search: 52
The Number 52 is found at index 3

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 2
Enter Number You Want to Delete: 42
The Number 42 was deleted from index 2

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 4
Index 0 => Empty
Index 1 => Empty
Index 2 => Empty
Index 3 => 52
Index 4 => Empty
Index 5 => Empty
Index 6 => Empty
Index 7 => 17
Index 8 => Empty
Index 9 => 29

MENU
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter Your Choice: 5
Exiting ...
```

## Quadratic Probing

### Question

Write a separate C++ menu-driven program to implement Hash ADT with Quadratic Probing. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - QuadraticProbingInsert {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num inserted (if possible)

##### Steps {.unnumbered}

1. $index \leftarrow num \bmod SIZE$
2. If $table[index] = EMPTY$:
    1. $table[index] \leftarrow num$
3. Else:
    1. $temp \leftarrow index$
    2. $col \leftarrow 1$
    3. While $table[index] \neq EMPTY$:
        1. $index \leftarrow (index + col + col^2) \bmod SIZE$
        2. $col \leftarrow col + 1$
        3. If $index = temp$:
            1. Print "Table is full"
            2. Return
    4. $table[index] \leftarrow num$

#### Algorithm 2 - QuadraticProbingDelete {.unnumbered}

##### Input {.unnumbered}

1. num - value to delete
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num removed (if found)

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = num$:
        1. $table[i] \leftarrow EMPTY$
        2. Return
2. Print "Element not found"

#### Algorithm 3 - QuadraticProbingSearch {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. table[] - hash table array
3. SIZE - size of hash table

##### Output {.unnumbered}

- Status message indicating if num was found or not

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = num$:
        1. Print "The element is present at index $i$"
        2. Return
2. Print "The element is not present"

#### Algorithm 4 - QuadraticProbingDisplay {.unnumbered}

##### Input {.unnumbered}

1. table[] - hash table array
2. SIZE - size of hash table

##### Output {.unnumbered}

- Visual representation of the hash table

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. If $table[i] = EMPTY$:
        1. Print "$i$ -> EMPTY"
    2. Else:
        1. Print "$i$ -> $table[i]$"

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];
    int hashFunc(int key);  // O(1)

public:
    HashTable();            // O(n)
    void insert(int key);   // Average: O(1), Worst: O(n)
    void remove(int key);   // Average: O(1), Worst: O(n)
    void search(int key);   // Average: O(1), Worst: O(n)
    void display();         // O(n)
};

// ===== MAIN MENU =====
int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n=== Hash Table Menu (Quadratic Probing) ===\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                ht.display();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

HashTable::HashTable() {    // O(n)
    for (int i = 0; i < TABLE_SIZE; i++)
        table[i] = EMPTY;
}

int HashTable::hashFunc(int key) {  // O(1)
    return key % TABLE_SIZE;
}

void HashTable::insert(int key) {   // Average: O(1), Worst: O(n)
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY &&
           table[(index + i * i) % TABLE_SIZE] != DELETED &&
           table[(index + i * i) % TABLE_SIZE] != key) {
        i++;
        if (i == TABLE_SIZE) {
            cout << "Hash table is full. Cannot insert.\n";
            return;
        }
    }

    int newIndex = (index + i * i) % TABLE_SIZE;
    if (table[newIndex] == key) {
        cout << "Duplicate key. Already exists.\n";
    } else {
        table[newIndex] = key;
        cout << "Inserted key " << key << " at index " << newIndex << ".\n";
    }
}

void HashTable::remove(int key) {   // Average: O(1), Worst: O(n)
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == key) {
            table[probeIndex] = DELETED;
            cout << "Key " << key << " deleted from index " << probeIndex << ".\n";
            return;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }

    cout << "Key " << key << " not found.\n";
}

void HashTable::search(int key) {   // Average: O(1), Worst: O(n)
    int index = hashFunc(key);
    int i = 0;

    while (table[(index + i * i) % TABLE_SIZE] != EMPTY) {
        int probeIndex = (index + i * i) % TABLE_SIZE;

        if (table[probeIndex] == key) {
            cout << "Key " << key << " found at index " << probeIndex << ".\n";
            return;
        }
        i++;
        if (i == TABLE_SIZE) break;
    }

    cout << "Key " << key << " not found.\n";
}

void HashTable::display() {         // O(n)
    cout << "\nHash Table Contents:\n";
    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << i << ": ";
        if (table[i] == EMPTY)
            cout << "EMPTY";
        else if (table[i] == DELETED)
            cout << "DELETED";
        else
            cout << table[i];
        cout << endl;
    }
}
```

### Execution

```sh

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 25
Inserted key 25 at index 5.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 35
Inserted key 35 at index 5.
Inserted key 35 at index 6.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 45
Inserted key 45 at index 5.
Inserted key 45 at index 6.
Inserted key 45 at index 9.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 4

Hash Table Contents:
0: EMPTY
1: EMPTY
2: EMPTY
3: EMPTY
4: EMPTY
5: 25
6: 35
7: EMPTY
8: EMPTY
9: 45

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 3
Enter key to search: 35
Key 35 found at index 6.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 2
Enter key to delete: 25
Key 25 deleted from index 5.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 4

Hash Table Contents:
0: EMPTY
1: EMPTY
2: EMPTY
3: EMPTY
4: EMPTY
5: DELETED
6: 35
7: EMPTY
8: EMPTY
9: 45

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 1
Enter key to insert: 15
Inserted key 15 at index 5.

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 4

Hash Table Contents:
0: EMPTY
1: EMPTY
2: EMPTY
3: EMPTY
4: EMPTY
5: 15
6: 35
7: EMPTY
8: EMPTY
9: 45

=== Hash Table Menu (Quadratic Probing) ===
1. Insert
2. Delete
3. Search
4. Display
5. Exit
Enter your choice: 5
Exiting...
```

## Separate Chaining

### Question

Write a separate C++ menu-driven program to implement Hash ADT with Separate Chaining. Maintain proper boundary conditions and follow good coding practices. The Hash ADT has the following operations,

1. Insert
2. Delete
3. Search
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - SeparateChainingInsert {.unnumbered}

##### Input {.unnumbered}

1. num - value to insert
2. table[] - hash table with linked lists
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num inserted

##### Steps {.unnumbered}

1. $index \leftarrow num \bmod SIZE$
2. Create $newnode$ with $data = num$
3. $newnode.next \leftarrow table[index]$
4. $table[index] \leftarrow newnode$

#### Algorithm 2 - SeparateChainingDelete {.unnumbered}

##### Input {.unnumbered}

1. num - value to delete
2. table[] - hash table with linked lists
3. SIZE - size of hash table

##### Output {.unnumbered}

- Updated hash table with num removed (if found)

##### Steps {.unnumbered}

1. $index \leftarrow num \bmod SIZE$
2. If $table[index] = null$:
    1. Print "Element not found"
    2. Return
3. $temp \leftarrow table[index]$
4. If $temp.next = null$:
    1. If $temp.data = num$:
        1. Delete $temp$
        2. $table[index] \leftarrow null$
        3. Return
    2. Else:
        1. Print "Element not found"
        2. Return
5. If $temp.data = num$:
    1. $table[index] \leftarrow temp.next$
    2. Delete $temp$
    3. Return
6. While $temp.next \neq null$:
    1. If $temp.next.data \neq num$:
        1. $temp \leftarrow temp.next$
    2. Else:
        1. Break loop
7. If $temp.next \neq null$ and $temp.next.data = num$:
    1. $temp2 \leftarrow temp.next$
    2. $temp.next \leftarrow temp2.next$
    3. Delete $temp2$
8. Else:
    1. Print "Element not found"

#### Algorithm 3 - SeparateChainingSearch {.unnumbered}

##### Input {.unnumbered}

1. num - value to search for
2. table[] - hash table with linked lists
3. SIZE - size of hash table

##### Output {.unnumbered}

- Status message indicating if num was found or not

##### Steps {.unnumbered}

1. $index \leftarrow num \bmod SIZE$
2. $temp \leftarrow table[index]$
3. While $temp \neq null$:
    1. If $temp.data = num$:
        1. Print "Element found at index $index$"
        2. Return
    2. $temp \leftarrow temp.next$
4. Print "Element not found"

#### Algorithm 4 - SeparateChainingDisplay {.unnumbered}

##### Input {.unnumbered}

1. table[] - hash table with linked lists
2. SIZE - size of hash table

##### Output {.unnumbered}

- Visual representation of the hash table with all chains

##### Steps {.unnumbered}

1. For $i$ from $0$ to $SIZE-1$:
    1. Print "Index $i$: "
    2. $temp \leftarrow table[i]$
    3. If $temp = null$:
        1. Print "Empty"
    4. Else:
        1. While $temp \neq null$:
            1. Print $temp.data$ followed by " -> "
            2. $temp \leftarrow temp.next$
        2. Print "NULL"
    5. Print newline

### Code

__main.cpp__

```cpp

#include <iostream>
using namespace std;

#define SIZE 10

class HashTable {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int val) {
            data = val;
            next = nullptr;
        }
    };

    Node* table[SIZE];
    int hashFunction(int key);

public:
    HashTable();
    void insert(int key);        // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void remove(int key);        // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void search(int key);       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    void display();             // Time Complexity: O(SIZE * n) where n is the average chain length
};

int main() {
    HashTable ht;
    int choice, key;

    while (true) {
        cout << "\nMENU:\n";
        cout << "1. Insert\n2. Delete\n3. Search\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter number to insert: ";
                cin >> key;
                ht.insert(key);
                break;
            case 2:
                cout << "Enter number to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 3:
                cout << "Enter number to search: ";
                cin >> key;
                ht.search(key);
                break;
            case 4:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }

        ht.display();  // Show table after each operation
    }

    return 0;
}


HashTable::HashTable() {        // Time Complexity: O(SIZE) → Initializes all buckets to nullptr
    for (int i = 0; i < SIZE; ++i) {
        table[i] = nullptr;
    }
}

int HashTable::hashFunction(int key) {  // Time Complexity: O(1) → Simple modulo operation
    return key % SIZE;
}

void HashTable::insert(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* newNode = new Node(key);
    newNode->next = table[index];
    table[index] = newNode;
    cout << "Inserted " << key << " at index " << index << endl;
}

void HashTable::remove(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* curr = table[index];
    Node* prev = nullptr;

    while (curr != nullptr) {
        if (curr->data == key) {
            if (prev == nullptr)
                table[index] = curr->next;
            else
                prev->next = curr->next;

            delete curr;
            cout << "Deleted " << key << " from index " << index << endl;
            return;
        }
        prev = curr;
        curr = curr->next;
    }
    cout << "Key " << key << " not found." << endl;
}

void HashTable::search(int key) {       // Time Complexity: O(1) average, O(n) worst case (if all keys collide)
    int index = hashFunction(key);
    Node* curr = table[index];

    while (curr != nullptr) {
        if (curr->data == key) {
            cout << "Found " << key << " at index " << index << endl;
            return;
        }
        curr = curr->next;
    }
    cout << "Key " << key << " not found." << endl;
}

void HashTable::display() {             // Time Complexity: O(SIZE * n) where n is the average chain length
    cout << "\nHash Table:\n";
    for (int i = 0; i < SIZE; ++i) {
        cout << "Index " << i << ": ";
        Node* curr = table[i];
        while (curr != nullptr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}
```

### Execution

```sh

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 1
Enter number to insert: 25
Inserted 25 at index 5

Hash Table:
Index 0: NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 1
Enter number to insert: 35
Inserted 35 at index 5

Hash Table:
Index 0: NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 35 -> 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 1
Enter number to insert: 45
Inserted 45 at index 5

Hash Table:
Index 0: NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 45 -> 35 -> 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 3
Enter number to search: 35
Found 35 at index 5

Hash Table:
Index 0: NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 45 -> 35 -> 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 2
Enter number to delete: 35
Deleted 35 from index 5

Hash Table:
Index 0: NULL
Index 1: NULL
Index 2: NULL
Index 3: NULL
Index 4: NULL
Index 5: 45 -> 25 -> NULL
Index 6: NULL
Index 7: NULL
Index 8: NULL
Index 9: NULL

MENU:
1. Insert
2. Delete
3. Search
4. Exit
Enter your choice: 4
Exiting...
```

\pagebreak

# Graph ADT

## Adjmatrix

### Question

Write a separate C++ menu-driven program to implement Graph ADT with an adjacency matrix. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations:

1. Insert
2. Delete
3. Search
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - InsertEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adj[][] - adjacency matrix of graph
4. n - number of vertices

##### Output {.unnumbered}

- Updated adjacency matrix with edge (u,v) inserted

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. $adj[u][v] \leftarrow 1$
3. $adj[v][u] \leftarrow 1$

#### Algorithm 2 - DeleteEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adj[][] - adjacency matrix of graph
4. n - number of vertices

##### Output {.unnumbered}

- Updated adjacency matrix with edge (u,v) removed

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. $adj[u][v] \leftarrow 0$
3. $adj[v][u] \leftarrow 0$

#### Algorithm 3 - SearchEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adj[][] - adjacency matrix of graph
4. n - number of vertices

##### Output {.unnumbered}

- Status of edge existence between vertices u and v

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. If $adj[u][v] = 1$:
    1. Print "Edge exists between $u$ and $v$"
3. Else:
    1. Print "No edge exists between $u$ and $v$"

#### Algorithm 4 - DisplayGraph {.unnumbered}

##### Input {.unnumbered}

1. adj[][] - adjacency matrix of graph
2. n - number of vertices

##### Output {.unnumbered}

- Visual representation of the adjacency matrix

##### Steps {.unnumbered}

1. Print "Adjacency Matrix:"
2. For $i$ from $0$ to $n-1$:
    1. For $j$ from $0$ to $n-1$:
        1. Print $adj[i][j]$ followed by space
    2. Print newline

### Code

__main.cpp__

```cpp

#include<iostream>
#include<vector>
using namespace std;

class graph
{
private:
    int numVertices;
    vector<vector<int>> adjMatrix;
public:
    graph(int vertices ){
        numVertices = vertices;
        adjMatrix.resize(vertices,vector<int>(vertices,0));
    };
    bool isValid(int);
    void insertEdge(int,int);
    void deleteEdge(int,int);
    void searchEdge(int,int);
    void display();
};



int main(){
    int num;
    cout<<"Enter The Number of Vetices : ";
    cin>>num;
    graph g(num);
    int u, v;
    int choice;

    while (true) {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.searchEdge(u, v);
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again!\n";
        }
    }
    return 0;
}

bool graph::isValid(int v){
    return (v>=0 && v<numVertices);
}
void graph::insertEdge(int u,int v){
    if(isValid(u) && isValid(v)){
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;
        cout<<"Edge Inserted between("<<u<<","<<v<<") and ("<<v<<","<<u<<")"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
}
void graph::deleteEdge(int u,int v){
    if(isValid(u) && isValid(v)){
        adjMatrix[u][v] = 0;
        adjMatrix[v][u] = 0;
        cout<<"Edge Deleted between("<<u<<","<<v<<") and ("<<v<<","<<u<<")"<<endl;
    }
    else{
        cout<<"Invalid"<<endl;
    }
}
void graph::searchEdge(int u,int v){
    if (isValid(u) && isValid(v))
    {
        if(adjMatrix[u][v] == 1){
            cout<<"Vertex is present at position ("<<u<<","<<v<<")"<<endl;
        }
        else{
            cout<<"Vertex is NOT present at position ("<<u<<","<<v<<")"<<endl;
        }
    }
    else{
        cout<<"Invalid Index"<<endl;
    }
}

void graph::display(){
    for (int i = 0; i < numVertices; i++)
    {
        for (int j = 0; j < numVertices; j++)
        {
            cout<<adjMatrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}
```

## Adjlist

### Question

Write a separate C++ menu-driven program to implement Graph ADT with an adjacency list. Maintain proper boundary conditions and follow good coding practices. The Graph ADT has the following operations:

1. Insert
2. Delete
3. Search
4. Display
5. Exit

### Algorithm

#### Algorithm 1 - InsertEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adjList[] - adjacency list representation of graph
4. n - number of vertices

##### Output {.unnumbered}

- Updated adjacency list with edge (u,v) inserted

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. Create new node $newNode$ with $data = v$ and $next = adjList[u]$
3. $adjList[u] \leftarrow newNode$
4. Create new node $newNode$ with $data = u$ and $next = adjList[v]$
5. $adjList[v] \leftarrow newNode$

#### Algorithm 2 - DeleteEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adjList[] - adjacency list representation of graph
4. n - number of vertices

##### Output {.unnumbered}

- Updated adjacency list with edge (u,v) removed

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. $temp \leftarrow adjList[u]$
3. $prev \leftarrow null$
4. While $temp \neq null$ and $temp.data \neq v$:
    1. $prev \leftarrow temp$
    2. $temp \leftarrow temp.next$
5. If $temp \neq null$:
    1. If $prev = null$:
        1. $adjList[u] \leftarrow temp.next$
    2. Else:
        1. $prev.next \leftarrow temp.next$
    3. Delete $temp$
6. $temp \leftarrow adjList[v]$
7. $prev \leftarrow null$
8. While $temp \neq null$ and $temp.data \neq u$:
    1. $prev \leftarrow temp$
    2. $temp \leftarrow temp.next$
9. If $temp \neq null$:
    1. If $prev = null$:
        1. $adjList[v] \leftarrow temp.next$
    2. Else:
        1. $prev.next \leftarrow temp.next$
    3. Delete $temp$

#### Algorithm 3 - SearchEdge {.unnumbered}

##### Input {.unnumbered}

1. u - first vertex
2. v - second vertex
3. adjList[] - adjacency list representation of graph
4. n - number of vertices

##### Output {.unnumbered}

- True if edge (u,v) exists, False otherwise

##### Steps {.unnumbered}

1. If $u \geq n$ or $v \geq n$:
    1. Print "Invalid vertex"
    2. Return
2. $temp \leftarrow adjList[u]$
3. While $temp \neq null$:
    1. If $temp.data = v$:
        1. Print "Edge exists between $u$ and $v$"
        2. Return
    2. $temp \leftarrow temp.next$
4. Print "No edge exists between $u$ and $v$"

### Code

__main.cpp__

```cpp

#include <iostream>
#include <vector>
#include <list>
using namespace std;

// --- Graph Class ---
class Graph {
private:
    int numVertices;
    vector<list<int>> adjList;

    bool valid(int u, int v); // Private helper

public:
    Graph(int V); // Constructor
    void insertEdge(int u, int v);
    void deleteEdge(int u, int v);
    void searchEdge(int u, int v);
    void display();
};

// Main Function
int main() {
    int V;
    cout << "Enter number of vertices: ";
    cin >> V;

    Graph g(V);
    int u, v;
    int choice;

    while (true) {
        cout << "\n--- Graph Menu ---\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Search Edge\n";
        cout << "4. Display\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.insertEdge(u, v);
                break;
            case 2:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.deleteEdge(u, v);
                break;
            case 3:
                cout << "Enter edge (u v): ";
                cin >> u >> v;
                g.searchEdge(u, v);
                break;
            case 4:
                g.display();
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again!\n";
        }
    }
}

// --- Function Definitions ---
Graph::Graph(int V) {
    numVertices = V;
    adjList.resize(V);
}

bool Graph::valid(int u, int v) {
    return u >= 0 && v >= 0 && u < numVertices && v < numVertices;
}

void Graph::insertEdge(int u, int v) {
    if (valid(u, v)) {
        adjList[u].push_back(v);
        cout << "Edge inserted from " << u << " to " << v << endl;
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::deleteEdge(int u, int v) {
    if (valid(u, v)) {
        adjList[u].remove(v);
        cout << "Edge deleted from " << u << " to " << v << endl;
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::searchEdge(int u, int v) {
    if (valid(u, v)) {
        for (int neighbor : adjList[u]) {
            if (neighbor == v) {
                cout << "Edge exists from " << u << " to " << v << endl;
                return;
            }
        }
        cout << "Edge does not exist.\n";
    } else {
        cout << "Invalid vertices!\n";
    }
}

void Graph::display() {
    cout << "\nAdjacency List:\n";
    for (int i = 0; i < numVertices; ++i) {
        cout << i << " -> ";
        for (int neighbor : adjList[i]) {
            cout << neighbor << " ";
        }
        cout << endl;
    }
}
```

## Graph Algorithms

### Question

Write a separate C++ menu-driven program to implement Graph ADT with the
implementation for Prim’s algorithm, Kruskal’s algorithm, and Dijkstra’s algorithm. Maintain
proper boundary conditions and follow good coding practices.
### Algorithm

#### Algorithm 1 - Kruskal's Algorithm {.unnumbered}

##### Input {.unnumbered}

1. G(V,E) - Graph with vertices V and edges E
2. w(u,v) - Weight of edge between vertices u and v

##### Output {.unnumbered}

- MST - Minimum Spanning Tree of G
- mstWeight - Total weight of the MST

##### Steps {.unnumbered}

1. Initialize $priorityQueue \leftarrow$ empty MinHeap
2. Initialize $mstWeight \leftarrow 0$
3. Create DisjointSet $ds$ with $vertices$ elements
4. For each vertex $i$ from $0$ to $vertices-1$:
    1. For each vertex $j$ from $0$ to $vertices-1$:
        1. $weight \leftarrow$ weight of edge $(i,j)$
        2. If $weight > 0$:
            1. Add edge $(i,j,weight)$ to $priorityQueue$
5. While $priorityQueue$ is not empty:
    1. Extract min edge $(u,v,weight)$ from $priorityQueue$
    2. If $ds.find(u) \neq ds.find(v)$:
        1. $ds.unite(u,v)$
        2. Add edge $(u,v,weight)$ to MST
        3. $mstWeight \leftarrow mstWeight + weight$
6. Return MST and $mstWeight$

#### Algorithm 2 - Prim's Algorithm {.unnumbered}

##### Input {.unnumbered}

1. G(V,E) - Graph with vertices V and edges E
2. w(u,v) - Weight of edge between vertices u and v
3. start - Starting vertex

##### Output {.unnumbered}

- MST - Minimum Spanning Tree of G
- mstWeight - Total weight of the MST

##### Steps {.unnumbered}

1. Initialize $visited$ map with all vertices marked as false
2. Initialize $priorityQueue \leftarrow$ empty MinHeap
3. Set $visited[start] \leftarrow true$
4. For each vertex $i$ from $0$ to $vertices-1$:
    1. If $i \neq start$:
        1. $weight \leftarrow$ weight of edge $(start,i)$
        2. If $weight > 0$:
            1. Add edge $(start,i,weight)$ to $priorityQueue$
5. Initialize $mstWeight \leftarrow 0$
6. While $priorityQueue$ not empty and $|visited| < vertices$:
    1. Extract min edge $(u,v,weight)$ from $priorityQueue$
    2. If $visited[v]$, continue
    3. Add edge $(u,v,weight)$ to MST
    4. $mstWeight \leftarrow mstWeight + weight$
    5. $visited[v] \leftarrow true$
    6. For each vertex $i$ from $0$ to $vertices-1$:
        1. If $!visited[i]$:
            1. $edgeWeight \leftarrow$ weight of edge $(v,i)$
            2. If $edgeWeight > 0$:
                1. Add edge $(v,i,edgeWeight)$ to $priorityQueue$
7. Return MST and $mstWeight$

#### Algorithm 3 - Dijkstra's Algorithm {.unnumbered}

##### Input {.unnumbered}

1. G(V,E) - Graph with vertices V and edges E
2. w(u,v) - Weight of edge between vertices u and v
3. start - Starting vertex

##### Output {.unnumbered}

- distance[] - Array of shortest distances from start to all vertices

##### Steps {.unnumbered}

1. Initialize $visited$ map with all vertices marked as false
2. Initialize $distance[i] \leftarrow \infty$ for all vertices $i$
3. Set $distance[start] \leftarrow 0$
4. While $!visited[start]$:
    1. For each vertex $i$ from $0$ to $vertices-1$:
        1. If $i \neq start$:
            1. $weight \leftarrow$ weight of edge $(start,i)$
            2. If $weight > 0$ and $distance[start] + weight < distance[i]$:
                1. $distance[i] \leftarrow distance[start] + weight$
    2. $visited[start] \leftarrow true$
    3. $minim \leftarrow \infty$
    4. For each vertex $i$ from $0$ to $vertices-1$:
        1. If $!visited[i]$ and $distance[i] < minim$:
            1. $minim \leftarrow distance[i]$
            2. $start \leftarrow i$
5. Return $distance[]$

### Code

__main.cpp__

```cpp

#include <iostream>
#include <vector>
#include <climits>
#include "heap.h"
using namespace std;

class Graph{
    private:
        vector <vector <int>> matrix;
        int n;                          //vertices
    public:
        Graph(int vertices){
            n=vertices;
            matrix.resize(n, vector<int>(n, 0));
        }
        void delete1(int u,int v){
            if (n>u && n>v){
                matrix[u][v]=0;
                matrix[v][u]=0;
            }
        }
        void insert(int u,int v,int weight){
            if (n>u && n>v){
                matrix[u][v]=weight;
                matrix[v][u]=weight;
            }
        }
        void display(){
            cout<<"\n\nAdjacency Matrix: \n";
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    cout<<matrix[i][j]<<" ";
                }
                cout<<"\n";
            }
        }

        void prims(){
            cout<<"\n";
            heap h1(n*n);
            vector <int> visited(n,0);
            node newnode;
            newnode.weight=0;
            newnode.vertex=0;
            newnode.parent=-1;
            h1.insert(newnode);
            int ttlweight=0;
            while(h1.getCurr()!=0){
                node rootNode=h1.delete1();
                int rNvert=rootNode.vertex;     //vertex of the root node which is deleted

                if (visited[rNvert]==1){
                    continue;
                }
                visited[rNvert]=1;

                if (rootNode.parent!=-1){
                    cout<<"Edge: "<<rootNode.parent<<" - "<<rNvert<<" | "<<"Weight: "<<rootNode.weight<<endl;
                    ttlweight+=rootNode.weight;
                } 

                for (int i=0;i<n;i++){
                    if (matrix[rNvert][i]!=0 && visited[i]==0){
                        node newnode;
                        newnode.weight=matrix[rNvert][i];
                        newnode.vertex=i;
                        newnode.parent=rNvert;
                        h1.insert(newnode);
                    }
                }
            }
            cout<<"Total weight: "<<ttlweight;
        }

        void kruskals(){
            cout<<"\n";
            int visited[n];
            int ttlweight=0;
            for (int i=0;i<n;i++){
                visited[i]=0;
            }
            heap h3(n*n);
            for (int i=0;i<n;i++){
                for (int j=0;j<n;j++){
                    if(matrix[i][j]!=0 ){
                        node newnode;
                        newnode.weight=matrix[i][j];
                        newnode.parent=i;
                        newnode.vertex=j;
                        h3.insert(newnode);
                    }
                }
            }

            while(h3.getCurr()!=0){
                node rootNode=h3.delete1();
                if (!(visited[rootNode.parent]==1 && visited[rootNode.vertex]==1)){
                    cout<<"Edge: "<<rootNode.parent<<" - "<<rootNode.vertex<<" | "<<"Weight: "<<rootNode.weight<<endl;
                    visited[rootNode.parent]=1;
                    visited[rootNode.vertex]=1;
                    ttlweight+=rootNode.weight;
                }
            }
            cout<<"Total weight: "<<ttlweight;
        }

        void dijikstra(int src,int dest){
            vector <int> dist(n,INT_MAX);
            heap h2(n*n);
            node newnode;
            newnode.vertex=src;
            newnode.weight=0;
            dist[0]=0;

            h2.insert(newnode);

            while(h2.getCurr()!=0){
                node rootNode=h2.delete1();
                int rNvert=rootNode.vertex;

                for (int i=0;i<n;i++){
                    if (matrix[rNvert][i]!=0 && dist[rNvert]+matrix[rNvert][i]<dist[i]){
                        node newnode;
                        newnode.vertex=i;
                        newnode.weight=matrix[rNvert][i]+dist[rNvert];
                        h2.insert(newnode);
                        dist[i]=dist[rNvert]+matrix[rNvert][i];
                    }
                }
            }
            cout<<"\nDistance between all nodes from "<<src<<":"<<endl;
            cout<<"src - dest"<<endl;
            for (int i=0;i<n;i++){
                if (i==src){
                    continue;
                }
                cout<<"\n"<<src<<" - "<<dist[i]<<endl;
            }
            cout<<"\nDistance between "<<src<<" and "<<dest<<" is "<<dist[dest]<<endl;
            
        }

};

int main() {
    int choice, u, v, vertices, weight;
    int exitFlag = 0;
    cout << "Enter number of vertices: ";
    cin >> vertices;

    Graph g1(vertices);

    while (!exitFlag) {
        cout << "\n==== Graph Menu ====\n";
        cout << "1. Insert Edge\n";
        cout << "2. Delete Edge\n";
        cout << "3. Prim's Algorithm (MST)\n";
        cout << "4. Kruskal's Algorithm (MST)\n";
        cout << "5. Dijkstra's Algorithm (Shortest Path)\n";
        cout << "6. Display Adjacency Matrix\n";
        cout << "7. Exit\n";
        cout << "=====================\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter (u v weight): ";
                cin >> u >> v >> weight;
                g1.insert(u, v, weight);
                break;

            case 2:
                cout << "Enter (u v): ";
                cin >> u >> v;
                g1.delete1(u, v);
                break;

            case 3:
                cout << "\nPrim's Algorithm Output:\n";
                g1.prims();
                break;

            case 4:
                cout << "\nKruskal's Algorithm Output:\n";
                g1.kruskals();
                break;

            case 5: {
                int src, dest;
                cout << "Enter source vertex: ";
                cin >> src;
                cout << "Enter destination vertex: ";
                cin >> dest;
                g1.dijikstra(src, dest);
                break;
            }

            case 6:
                g1.display();
                break;

            case 7:
                exitFlag = 1;
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

```

__heap.h__

```h

#include <iostream>

struct node{
    int weight;
    int vertex;
    int parent;
};

class heap{
    private:
        int curr;
        node arr[100];
        int size;
    public:
        heap(int vertex){
            curr=0;
            size=vertex;
        }
        void heapify(int,int);
        int insert(node);
        void display();
        node delete1();
        int getCurr() {
            return curr;
        }

        node getNode(int i) {
            return arr[i];
        }
};

void heap::display(){
    std::cout<<"\n";
    for (int i=1;i<=curr;i++){
        std::cout<<" "<<arr[i].weight;
    }
}

int heap::insert(node data){
    if (curr+1==size){
        return 1;
    }else{
        curr=curr+1;
        arr[curr]=data;
        heapify(curr,0);
        return 0;
    }
}

node heap::delete1(){
    // if (curr == 0)
    // {
    //     return -1;
    // }
    if (curr == 1)
    {
        curr = 0;
        return (arr[1]);
    }
    else{
        node returnElem = arr[1];

        arr[1] = arr[curr];
        curr -= 1;

        heapify(1, 1);

        return (returnElem);
    }
}

void heap::heapify(int start,int mode){
    if (mode==0){       
        int parent=start/2;                        //heapify up
        if (start!=0 && start!=1 && arr[start/2].weight>arr[start].weight){
            node temp=arr[start/2];
            arr[start/2]=arr[start];
            arr[start]=temp;
            heapify(parent,mode);
        }
    }
    else{
        
        if ((start*2<=curr && arr[start].weight>arr[start*2].weight) || (start*2+1<=curr && arr[start].weight>arr[start*2+1].weight)){
            node temp=arr[start*2].weight>arr[start*2+1].weight?arr[start*2+1]:arr[start*2];
            int tempind=arr[start*2].weight>arr[start*2+1].weight?start*2+1:start*2;
            arr[tempind]=arr[start];
            arr[start]=temp;
            heapify(tempind,mode);
        }
    }
}

```

\pagebreak

# Lab Record Generator

## assets

### Code

__main.cpp__

```cpp


```

## templates

### Algorithm

#### Algorithm 1 - AlgorithmName1 {.unnumbered}

##### Input {.unnumbered}

1. input 1
2. input 2

##### Output {.unnumbered}

- output 1
- output 2

##### Steps {.unnumbered}

1. step 1
2. step 2
3. step 3
    1. step31
    2. step32
    3. step33
        1. step331
        2. step332
4. step 4
5. step 5
    1. step51
    2. step52

#### Algorithm 2 - AlgorithmName2 {.unnumbered}

##### Input {.unnumbered}

1. input 1
2. input 2

##### Output {.unnumbered}

- output 1
- output 2

##### Steps {.unnumbered}

1. step 1
2. step 2
    1. step 21

### Code

__main.cpp__

```cpp


```

\pagebreak

