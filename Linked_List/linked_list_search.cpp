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

Node* search(Node** head, int value){
    if(head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return;
    }
    Node* current= *head;
    while(current->data!=value && current->next!=nullptr){
        current=current->next;
    }
    if(current==nullptr){
        cout<<"Given data in not available in the list!"<<endl;
        return;
    }
    return current;
}

int countOccurrences(Node** head, int value){
    if(head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return;
    }
    Node* current= *head;
    int count=0;
    while(current!=nullptr){
        if(current->data==value) count++;
        current=current->next;
    }
    return count;
}