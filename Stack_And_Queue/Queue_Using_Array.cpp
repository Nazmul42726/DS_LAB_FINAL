#include<iostream>
using namespace std;

const int Max_size=100000; //random size

class Queue{
private:
    int array[Max_size];
    int frontIndex;
    int rearIndex;
public:
    Queue(){
        frontIndex=-1;
        rearIndex=-1;
    }
    bool isEmpty(){
        return (frontIndex==-1 && rearIndex==-1);
    }
    int front(){
        if(isEmpty()){
            cout<<"Error: Queue is Empty!\n";
            return 0;
        }
        return array[frontIndex];
    }
    void enqueue(int data){
        if((rearIndex+1)%Max_size==frontIndex){
            cout<<"Error: Queue overflow!\n";
            return;
        }
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
            cout<<"Error: Queue Underflow!\n";
            return;
        }
        if(frontIndex==rearIndex){
            frontIndex=-1;
            rearIndex=-1;
        }
        frontIndex=(frontIndex+1)%Max_size;
    }
};

// int main(){
//     Queue q;
//     q.enqueue(3);
//     q.enqueue(5);
//     q.enqueue(7);
//     cout<<q.front()<<endl;
//     q.dequeue();
//     cout<<q.front()<<endl;
// }