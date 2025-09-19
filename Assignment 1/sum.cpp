#include<iostream>
using namespace std;
const int MAX_ROWS=100;
const int MAX_COLUMNS=100;
void input(int arr[][MAX_COLUMNS],int r,int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            cin>>arr[i][j];
        }
    }
}
void rowsum(int arr[][MAX_COLUMNS],int r,int c){
    for(int i=0;i<r;i++){
        int rsum=0;
        for(int j=0;j<c;j++){
            rsum=rsum+arr[i][j];
        }
        cout<<"The sum of row "<<i+1<<" is "<<rsum<<endl;
    }
}
void columnsum(int arr[][MAX_COLUMNS],int r,int c){
    for(int i=0;i<c;i++){
        int csum=0;
        for(int j=0;j<r;j++){
            csum=csum+arr[j][i];
        }
        cout<<"The sum of column "<<i+1<<" is "<<csum<<endl;
    }
}
int main(){
    int arr[MAX_ROWS][MAX_COLUMNS];
    int r,c;
    cout<<"Enter rows and columns of matrix:"<<endl;
    cin>>r>>c;
    cout<<"Enter elements of 2D array:"<<endl;
    input(arr,r,c);
    rowsum(arr,r,c);
    columnsum(arr,r,c);
    return 0;
}