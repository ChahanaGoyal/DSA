#include<iostream>
using namespace std;
    int n;
    int arr[10000000];
void create(){
    cout<<"Enter size of array:"<<endl;
    cin>>n;
    cout<<"Enter elements in array:"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    } 
    cout<<"Array created successfully"<<endl;
}
void display(){
    cout<<"Array elements are:"<<endl;
    for(int i=0;i<n;i++){
            cout<<arr[i]<<" ";
        } 
        cout<<endl;
}
void insert(){
    int index;
    cout<<"Enter index at which element is to be inserted"<<endl;
    cin>>index;
    int element;
    cout<<"Enter the element to be inserted"<<endl;
    cin>>element;
    for(int i=n-1;i>=index;i--){
        arr[i+1]=arr[i];
    }
    arr[index]=element;
    n=n+1;
    cout<<"Element inserted successfully"<<endl;
}
void deleteElement(){
    int index2;
    cout<<"Enter index at which element is to be deleted"<<endl;
    cin>>index2;
    for(int i=index2;i<n-1;i++){
        arr[i]=arr[i+1];
    }
    n=n-1;
    cout<<"Element deleted successfully"<<endl;
}
void search(){
    int key;
    cout<<"Enter element to be searched:"<<endl;
    cin>>key;
    for(int i=0;i<n;i++){
        if(arr[i]==key){cout<<"Element found at index "<<i<<endl;
        return;
        }
    }
    cout<<"Element not found in the array"<<endl;
}
int main(){
    int choice;
    do{
    cout << "MENU\n";
    cout << "1. CREATE\n";
    cout << "2. DISPLAY\n";
    cout << "3. INSERT\n";
    cout << "4. DELETE\n";
    cout << "5. LINEAR SEARCH\n";
    cout << "6. EXIT\n";
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        create();
        break;
        case 2:
        display();
        break;
        case 3:
        insert();
        break;
        case 4:
        deleteElement();
        break;
        case 5:
        search();
        break;
        case 6:
        cout<<"Exiting the program\n";
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }}while(choice!=6);
    return 0;
}