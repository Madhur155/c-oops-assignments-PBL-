// Set A of customers like pizza and set B of customers like a burger. Write a C + +program to store two
// sets using an array. compute and displaya Set of customers who like either pizza or burger or both
// b Set of customers who like both pizza and burger.
// c Set of customers who like only pizza, not burger.d
// Set of customers who like only burger not pizza.
// e Number of customers who like neither pizza nor burger.

#include<iostream>
using namespace std;

class set
{
  private:
  int no;
  string name[20];
  public:
  void read_set()
  {
      cout<<"Enter the number of people"<<endl;
      cin>>no;
      for(int i=0;i<no;i++)
      {
          cin>>name[i];
      }
  }
  void display()
  {
      for(int i=0;i<no;i++)
      {
          cout<<name[i];
          cout<<endl;
      }
  }
  //b
  set intersection(set b)
  {
      set c;
      int count=0;
     
      for(int i=0;i<no;i++)
      {
          for(int j=0;j<b.no;j++)
          {
              if(name[i]==b.name[j])
              {
                  count++;
              }
          }
      }
      cout<<"Number of common people is "<<count<<endl;
      c.no=count;
      for(int i=0;i<no;i++)
      {
          for(int j=0;j<b.no;j++)
          {
              if(name[i]==b.name[j])
              {
                  c.name[i]=name[i];
              }
          }
      }
      return c;
  }
};

int main()
{
    set pizza,burger,inter;
    pizza.read_set();
    pizza.display();
    burger.read_set();
    burger.display();
    inter=pizza.intersection(burger);
    inter.display();
}
