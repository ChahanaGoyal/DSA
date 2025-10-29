#include<iostream>
using namespace std;
void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int minindex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minindex]) minindex=j;
        }
        swap(arr[minindex],arr[i]);
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int temp=arr[i];
        int j=i-1;
        for(j=i-1;j>=0;j--){
            if(arr[j]>temp) arr[j+1]=arr[j];
            else break;
        }
        arr[j+1]=temp;
    }
    for(int k=0;k<n;k++){
        cout<<arr[k]<<" ";
    }
}
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = false;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j+1])
            {
                swap(arr[j+1], arr[j]);
                flag = true;
            }
        }
        if(flag==false) break;
}
 for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

}
void merge(int* arr,int s,int e){
    int mid=s+(e-s)/2;
    int len1=mid-s+1;
    int len2=e-mid;
    int* first=new int[len1];
    int *second=new int[len2];
    //copy values
    int l=s;
    for(int i=0;i<len1;i++){
        first[i]=arr[l++];
    }
    l=mid+1;
    for(int i=0;i<len2;i++){
        second[i]=arr[l++];
    }
    //merge
    int i=0,j=0,k=s;
    while(i<len1 && j<len2){
        if(first[i]<second[j]){
            arr[k++]=first[i++];
    }
    else{
        arr[k++]=second[j++];
    }
}
//if any element in any array left then copy that in final array as it is
    while(i<len1){
        arr[k++]=first[i++];
    }
    while(j<len2){
        arr[k++]=second[j++];
    }
    delete []first;
    delete []second;
}
void mergeSort(int *arr,int s,int e){
    //base case
    if(s>=e) return;
    int mid=s+(e-s)/2;
    //sort left part
    mergeSort(arr,s,mid);
    //sort right part
    mergeSort(arr,mid+1,e);
    //merge
    merge(arr,s,e);
}
int partition(int arr[],int s,int e){
    int pivot=arr[s];
    int count=0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot) count++;
    }
    //place pivot at right position
    int pivotindex=s+count;
    swap(arr[pivotindex],arr[s]);
    //sort left and right part as elements smaller than and greater than pivot respectively
    int i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[i++],arr[j--]);
        }
    }
    return pivotindex;
}
void quickSort(int arr[],int s,int e){
    //base case
    if(s>=e) return;
    //Partition
    int p=partition(arr,s,e);
    //sort left part
    quickSort(arr,s,p-1);
    //sort right part
    quickSort(arr,p+1,e);
}
int main(){
    int choice,size,k;
    int arr[10000];
    do{
    cout<<"\nSORTING TECHNIQUES MENU"<<endl;
    cout<<"1.Selection sort\n"
        <<"2.Insertion sort\n"
        <<"3.Bubble sort\n"
        <<"4.Merge sort\n"
        <<"5.Quick sort\n"
        <<"6.EXIT\n";
    cout<<"Enter choice of sorting technique to be performed"<<endl;
    cin>>choice;
    if(choice>=1 && choice <=5){
        cout<<"Enter size of array to be sorted"<<endl;
        cin>>size;
        cout<<"Enter elements in array which are to be sorted"<<endl;
        for(int i=0;i<size;i++){
            cin>>arr[i];
        }
}
    switch(choice){
        case 1:selectionSort(arr,size);
        break;
        case 2:insertionSort(arr,size);
        break;
        case 3:bubbleSort(arr,size);
        break;
        case 4:mergeSort(arr,0,size-1);
        for (int k = 0; k < size; k++)
        {
            cout << arr[k] << " ";
        }
        break;
        case 5:quickSort(arr,0,size-1);
        for (int k = 0; k < size; k++)
        {
            cout << arr[k] << " ";
        }
        break;
        case 6:cout<<"Exiting the program"<<endl;
        break;
        default:cout<<"Wrong choice"<<endl;
    }
}while(choice!=6);
    return 0;
}