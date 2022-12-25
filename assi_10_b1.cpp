// Set A of customers like pizza and set B of customers like a burger. Write a C + +program to store two
// sets using an array. compute and display a Set of customers who like either pizza or burger or both
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
   void setno(int no){
	        this->no = no;
	    }
  void read_set()
  {
      cout<<"Enter the number of people"<<endl;
      cin>>no;
      cout<<"Enter name of people"<<endl;
      for(int i=0;i<no;i++)
      {
          cin>>name[i];
      }
  }
  void display()
  {
      cout<<"name of people are"<<endl;
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
     
    //   for(int i=0;i<no;i++)
    //   {
    //       for(int j=0;j<b.no;j++)
    //       {
    //           if(name[i]==b.name[j])
    //           {
    //               count++;
    //           }
    //       }
    //   }
    //   cout<<"Number of common people is "<<count<<endl;
    //   c.no=count;
      for(int i=0;i<no;i++)
      {
          for(int j=0;j<b.no;j++)
          {
              if(name[i]==b.name[j])
              {
                  c.name[count]=name[i];
                  count++;
              }
          }
      }
      c.setno(count);
      return c;
  }

set unionn(set X){
     set Y;
	int j=0, fl=0;
	
	for(int i=0; i<no; i++, j++){
	    Y.name[i]=name[i];
	}
	
	for(int i=0; i<no; i++){
	    for(int k=0; k<X.no; k++){
	        if(name[i] != X.name[k]){
	            for(int l=0; l<j; l++){
	                if(Y.name[l] == X.name[k]){
	                    fl = 1;
	                }
	            }
	            if(fl == 0){
	                Y.name[j] = X.name[k];
	                j++;
	            }
	            else{
	                fl--;
	            }
	        }
	    }
	}
	
	Y.setno(j);
	return Y;
}

set difference(set x){
    int i,j,k=0;
    set y;

    for(int i=0;i<no;i++){
        y.name[i]=name[i];
    }
    k=i+1;

    for(int i=0;i<k;i++){
        // int flag=0;
        for(int j=0;j<x.no;j++){
            if(y.name[i]==x.name[j]){
                y.name[i]="null";
                k--;
                for(int l=i; l<k; l++){
					y.name[l] = y.name[l+1];
				}
            }
        }
    }

    y.setno(k);
    return y;
}
};

int main()
{
    set pizza,burger,inter,uunion,diff;
    cout<<"Enter Pizza Set- "<<endl;
    pizza.read_set();
    cout<<"Pizza Set- "<<endl;
    pizza.display();

    cout<<"Enter Burger Set- "<<endl;
    burger.read_set();
    cout<<"Burger Set- "<<endl;
    burger.display();

    inter=pizza.intersection(burger);
    cout<<"Set of customers who like both pizza and burger"<<endl;
    inter.display();

    uunion=pizza.unionn(burger);
    cout<<"Set of customers who like either pizza or burger or both"<<endl;
    uunion.display();

    diff=pizza.difference(burger);
    cout<<"Set of customers who like only pizza, not burger"<<endl;
    diff.display();
}

