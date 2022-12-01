// Consider we want to store the information of different vehicles.
// Create a class named Vehicle with two data member named mileage and price.
// Create its two subclasses:
// *Car with data members to store ownership cost, warranty (by years), seating capacity and
// fuel type (diesel or petrol).
// *Bike with data members to store the number of cylinders, number of gears, cooling type(air,
// liquid or oil), wheel type(alloys or spokes) and fuel tank size(in inches).
// Make another two subclasses Audi and Ford of Car, each having a data member to store the
// model type.
// Next, make two subclasses Bajaj and TVS, each having a data member to store the make-type.
// Now, store and print the information of an Audi and a Ford car (i.e. model type, ownership
// cost, warranty, seating capacity, fuel type, mileage and price.).
// Note:
// I. Instructor will suggest students to implement reusability feature of OOP using inheritance
// in their application to be developed as a part of PBL-I project.


#include <iostream>
using namespace std;

class vehicle{
    public:
    int milege,price;
};


class car:public vehicle{
    public:
    int ownership_cost, warranty , seating_capacity;
    string fuel_type; 
};
class bike:public vehicle{
    public:
    int no_cylinders, no_gears;
    string cooling_type, wheel_type;
    int fuel_tank_size;
};


class audi:public car{
    public:
    string model_type;
    void read();
    void display();
};
class ford:public car{
    public:
    string model_type;
    void read();
    void display();
};


class bajaj:public bike{
    public:
    string make_type;
};
class tvs:public bike{
    public:
    string make_type;
};


void audi :: read(){
    cout<<"welcome to Audi"<<endl;
    cout<<"enter model type: ";
    cin>>model_type;
    cout<<"enter owernship cost";
    cin>>ownership_cost;
    cout<<"enter warrenty in year";
    cin>>warranty;
    cout<<"enter seating capacity";
    cin>>seating_capacity;
    cout<<"enter fuel type (diesel or petrol)";
    cin>>fuel_type;
    cout<<"enter milege";
    cin>>milege;
    cout<<"enter price of the vehicle";
    cin>>price;
}

void ford :: read(){
    cout<<endl;
    cout<<"welcome to ford "<<endl;
    cout<<"enter model type: ";
    cin>>model_type;
    cout<<"enter owernship cost";
    cin>>ownership_cost;
    cout<<"enter warrenty in year";
    cin>>warranty;
    cout<<"enter seating capacity";
    cin>>seating_capacity;
    cout<<"enter fuel type (diesel or petrol)";
    cin>>fuel_type;
    cout<<"enter milege";
    cin>>milege;
    cout<<"enter price of the vehicle";
    cin>>price;
}

void audi :: display(){
    cout<<endl;
    cout<<"model type is "<<model_type<<endl;
    cout<<"owernship cost is "<<ownership_cost<<endl;
    cout<<"warrenty in year is "<<warranty<<endl;
    cout<<"seating capacity is "<<seating_capacity<<endl;
    cout<<"fuel type (diesel or petrol) is "<<fuel_type;
    cout<<"milege is "<<milege<<endl;
    cout<<"price of the vehicle is "<<price<<endl;
} 

void ford :: display(){
    cout<<endl;
    cout<<"model type is "<<model_type<<endl;
    cout<<"owernship cost is "<<ownership_cost<<endl;
    cout<<"warrenty in year is "<<warranty<<endl;
    cout<<"seating capacity is "<<seating_capacity<<endl;
    cout<<"fuel type (diesel or petrol) is "<<fuel_type;
    cout<<"milege is "<<milege<<endl;
    cout<<"price of the vehicle is "<<price<<endl;
} 

int main()
{
    audi o1;
    ford o2;
    o1.read();
    o1.display();
    o2.read();
    o2.display();
    

    return 0;
}
