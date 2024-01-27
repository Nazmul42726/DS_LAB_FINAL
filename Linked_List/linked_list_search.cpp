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

bool search(Node** head, int value){
    if(*head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return false;
    }
    Node* current= *head;
    while(current->data!=value && current->next!=nullptr){
        current=current->next;
    }
    if(current->data==value)
        return true;
    
    cout<<"Given data in not available in the list!"<<endl;
    return false;
}

int countOccurrences(Node** head, int value){
    if(*head==nullptr){
        cout<<"Error: List is empty!"<<endl;
        return 0;
    }
    Node* current= *head;
    int count=0;
    while(current!=nullptr){
        if(current->data==value) count++;
        current=current->next;
    }
    return count;
}