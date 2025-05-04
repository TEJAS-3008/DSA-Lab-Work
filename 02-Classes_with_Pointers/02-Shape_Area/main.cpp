#include <iostream>
using namespace std;


class cuboid{
    private:
        int le,br,he;
    
    public:
        void third_set_parameters(int length, int breadth, int height);
        int third_area();
};

class cube{
    private:
        int s;
    public:
        void two_set_parameters(int side);
        int two_area();
};

class rectangle{
    private:
        int len,bre;
    public:
        void four_set_parameters(int length, int breadth);
        int four_area();

};

class square{
    private:
        int s;
    public:
        void one_set_parameters(int side);
        int one_area();
};

void cuboid_area();
void cube_area();
void rectangle_area();
void square_area();
void exit_menu();

int main(){
    int choice;
    //menu driven program
    while(1){
        cout << "\n<===== MENU ======>" << endl;
        cout << "1.SQUARE" << endl;
        cout << "2.CUBE" << endl;
        cout << "3.RECTANGLE" << endl;
        cout << "4.CUBOID" << endl;
        cout << "5.EXIT" << endl;
        cout << "select your choice:" << endl;
        cin >> choice;
        cout << endl;
        switch(choice){
            case 1:
                square_area();
                break;
            case 2:
                cube_area();
                break;
            case 3:
                rectangle_area();
                break;
            case 4:
                cuboid_area();
                break;
            case 5:
                exit_menu();
                return 0;
            default:
                cout << "The selected option cease to exist!!\nTRY Again!!" << endl;
        }
    }
}

//setting parameters for cuboid
void cuboid::third_set_parameters(int length, int breadth, int height){
    le = length;
    br = breadth;
    he = height; 
}

//setting parameters for cube
void cube::two_set_parameters(int side){
    s = side;
}

//setting parameters for rectangle
void rectangle::four_set_parameters(int length, int breadth){
    len = length;
    bre = breadth;
}

//setting parameters for square
void square::one_set_parameters(int side){
    s = side;
}


//defining functions to calculate areas:


int cuboid::third_area(){
    int area = 2*(le*br + le*he + he*br);
    return area;
}

int cube::two_area(){
    int area = (6*(s*s));
    return area;
}

int rectangle::four_area(){
    int area = (len * bre);
    return area;
}

int square::one_area(){
    int area = s*s ;
    return area;
}



//defining the functions to print output:

void cuboid_area(){
    int length, breadth, height;
    cout << "Enter the length";
    cin >> length;
    cout << "ENter the breadth:";
    cin >> breadth;
    cout << "Enter the height: ";
    cin >>  height;
    cuboid one;
    one.third_set_parameters(length,breadth, height);
    cout << "The area of the cuboid is " << one.third_area() << endl;
}

void cube_area(){
    int side;
    cout << "Enter the side of the cube:";
    cin >> side;
    cube cyber1;
    cyber1.two_set_parameters(side);
    cout << "The area of the cube is  " << cyber1.two_area() << endl;
}

void rectangle_area(){
    int length, breadth;
    cout << "Enter the length :" ;
    cin >> length;
    cout << "Enter the breadth: " ;
    cin >> breadth;
    rectangle cyber;
    cyber.four_set_parameters(length, breadth);
    cout << "Area of the rectangle = " << cyber.four_area() << endl;
}

void square_area(){
    int side;
    cout << "Enter the side:";
    cin >> side;
    square cyber;
    cyber.one_set_parameters(side);
    cout << "The area of the square = " << cyber.one_area() << endl;
}

//function to exit

void exit_menu(){
    cout << "MENU EXITED!!\n" << endl;
}
