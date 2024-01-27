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

class Queue{
private:
    Node* head;

public:
    Queue(){
        head=nullptr;
    }
    bool isEmpty(){
        return head==nullptr;
    }
    int front(){
        if(head==nullptr){
            cout<<"Error: Queue is Empty!\n";
            return 0;
        }
        return head->data;
    }
    void enqueue(int data){
        Node* nodeToEnqueue=new Node(data);
        if(head==nullptr){
            head=nodeToEnqueue;
            return;
        }
        Node* current=head;
        while(current->next!=nullptr){
            current=current->next;
        }
        current->next=nodeToEnqueue;
    }
    void dequeue(){
        if(head==nullptr){
            cout<<"Error: Queue Underflow!\n";
            return;
        }
        Node* temp=head;
        head=head->next;
        delete temp;
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