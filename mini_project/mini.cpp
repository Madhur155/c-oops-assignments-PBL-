// erp system at hospital reception 
#include <iostream>
#include<cstdlib>
#include<bits/stdc++.h>
#include<string.h>

using namespace std;

class hospital
{
    public:
    static int bed;
    static int doctor;
    int room_no,floor;
    
    static void display_hospital_info()
    {
        cout<<"number of doctor available = "<<doctor<<endl;
        cout<<"number of beds = "<<bed<<endl;
    }
    void admit()
    {  
      cout<<"Enter floor number ";
        cin>>floor;
        cout<<"enter room to be allocated : "<<endl;
        cin>>room_no;
        bed--;
        doctor--;
    }
    void check_up()
    {
        doctor--;
    }
};

int hospital::bed=1000;
int hospital::doctor=50;

class patient:public hospital
    {
    private:
  
    char name[200];
    char address[200];
    int no,id,age;
    int x;
    
    public:
    
    // patient()
    // {
    //     name[200]=NULL;
    //     add[500]=NULL;
    //     no=0;
    //     id=0;
    // }
    // ~patient()
    // {
    //     name[200]=NULL;
    //     add[200]=NULL;
    //     no=0;
    //     id=0;
    // }
    void enterdata(int patient_no)
    {
        cout<<"enter patients name : ";
        cin.ignore();
        cin.getline(name,200);
        cout<<"enter patients age : ";
        cin>>age;
        cout<<"enter patient address : ";
        cin.ignore();
        cin.getline(address,200);
        
        cout<<"enter patients phone number : ";
        cin>>no;
        
        id = patient_no;
        
        cout<<"1.admit"<<endl<<"2.checkup"<<endl;
        cout<<"\n enter 1 for admit and 2 for check up"<<endl;
        cin>>x;
        if(x==1)
        {
            admit();
        }
        else if(x==2)
        {
            check_up();
        }
        cout<<endl;
    }
    
    void display_patient_data()
    {
        int x;
        cout<<"patients name is : "<<name<<endl;
        cout<<"patient address is : "<<address<<endl;
        cout<<"patients number is : "<<no<<endl;
        cout<<"patient age is : "<<age<<endl;
        cout<<"patient's floor no : "<<floor<<endl;
        cout<<"patient's room no : "<<room_no<<endl;
        
        if(x==1)
        cout<<"patient is admitted "<<endl;
        else
        cout<<" patient has came for check up "<<endl;
    } 
}; 
int main()
{

    cout<<endl<<"Apollo group of Hospitals";
    do
    {
    cout<<endl<<"enter 0 to exit "<<endl;
    cout<<"enter 1 to enter data of patient"<<endl;
    cout<<"enter 2 to display report of particular patient "<<endl;
    cout<<"enter 3 to display hospital info"<<endl<<endl;

    int a;
    cin>>a;
    patient p[1000];
        switch(a)
        {
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
          
            case 2:
            {
              cout<<"enter patient id whose details ou want to see"<<endl;
              int b;
              cin>>b;
              p[b].display_patient_data();
            }
            break;
            
            case 3:
            {
                hospital ::display_hospital_info();
            }
            break;
            
            default:
            {
                cout<<"Please enter valid choice"<<endl;
            }
                break;
            
        }
    }while(1);

    return 0;
}
