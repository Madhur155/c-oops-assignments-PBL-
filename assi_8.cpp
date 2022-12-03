// Write a program to maintain an employee database in binary file with employee information such as empId,
// name, age, department, post and salary. Write function for adding new record, displaying all records,
// searching for a particular employee, updating employee salary and post.


#include <iostream>
#include<fstream>
#include<cstdio>
#include<string.h>
#include<bits/stdc++.h>
using namespace std;
class employee{
    int phno, id, age, salary;
    string name, dep, post;
    public:
    void read(){
        cout<<"enter employee name:";
        cin>>name;
        cout<<"enter id";
        cin>>id;
        cout<<"enter age:";
        cin>>age;
        cout<<"enter salary";
        cin>>salary;
        cout<<"enter department";
        cin>>dep;
        cout<<"enter phone no";
        cin>>phno;
        cout<<"enter position";
        cin>>post;
       
    }
    void display(){
        cout<<"employee name:"<<name<<endl;
        cout<<"employee id :"<<id<<endl;
        cout<<"employee age:"<<age<<endl;
        cout<<"employee salary:"<<salary<<endl;
        cout<<"employee department:"<<dep<<endl;
        cout<<"emloyee phone no:"<<phno<<endl;
        cout<<"employee position:"<<post<<endl;
       
    }
   
    int  getid(){
        return id;
    }
};


void writerecord()
{
    employee obj;
    obj.read();
   
    ofstream outfile;
    outfile.open("mad",ios::binary | ios::in);
    outfile.write((char*)&obj,sizeof(obj));
    outfile.close();
}


void displaydata()
{
    employee  obj;
    ifstream infile;
    infile.open("mad",ios::binary);
   
    while(infile.read((char*)&obj,sizeof(obj)))
    {
        obj.display();
    }
    infile.close();
}

void search(int n){
    employee obj;
    ifstream infile;
    infile.open("mad", ios::binary);
   
    while(infile.read((char *)&obj,sizeof(obj)))
    {
        if(n == obj.getid()){
        obj.display();
        }
    }
    infile.close();
}

void modify_record(int n)
{
    // ifstream infile;
    // ofstream outfile;
    // infile.open("mad",ios::in | ios::out);
    // outfile.open("mad",ios::binary | ios::app);
    fstream file;
    file.open("mad",ios::in | ios::out);

    employee obj;

    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.getid() == n)
        {
            cout << "\nEnter the new details of student";
            obj.display();
            
            long long int pos = -1 * sizeof(obj);
            file.seekg(pos, ios::cur);
			
            file.write((char*)&obj, sizeof(obj));
        }
    }
  
    file.close();
}

int main()
{   int ch, no1, no2;
    // char name[20];
    employee obj[5];
    do{
    cout<<"\nenter choice 1.read 2.display 3.serach 4.modify";
    cin>>ch;
   
    switch(ch){
       
        case 1:
        writerecord();
        break;
       
        case 2:
        cout<<"\n list of record"<<endl;
        displaydata();
        break;
       
        case 3:
        cout<<"Enter the id which you want to search";
        cin>>no1;
        search(no1);
        break;
        
        case 4:
        cout<<"enter the id which you want to modify";
        cin>>no2;
        modify_record(no2);
        break;
    }
    }while(ch!=0);
   

    return 0;
}          
