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

void DeleteExistingFile(){
    remove("mad.dat");
}

void writerecord()
{
    employee obj;
    obj.read();
   
    ofstream fout;
    fout.open("mad.dat",ios::binary | ios::app);
    fout.write((char*)&obj,sizeof(obj));
    fout.close();
}


void displaydata()
{
    employee  obj;
    ifstream fin;
    fin.open("mad.dat",ios::binary);
   
    while(fin.read((char *)&obj,sizeof(obj)))
    {
        obj.display();
    }
    fin.close();
}

void search(int n){
    employee obj;
    ifstream fin;
    fin.open("mad.dat", ios::binary);
   
    while(fin.read((char *)&obj,sizeof(obj)))
    {
        if(n == obj.getid()){
        obj.display();
        }
    }
    fin.close();
}

void modify_record(int n)
{
    employee obj;
    fstream file;
    file.open("mad.dat",ios::ate| ios::in| ios::out| ios::binary);


    file.seekg(0);
    while(file.read((char*)&obj, sizeof(obj)))
    {
        if(obj.getid() == n)
        {
            cout << "\nEnter the new details of student";
            obj.read();
            
            long long int pos = ((-1) * sizeof(obj));
            file.seekp(pos, ios::cur);
			
            file.write((char*)&obj, sizeof(obj));
        }
    }
    file.close();
}

int main()
{   int ch, no1;
    DeleteExistingFile();
    // employee obj[5];
    do{
    cout<<"\nenter choice 1.read 2.display 3.serach 4.modify 5.exit";
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
        int no2;
        cout<<"enter the id which you want to modify";
        cin>>no2;
        modify_record(no2);
        break;

        case 5:
        exit(0);

        default:
        cout<<"Enter valid choice"<<endl;
        break;
    }
    }while(1);
   

    return 0;
}          
