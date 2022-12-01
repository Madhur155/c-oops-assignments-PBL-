// Create a base class called 'SHAPE' having-two data members of type double -member function get-data( )to
// initialize base class data members - pure virtual member function display-area( )to compute and display the
// area of the geometrical object.
// Derive two specific classes 'TRIANGLE' and 'RECTANGLE' from the base class Using these three classes,
// design a program that will accept the dimension of a triangle / rectangle interactively and display the area.
// Implement using C++.
// Note:
// I Instructor will suggest students to identify the use of function overloading and operator
// overloading for their application to be developed as a part of PBL-I project.
// Instructor will suggest students to implement identified function overloading and operator overloading for
// their application to be developed as a part of PBL-I project.
#include<iostream>
using namespace std;
class Shape{
public:
double length,breadth;

Shape(){
length=0;
breadth=0;
}

void get_data(){
cout<<"\nEnter the dimensions:"<<endl;
cin>>length>>breadth;
}

virtual void display_area()=0;
};


class Triangle : public Shape
{
public:

void getdata(){
  Shape::get_data();
}

void display_area()
{

cout<<"\nArea of Triangle = "<<(length*breadth)/2<<endl;
}
};


class Rectangle : public Shape
{
public:

void getdata(){
     Shape::get_data();
}

void display_area()
{
cout<<"\nArea of Rectangle = "<<(length*breadth)<<endl;
}
};

int main(){
    int ch;
    Shape *ptr;
    Triangle tr;
    Rectangle rec;
   
    cout<<"\n1.triangle\n2.rectangle\n";
    cout<<"Enter your choice:"<<endl;
    cin>>ch;
   
    switch(ch){
   
        case 1:
        ptr=&tr;
        ptr->get_data();
        ptr->display_area();
        break;
       
        case 2:
        ptr=&rec;
        ptr->get_data();
        ptr->display_area();
        break;
       
    }
    return 0;
}