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

void deleteAtPosition(Node** head, int position){
    if(*head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return;
    }

    if(position==0){
        *head=(*head)->next;
        return;
    }

    Node* current=*head;
    int nodeCount=0;
    while(nodeCount<position-1 && current->next!=nullptr){
        current=current->next;
        nodeCount++;
    }
    if(current->next==nullptr){
        cout<<"Given \"Position\" is out of bound"<<endl;
        return;
    }
    Node* nodeToDelete=current->next;
    current->next=nodeToDelete->next;
}

void deleteNodeWithValue(Node** head, int value){
    if(*head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return;
    }
    if((*head)->data==value){
        *head=(*head)->next;
        return;
    }

    Node* current=*head;

    while(current->next->data!=value && current->next->next!=nullptr)
        current=current->next;

    if(current->next->data==value){
        Node* nodeToDelete=current->next;
        current->next=nodeToDelete->next;
        return;
    }
    cout<<"Given \"Value\" doesn't match with any data in the list"<<endl;
}