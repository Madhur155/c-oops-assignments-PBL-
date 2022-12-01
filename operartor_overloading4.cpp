// Implement a class Complex which represents the Complex Number data type. Implement the
// following operations:
// a Constructor (including a default constructor which creates the complex number 0+0i).
// b Overloaded operator + to add two complex numbers.
// c. Overloaded operator * to multiply two complex numbers.
// d. Overloaded << and >> to print and read Complex Numbers.

// Write a C + + programto read and display all project information using Operator Overloading.
// Note:
// I Instructor will suggest students to identify the use of function overloading and operator
// overloading for their application to be developed as a part of PBL-I project.
// Instructor will suggest students to implement identified function overloading and operator overloading for
// their application to be developed as a part of PBL-I project.

#include <iostream>
using namespace std;
class complex{
    int real,imag;
    public:
    
    complex(){
        real=0;
        imag=0;
    }
    complex(int r,int i){
        real=r;
        imag=i;
    }
    
     
    complex operator+(complex c1){
        complex ret;
        ret.real=real+c1.real;
        ret.imag=imag+c1.imag;
        return ret;
    } 
    complex operator*(complex c1){
        complex ret;
        ret.real=real*c1.real - imag*c1.imag;
        ret.imag=real*c1.imag + imag*c1.real;
        return ret;
    }
    friend ostream & operator<< (ostream& out,  complex& c);
    friend istream & operator>> (istream& din,  complex& c);
};
    ostream & operator<< (ostream& out,  complex& c)
    {
    out<<"("<<c.real<<"+"<<c.imag<<"i)";
    return out;
    }
    
    istream& operator>> (istream &din, complex &c){
    cout<<"Enter :";
    din>>c.real;
    din>>c.imag;
    return din;
    }
int main()
{
    complex c1,c2,c3,c4;
    cin>>c1;
    cin>>c2;
    
    c3=c1+c2;
    c4=c1*c2;
    
    cout<<endl<<"Addition :"<<c3<<endl;
    cout<<"Multiplication :"<<c4;
    return 0;
}
