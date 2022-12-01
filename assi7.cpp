// Write a classtemplate to represent a generic vector. Include member functions to perform the following tasks:
// a To create the vector.
// b To modify the value of a given element.
// c To multiply the vector by a scalar value.
// d To display the vector in the form (10, 20, 30 ......... )

#include <iostream>
using namespace std;


template<class T>
class vector{
    T v[20];
    int n;
    public:
    void create();
    void modify();
    void mult();
    void display();
};;

template<class T>
void vector<T>::create(){
    cout<<"Enter no of elements you want to insert"<<endl;
    cin>>n;
    cout<<"Enter the vector elements: ";
    for(int i=0;i<n;i++){
      cin>>v[i];
    }
}

template<class T>
void vector<T>::mult()
{
  int i;
  int x;
  cout<<"\nEnter scalar value for multiplication";
  cin>>x;
  for(int i=0;i<n;i++)
    v[i]=v[i]*x;
}

template<class T>
void vector<T>::modify(){
    int a;
    cout<<"Enter the element that you want to modify";
    cin>>a;
    int b;
    cout<<"Enter the modified element :";
    cin>>b;
    for(int i=0;i<n;i++){
        if(v[i]==a)
        v[i]=b;
    }
}

template<class T>
void vector<T>::display(){
   cout<<"\nElements in vector are:";
   cout<<"( ";
   for(int i=0;i<n;i++){
     cout<<v[i]<<" ";
   }
   cout<<" )";
}

int main()
{
   int ch;
   vector<int> obj;
do
{
  cout<<"1.Create"<<endl;
  cout<<"2.Display"<<endl;
  cout<<"3.Mult"<<endl;
  cout<<"4.Modify"<<endl;
  cout<<"5.Exit"<<endl;
  cout<<"Enter your choice:";
   cin>>ch;
switch(ch)
{
 case 1:
  obj.create();
  break;
 case 2:
  obj.display();
  break;
 case 3:
  obj.mult();
  break;
 case 4:
  obj.modify();
  break;
 case 5:
  cout<<"\n exit";
  break;
 }
}while(ch!=5);
  return 0;
}
