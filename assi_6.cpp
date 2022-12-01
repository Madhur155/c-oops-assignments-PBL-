// Implement matrix class as ADT. Write a program to perform matrix addition, subtraction, and
// multiplication. In read matrix function, raise an exception if any attempt is made to have rows and columns
// beyond the array size. Raise an exception if any attempt is made to perform matrix operations on matrices
// which does not satisfy the matrix order criteria. Implement using C++.
#include <iostream>
using namespace std;

class matrix{
    int r,c;
    int a[5][5];
    public:
   
    void read(){
        cout<<"enter number of rows and colums";
        cin>>r>>c;
        try{
            if(r>5 || c>5){
                throw 1;
            }
            else{
                cout<<"enter the elements in the matrix";
                for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                cin>>a[i][j];        
            }
        }
        }
    }
    catch(int a){
        cout<<"exception caught"<<endl<<"rows and columns beyond the array size"<<endl;
        exit(0);
    }
    }
 
    void display(){
        for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                cout<<a[i][j]<<" ";        
            }
            cout<<endl;
        }
    }
   
    matrix operator+(matrix m){
        matrix ret;
        try{
            if(r!=m.r || c!=m.c){
                throw 2;
            }
            else{
                ret.r=m.r;
                ret.c=m.c;
                for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                ret.a[i][j] = a[i][j] + m.a[i][j];
               
            }
        }
        return ret;
            }
        }
        catch(int a){
            cout<<"exception caught"<<endl<<"rows and columns of the matrix are not equal"<<endl;
            exit(0);
        }
    }
   
    matrix operator*(matrix m){
        matrix ret;
        try{
            if(c!=m.r && ret.r!=r && ret.c!=m.c){
                throw 2;
            }
            else{
                ret.r=r;
                ret.c=m.c;
                for(int i=0;i<r;i++){
                for(int j=0;j<c;j++){
                ret.a[i][j] = a[i][j] * m.a[i][j];
               
            }
        }
        return ret;
            }
        }
        catch(int a){
            cout<<"exception caught"<<endl<<"matrix operations on matrices which does not satisfy the matrix order criteria"<<endl;
            exit(0);
        }
    }
   
};
               
int main()
{
    matrix m1,m2,m3,m4;
    cout<<"Enter first matrix"<<endl;
    m1.read();
    cout<<"first matrix"<<endl;
    m1.display();
   
    cout<<"Enter second matrix"<<endl;
    m2.read();
    cout<<"second matrix"<<endl;
    m2.display();
   
    m3=m1+m2;
   
    cout<<"addition of matrix 1 and 2 is: "<<endl;
    m3.display();
   
    m4=m1*m2;
    cout<<"multiplication of matrix 1 and 2 is: "<<endl;
    m4.display();
   
    return 0;
}
