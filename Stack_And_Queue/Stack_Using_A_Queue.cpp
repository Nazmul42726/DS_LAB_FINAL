#include<iostream>
using namespace std;

const int Max_size=100000; //random size

class StackUsingQueue{
private:
    int array[Max_size];
    int frontIndex;
    int rearIndex;

    int front(){
        if(isEmpty()){
            cout<<"Error: Stack is Empty!\n";
            return 0;
        }
        return array[frontIndex];
    }
    void enqueue(int data){
        if(isEmpty()){
            frontIndex=0;
            rearIndex=0;
        }
        else{
            rearIndex=(rearIndex+1)%Max_size;
        }
        array[rearIndex]=data;
    }
    void dequeue(){
        if(isEmpty()){
            cout<<"Error: Stack Underflow!\n";
            return;
        }
        if(frontIndex==rearIndex){
            frontIndex=-1;
            rearIndex=-1;
        }
        frontIndex=(frontIndex+1)%Max_size;
    }

public:
    StackUsingQueue(){
        frontIndex=-1;
        rearIndex=-1;
    }
    bool isEmpty(){
        return (frontIndex==-1 && rearIndex==-1);
    }
    int top(){
        return front();
    }
    void push(int data){
        if((rearIndex+1)%Max_size==frontIndex){
            cout<<"Error: Stack overflow!\n";
            return;
        }
        enqueue(data);

        if(isEmpty()){
            enqueue(data);
            return;
        }
        int size;
        if(rearIndex>frontIndex) size=rearIndex-frontIndex+1;
        else size=(Max_size-frontIndex)+rearIndex+1;

        for(int i=1; i<size; i++){
            enqueue(front());
            dequeue();
        }
    }
    void pop(){
        dequeue();
    }
};

int main(){
    StackUsingQueue st;
    st.push(5); //5
    st.push(3); //3->5
    st.pop();   //5
    st.push(2); //2->5
    cout<<st.top()<<endl;
}