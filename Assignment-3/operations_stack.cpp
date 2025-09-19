#include<iostream>
using namespace std;
class Stack{
    int *arr;
    int top;
    int size;
    public:
    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }
    bool isFull(){
        return top==size-1;
    }
    bool isEmpty(){
        return top==-1;
    }
    void push(int element){
        if(!isFull()){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack Overflow"<<endl;
        }
    }
    void pop(){
        if(!isEmpty()){
            cout<<"Popped element:"<<arr[top]<<endl;
            top--;
        }
        else{
            cout<<"Stack Underflow"<<endl;
        }
    }
    int peek(){
        if(!isEmpty()) return arr[top];
        else{
             cout<<"Stack is empty"<<endl;
             return -1;
        }
    }
    void display(){
        if(isEmpty()){
            cout<<"Stack is empty"<<endl;
            return;
        }
        for(int i=top;i>=0;i--){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
};
int main(){
    Stack st(5);
    int choice,element;
    do{
    cout << "MENU\n";
    cout << "1. PUSH\n";
    cout << "2. POP\n";
    cout << "3. IS_EMPTY\n";
    cout << "4. IS_FULL\n";
    cout << "5. DISPLAY\n";
    cout << "6. PEEK\n";
    cout << "7. EXIT\n";
    cout<<"Enter choice:"<<endl;
    cin>>choice;
    switch(choice){
        case 1:
        cout<<"Enter element to be pushed:";
        cin>>element;
        st.push(element);
        break;
        case 2:
        st.pop();
        break;
        case 3:
        cout<<(st.isEmpty() ? "Stack is empty" : "Stack is not empty")<<endl;
        break;
        case 4:
        cout<<(st.isFull() ? "Stack is full" : "Stack is not full")<<endl;
        break;
        case 5:
        st.display();
        break;
        case 6:
        element=st.peek();
        if(element!=-1) cout<<"Top element:"<<element<<endl;
        break;
        case 7:
        cout<<"Exiting the program"<<endl;
        break;
        default:
        cout<<"Invalid choice"<<endl;
    }}while(choice!=7);
    return 0;
}