// Write a program using C++ to create a student database system containing the following
// information: Name, roll number, Class, division, Date of Birth, Blood group, Contact address,
// telephone number. Use Class, object, inline function. Use static variables and static functions
// to maintain count of the number of students. Use constructor and destructor.
// Note:
// I. Instructor will suggest students to identify the use of inline function, static variables and
// static functions for their application to be developed as a part of PBL-I project.
// II. Instructor will suggest students to implement identified OOP features for their application
// to be developed as a part of PBL-I project.
// III. Instructor will suggest studentsto implement Constructor and Destructor in all classes of their selected
// applications.

#include<iostream>
using namespace std;
class student{
    string name, div, blood_grp, address;
    int  roll_no, Class, dob, telephone_no;
    public:
    
    inline void read(){
      cout<<"Enter name: ";
      cin>>name;
      cout<<"Enter address: ";
      cin>>address; 
      cout<<"Enter class: ";
      cin>>Class;
      cout<<"Enter D.O.B: ";
      cin>>dob;
      cout<<"Enter blood group: ";
      cin>>blood_grp;
      cout<<"Enter phone no: ";
      cin>>telephone_no;
      cout<<"Enter division: ";
      cin>>div;
    }

    inline void print(){
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"Class: "<<Class<<endl;
    cout<<"Division: "<<div<<endl;
    cout<<"Roll No: "<<roll_no<<endl;
    cout<<"D.O.B: "<<dob<<endl;
    cout<<"Blood Group: "<<blood_grp<<endl;
    cout<<"Phone No: "<<telephone_no<<endl;
    }   

    student(){
      roll_no = 0;
      name = "null";
      address = "null";
      Class = 0;
      dob = 0;
      blood_grp = "null";
      div = "null" ;
      telephone_no = 0;
    } 
    ~student(){
      
    }
};


int main()
{
    cout<<"\n # Student Database System # \n"<<endl;
    static int n;
    cout<<"enter number of students ";
    cin>>n;
    student o[n];
    for(int i=0;i<n;i++)
    {
      o[i].read();
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
      o[i].print();
    }
    cout<<endl;
return 0;
}