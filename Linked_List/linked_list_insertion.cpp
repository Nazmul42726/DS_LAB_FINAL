#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){     //remember? constructor?
        this->data=data;
        this->next=nullptr;
    }
};

void insertAtHead(Node** head, int data){
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next=*head;
    *head=nodeToInsert;
}
void insertAtTail(Node** head, int data){
    Node* nodeToInsert = new Node(data);
    Node* current=*head;
    while(current->next!=nullptr){
        current=current->next;
    }
    current->next=nodeToInsert;
}