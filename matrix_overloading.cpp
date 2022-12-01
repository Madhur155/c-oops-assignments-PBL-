#include <iostream>
#include<bits/stdc++.h>
using namespace std;


class matrix{
    int a[100][100];
    int r,c;
    public:
    
    matrix(){
        r=0;
        c=0;
        a[r][c]=0;
        
    }
    
    // matrix(int a){
    //     a[r][c]=a;
    // }
    
    void operator+(matrix m){
        int mat[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j] = m.a[i][j] + a[i][j];
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<mat[i][j];
            }
        }
    }

    void operator-(matrix m){
        int mat[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                mat[i][j] = m.a[i][j] - a[i][j];
            }
        }
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                cout<<mat[i][j];
            }
        }
    }
    
    friend ostream & operator<< (ostream& out,  matrix& m);
    friend istream & operator>> (istream& in,  matrix& m);
};

istream & operator>> (istream& in,  matrix& m){
    // cout<<"Enter number of rows and column";
    // cin>>r>>c;
    cout<<"Enter the elements: ";
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                in>>m[i][j];
            }
        }
    return in;
}

ostream & operator<< (ostream& out,  matrix& m){
    for(int i=0;i<2;i++){
            for(int j=0;j<2;j++){
                out<<m[i][j];
            }
            cout<<endl;
        }
    return out;
}

int main()
{
    matrix m1,m2,m3,m4;
    cin>>m1>>m2;
    
    m3=m1+m2;
    m4=m1-m2;
    
    cout<<endl<<"Addition :"<<m3<<endl;
    cout<<"Multiplication :"<<m4;

    return 0;
}