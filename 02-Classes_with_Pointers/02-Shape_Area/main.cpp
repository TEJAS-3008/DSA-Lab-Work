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
