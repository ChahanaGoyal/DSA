#include<iostream>
using namespace std;
class CircularQueue{
    int arr[5];
    int front;
    int rear;
    public:
    CircularQueue(){
        front=-1;
        rear=-1;
    }
    bool isEmpty(){
        return (front==-1);
    }
    bool isFull(){
        return (front==(rear+1)%5);
    }
    void enqueue(int element){
        if(!isFull()){
            if(isEmpty()){
            front=0;
            }
        rear=((rear+1)%5);
        arr[rear]=element;
        }
        else{
            cout<<"Queue is full"<<endl;
            return;
        }
    }
    void dequeue(){
        if(!isEmpty()){
            front=(front+1)%5;
        }
        else{
            cout<<"Queue is empty"<<endl;
            return;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
            int i=front;
            while(true){
                cout<<arr[i]<<" ";
                if(i==rear) break;
                i=(i+1)%5;
            }
        }
    }
    void peek(){
        if(isEmpty()){
            cout<<"Queue is empty"<<endl;
        }
        else{
                cout<<arr[front];
            }
    }
};
int main(){
    CircularQueue obj;
    int choice;
    int element;
    do{
        cout<<"\nMENU\n";
        cout<<"1.Enqueue\n";
        cout<<"2.Dequeue\n";
        cout<<"3.isEmpty\n";
        cout<<"4.isFull\n";
        cout<<"5.Display\n";
        cout<<"6.Peek\n";
        cout<<"7.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;
        switch(choice){
            case 1:
            cout<<"Enter element to be entered in queue:";
            cin>>element;
            obj.enqueue(element);
            break;
            case 2:obj.dequeue();
            break;
            case 3:cout<<(obj.isEmpty() ? "Queue is empty" : "Queue is not empty")<<endl;
            break;
            case 4:cout<<(obj.isFull() ? "Queue is full" : "Queue is not full")<<endl;;;
            break;
            case 5:obj.display();
            break;
            case 6:obj.peek();
            break;
            case 7:
            cout<<"Exiting the program";
            exit(0);
            break;
            default:
            cout<<"Wrong choice\n";
        }
    }while(choice!=7);
    return 0;
}