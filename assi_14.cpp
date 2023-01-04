// Write a C++ program to sort N names in alphabetical order

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<iostream>
#include<string>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    string s[4] = {"Ajay", "Vijay" , "Shrikant" , "Raju"};
    string temp;
    // for(int i=0;i<4;i++){
    //     cin>>s[i];
    // }
    
     for(int i=0;i<4;i++){
          for(int j=i+1;j<4;j++){
              if(s[i][0] > s[j][0]){
                  temp = s[i];
                  s[i]= s[j];
                  s[j]=temp;
              }
          }
     }
    
    
    for(int i=0;i<4;i++){
        cout<<s[i]<<endl;
    }
    return 0;
}