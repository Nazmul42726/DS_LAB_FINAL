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

void InsertAfterGivenNode(Node** givenNode, int data){
    if(*givenNode==nullptr){
        cout<<"INVALID ADDRESS"<<endl;
        return;
    }

    Node* nodeToInsert=new Node(data);

    nodeToInsert->next=(*givenNode)->next;
    (*givenNode)->next=nodeToInsert;
}

void InsertAfterGivenData(Node** head, int data, int dataOfPreviousNode){
    if(*head==nullptr){
        cout<<"Error: Node is Empty!"<<endl;
        return;
    }
    Node* current=*head;
    while(current->data!=dataOfPreviousNode && current!=nullptr){
        current=current->next;
    }
    if(current==nullptr){
        cout<<"Given Data doesn't belongs to the list"<<endl;
        return;
    }

    Node* nodeToInsert=new Node(data);
    
    nodeToInsert->next=current->next;
    current->next=nodeToInsert;
}