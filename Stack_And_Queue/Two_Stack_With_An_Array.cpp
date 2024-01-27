#include<iostream>
using namespace std;

class TwoStack{
private:
    int *array;
    int size;
    int topIndex1;
    int topIndex2;

public:
    TwoStack(int size){
        this->size=size;
        array=new int[size];
        topIndex1=-1;
        topIndex2=size;
    }
    
    bool isEmpty_1(){
        return topIndex1==-1;
    }
    bool isEmpty_2(){
        return topIndex2==size;
    }
    int top_1(){
        if(isEmpty_1()){
            cout<<"Error: Stack_1 is Empty!\n";
            return 0;
        }
        return array[topIndex1];
    }
    int top_2(){
        if(isEmpty_2()){
            cout<<"Error: Stack_2 is Empty!\n";
            return 0;
        }
        return array[topIndex2];
    }
    void push_1(int data){
        if(topIndex1==topIndex2-1){
            cout<<"Error: Stack_1 Overflow!\n";
            return;
        }
        topIndex1++;
        array[topIndex1]=data;
    }
    void push_2(int data){
        if(topIndex1==topIndex2-1){
            cout<<"Error: Stack_2 Overflow!\n";
            return;
        }
        topIndex2--;
        array[topIndex2]=data;
    }
    void pop_1(){
        if(isEmpty_1()){
            cout<<"Error: Stack_1 Underflow!\n";
            return;
        }
        topIndex1--;
    }
    void pop_2(){
        if(isEmpty_2()){
            cout<<"Error: Stack_2 Underflow!\n";
            return;
        }
        topIndex2++;
    }
};

int main(){
    TwoStack stt(3);
    stt.push_1(1);  
    stt.push_2(3);  
    stt.push_2(2);  
    stt.pop_2();   
    stt.push_1(4);
    cout<<stt.top_1()<<endl;
    cout<<stt.top_2()<<endl;
}