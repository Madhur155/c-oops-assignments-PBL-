// Define a class to represent a bank account which includes the following
// members as:
// Data members:
// a. Name of the depositor
// b. Account Number
// c. Withdrawal amount
// d. Balance amount in the account Member Functions:
// e. To assign initial values
// f. To deposit an amount
// g. To withdraw an amount after checking the balance
// h. To display name and balance.
// Implement the program by using features of OOP in C++.
// Note:
// I. Instructor will suggest students to identify and implement classes for their application to be developed as
// a part of PBL-I project.

#include <iostream>
using namespace std;

class bank_acc{
  long long int acc_no,wd,bal,depo, limit = 10000;
  int n;
  string name ;
  public:
  void read(){
      cout<<"enter account number ";
      cin>>acc_no;
      cout<<"enter your name ";
      cin>>name;
      cout<<"enter your balance ";
      cin>>bal;
      if(bal<10000){
          cout<<"you need to keep minimum balance of 10000"<<endl;
          exit(0);
      }
      cout<<"\n\n";
  }
  void display(){
     cout<<"account number is "<<acc_no<<endl;
      cout<<"your name "<< name<<endl;
      cout<<"your balance"<< bal<<endl;
      cout<<"\n";

  }
  void deposit (){
      cout<<"enter the amount that you want to deposit"<<endl;
      cin>>depo;
      bal= bal+ depo;
      cout<<"current balnce = "<<bal<<endl;
  }
  void withdraw(){
      cout<<"enter the amount that you want to withdraw "<<endl;
      cin>>wd;
      if(wd>bal){
          cout<<"insufficient balance"<<endl;
          cout<<"do you want to take loan?";
          
          exit(0);
      }
      if(bal - wd <= limit ){
          cout<<"you cant withdraw "<< wd <<"as you need to maintain minimum balance of 10000"<< endl;
      }
      else{
          cout<<wd << "debited";
      }
      bal= bal - wd;
      cout<<"current balnce = "<<bal<<endl;
  }

    int getacc_no(){
      return acc_no;
  }

//   ~bank_acc(){
//     acc_no=0;
//     wd=0;
//     bal=0;
//     depo=0;
//     name = "NULL";
//     // cout<<"\n Destructor executed"<<endl;
//     // display();
//   }
//   bank_acc(){
//     //default ocnstructor 
//   }
//   bank_acc(bank_acc &a){
//     acc_no = a.acc_no;
//     wd = a.wd;
//     bal = a.bal;
//     depo = a.depo;
//     //cop constructor 
//   }
};

    int find(bank_acc o[1000],int acc){
      int I,i,n;
      for(int i=0;i<n;i++){
          if(acc==o[i].getacc_no()){
              I=i;
          }
      }
      return I;
  }

int main()
{
    bank_acc o[1000];
    int n;
    cout<<"enter number of user"<<endl;
    cin>>n;
    for(int i=0;i<n;i++){
    o[i].read();
    }
        int acc;
        cout<<"enter account number that you want to search"<<endl;
        cin>>acc;
        int search_result = find(o,acc);
        cout<<"account number is present at "<<search_result<<" position"<<endl<<endl;
    int ch;
    do{
    cout<<"do you want to display info, deopsit money, withdraw money or exit "<<endl;
    cout<<"enter 0 to display information, 1 to deposit money, 2 to withdraw money and 3 to exit"<<endl;
    cin>>ch;
    if(ch==0){
        o[search_result].display();
    }
    else if(ch==1){
        o[search_result].deposit();
    }
    else if(ch==2){
        o[search_result].withdraw();
    }
    else if(ch==3){
        exit(0);
    }
    else{
        cout<<"An unexpected error occured"<<endl;
    }
    }while(1);
    return 0;
}