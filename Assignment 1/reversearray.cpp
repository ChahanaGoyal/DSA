#include<iostream>
using namespace std;
void reverseArray(int arr[],int size){
    int i=0,j=size-1;
    while(i<=j){
        int temp=arr[i];
        arr[i]=arr[j];
        arr[j]=temp;
        i++;
        j--;
    }
}
int main(){
    int size;
    cout<<"Enter size of array:"<<endl;
    cin>>size;
    int arr[100000];
    cout<<"Enter "<<size<<" elements in array:"<<endl;
    for(int i=0;i<size;i++){
        cin>>arr[i];
    }
    reverseArray(arr,size);
    cout<<"The reversed array is:"<<endl;
    for(int j=0;j<size;j++){
        cout<<arr[j]<<" ";
    }
    return 0;
}