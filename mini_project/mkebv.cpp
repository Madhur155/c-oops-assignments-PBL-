#include <iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;


class hospital{
    
     
    public:
    static int bed;
    static int doctor;
    static void display_hospital_info(){
        cout<<"number of doctor available = "<<doctor<<endl;
        cout<<"number of beds = "<<bed;
    }
    void admit(){
        bed--;
        doctor--;
    }
    void check_up(){
        doctor--;
    }
};
int hospital::bed=1000;
int hospital::doctor=50;

class patient:public hospital
    {
    public:
    string name,add;
    int no,id;
    int x;
    // patient()
    // {
    //     name="NULL";
    //     add="NULL";
    //     no=0;
    //     id=0;
    // }
    // ~patient()
    // {
    //     name="NULL";
    //     add="NULL";
    //     no=0;
    //     id=0;
    // }
    void enterdata(int patient_no){
        cout<<"enter patients name ";
        cin>>name;
        cout<<"enter patient address ";
        cin>>add;
        cout<<"enter patients number ";
        cin>>no;
        id = patient_no;
        cout<<"Do you want to admit the patient or do general check up";
        cout<<"\n enter 1 for admit and 2 for check up ";
        cin>>x;
        if(x==1){
            admit();
        }
        else if(x==2){
            check_up();
        }
        cout<<endl;
    }
    
    void display_patient_data()
    {
        int x;
        cout<<"patients name is"<<name<<endl;
        cout<<"patient address is"<<add<<endl;
        cout<<"patients number is"<<no<<endl;
        cout<<"patient id is"<<id<<endl;
        if(x==1)
        cout<<"patient is admitted"<<endl;
        else
        cout<<"patient has came for check up"<<endl;
    } 
}; 
int main()
{
    do{
    cout<<"enter 0 to exit "<<endl;
    cout<<"enter 1 to enter data of patient"<<endl;
    cout<<"enter 2 to display report of particular patient "<<endl;
    cout<<"enter 3 to display hospital info"<<endl<<endl;

    int a;
    cin>>a;
    patient p[1000];
        switch(a){
            case 0:
            {
                exit(0);
            }
            case 1:
            {
              int patient_number = 1 + (rand() % 100);
              cout<<"id is "<<patient_number<<endl;
              p[patient_number].enterdata(patient_number);
            }
            break;
            case 2:{
              cout<<"enter patient id whose details ou want to see"<<endl;
              int b;
              cin>>b;
              p[b].display_patient_data();
            break;
            }
            case 3:{
                hospital ::display_hospital_info();
            }
            break;
            default:{
                cout<<"Please enter valid choice"<<endl;
                break;
            }
        }
    }while(1);

    return 0;
}
