// b Write C++ program using STL map for managing Person Record (Name, birth date, telephone
// no). Perform operations – add, display, search, delete, and update.

#include <iostream>
#include<map>
using namespace std;


class person{
    string name,date;
    int pno;
    public:
    void read(){
        cout<<"Enter person name";
        cin>>name;
        cout<<"Enter phone number";
        cin>>pno;
        cout<<"Enter DOB";
        cin>>date;
    }
    void display(){
        cout<<"person's name"<<name<<endl;
        cout<<"person's phone number"<<pno<<endl;
        cout<<"person's DOB"<<date<<endl;
    }
string getname(){
    return name;
}
int getpno(){
    return pno;
}
};



int main()
{
    map <string,person>m;
    map <string,person> :: iterator it;
    person p;
    string name,name2,name3,key;
   
    do{
    int ch;
    cout<<"Enter choice 1.insert 2.display 3.search 4.delete 5.modify";
    cin>>ch;
    switch(ch){
        case 1:
        int n;
        cout<<"Enter number of employee";
        cin>>n;
        for(int i=0;i<n;i++){
            p.read();
            name = p.getname();
            m.insert(pair<string,person>(name,p));
        }
        break;
       
        case 2:
        for(it=m.begin();it!=m.end();it++){
            p=it->second;
            p.display();
        }
        break;
       
        case 3:
        cout<<"Enter the person name you want to search";
        cin>>name2;
        it=m.find(name2);
        p=it->second;
        p.display();
        break;
       
        case 4:
        cout<<"\nEnter Name to Delete Data : ";
        cin>>name3;
        it=m.find(name3);
        m.erase(it);
        break;
       
        case 5:
        cout<<"\nEnter Name to Update Data : ";
        cin>>key;
        it=m.find(key);
        m.erase(it);
        p.read();
        name=p.getname();
        m.insert(pair<string,person>(name,p));
    }
   
   
   
    }while(1);
   
   
   
   

    return 0;
}