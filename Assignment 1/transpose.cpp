#include <iostream>
using namespace std;
const int MAX_ROWS = 1000;
const int MAX_COLUMNS = 1000;
void input(int arr[][MAX_COLUMNS],int r,int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            cin >> arr[i][j];
        }
    }
}
void transpose(int arr[][MAX_COLUMNS], int brr[][MAX_ROWS], int r, int c){
    for (int i = 0; i < r; i++){
        for (int j = 0; j < c; j++){
            brr[j][i] = arr[i][j];
        }
    }
}
void display(int brr[][MAX_ROWS],int c,int r){
    for (int i = 0; i < c; i++){
        for (int j = 0; j < r; j++){
            cout << brr[i][j] << " ";
        }
        cout << "\n";
    }
}
int main()
{
    int r, c;
    cout << "Enter number of rows and columns:";
    cin >> r >> c;
    int arr[MAX_ROWS][MAX_COLUMNS];
    int brr[MAX_COLUMNS][MAX_ROWS];
    cout<<"Enter elements in matrix:"<<endl;
    input(arr,r,c);
    transpose(arr, brr, r, c);
    cout<<"The transpose of the given matrix is:"<<endl;
    display(brr,c,r);
    return 0;
}