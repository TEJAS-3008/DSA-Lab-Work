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



