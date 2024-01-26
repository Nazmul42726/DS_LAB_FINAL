#include<iostream>
using namespace std;

const int Max_size=100000;  //random size

class Stack{
private:
    int array[Max_size];
    int indexOfTop;

public:
    Stack(){
        indexOfTop=-1;
    }
    bool isEmpty(){
        if(indexOfTop==-1) return true;
        else return false;
    }
    void push(int data){
        if(indexOfTop==Max_size){
            cout<<"Error: stack overflow!"<<endl;
            return;
        }//else
        array[indexOfTop+1]=data;
        indexOfTop++;
    }
    void pop(){
        if(isEmpty()){
            cout<<"Error: stack underflow!"<<endl;
            return;
        }//else
        indexOfTop--;
    }
    int top(){
        if(isEmpty()){
            cout<<"Error: stack is empty!"<<endl;
            return 0;
        }
        return array[indexOfTop];
    }

};

int main(){
    Stack st;
    st.push(5); //5
    st.push(3); //3->5
    st.pop();   //5
    st.push(2); //2->5
    cout<<st.top()<<endl;
}