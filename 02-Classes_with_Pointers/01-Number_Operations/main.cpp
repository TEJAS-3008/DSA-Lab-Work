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

