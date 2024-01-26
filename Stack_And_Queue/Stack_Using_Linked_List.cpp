#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class Stack{
private:
    Node* topNode;

public:
    Stack(){
        topNode=nullptr;
    }
    bool isEmpty(){
        return topNode==nullptr;
    }
    void push(int data){
        Node* nodeToPush=new Node(data);
        nodeToPush->next=topNode;
        topNode=nodeToPush;
    }
    void pop(){
        if(isEmpty()){
            cout<<"ERROR: STACK UNDERFLOW!\n";
            return;
        }
        topNode=topNode->next;
    }
    int top(){
        if(isEmpty()){
            cout<<"ERROR: STACK IS EMPTY!\n";
            return 0;
        }
        return topNode->data;
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