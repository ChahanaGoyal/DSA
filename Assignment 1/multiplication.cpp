#include<iostream>
using namespace std;
const int MAX_R1=100;
const int MAX_C1=100;
const int MAX_R2=100;
const int MAX_C2=100;
void input(int a[][MAX_C1],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
}
void display(int res[][MAX_C2],int r1,int c2){
    cout<<"The resultant matrix is"<<endl;
        for(int i=0;i<r1;i++){
            for(int j=0;j<c2;j++){
            cout<<res[i][j]<<" ";
        }
    cout<<endl;
    }
}
void multiply(int arr[][MAX_C1],int r1,int c1,int b[][MAX_C2],int r2,int c2,int res[][MAX_C2]){
    if(c1!=r2){
        cout<<"Multiplication with given rows and columns is not possible"<<endl;
        return;
    }
    for(int i=0;i<r1;i++){
        for(int j=0;j<c2;j++){
        res[i][j]=0;
            for(int k=0;k<r2;k++){
                res[i][j]+=arr[i][k]*b[k][j];
            }
        }
    }
}
int main(){
    int r1,c1;
    cout<<"Enter number of rows and columns of 1st matrix:"<<endl;
    cin>>r1>>c1;
    int arr[MAX_R1][MAX_C1];
    int b[MAX_R2][MAX_C2];
    int res[MAX_R1][MAX_C2];
    int r2,c2;
    cout<<"Enter number of rows and columns of 2nd matrix:"<<endl;
    cin>>r2>>c2;
    cout<<"Enter "<<r1*c1<<" elements in 1st matrix"<<endl;
    input(arr,r1,c1);
    cout<<"Enter "<<r2*c2<<" elements in 2nd matrix"<<endl;
    input(b,r2,c2);
    multiply(arr,r1,c1,b,r2,c2,res);
    display(res,r1,c2);
    return 0;
}