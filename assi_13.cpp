// Write a C++ program to print all the repeated numbers with their frequency in an array in minimum time
// complexity

#include<bits/stdc++.h>

using namespace std;
int main(){

int a[] = {2,4,6,7,2,3,4,4,8,7}; 
int i, j, n, freq, t;
      
n=10;
for (i=0; i<n; i++)
{

if(a[i]!=-1){
freq=1;
t=a[i];
for (j=i+1; j<n; j++){
if(a[j]==a[i]){
freq++;
a[j]=-1;
}
}
cout<<t<<" "<<freq<<" ";
}
}

return 0;
}