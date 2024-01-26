#include<iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
    Node* previous;

    Node(int data){
        this->data=data;
        this->next=nullptr;
        this->previous=nullptr;
    }
};

class DoublyLinkedList{
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList(){
        head=nullptr;
        tail=nullptr;
    }
    void insertAtHead(int data){
        Node* nodeToInsert=new Node(data);
        if(head==nullptr){
            head=nodeToInsert;
            tail=nodeToInsert;
        }
        else{
            nodeToInsert->next=head;
            head->previous=nodeToInsert;
            head=nodeToInsert;
        }
    }
    void insertAtTail(int data){
        Node* nodeToInsert=new Node(data);
        if(tail==nullptr){
            head=nodeToInsert;
            tail=nodeToInsert;
        }
        else{
            nodeToInsert->previous=tail;
            tail->next=nodeToInsert;
            tail=nodeToInsert;
        }
    }
    void deleteNodeAtPosition(int position){
        if(head==nullptr){
            cout<<"Error: List is empty!"<<endl;
            return;
        }
        Node* current=head;
        int count=0;
        while(current!=nullptr && count!=position){
            current=current->next;
        }
        if(current==nullptr){
            cout<<"INVALID POSITION\n";
            return;
        }

        if(current->previous!=nullptr){
            current->previous->next=current->next;
        }
        else{
            if(current->next!=nullptr){
                head=current->next;
                head->previous=nullptr;
            }
            else{
                head=nullptr;
                tail=nullptr;
            }
        }

        if(current->next!=nullptr){
            current->next->previous=current->previous;
        }
        else{
            if(current->previous!=nullptr){
                tail=current->previous;
                tail->next=nullptr;
            }
            else{
                head=nullptr;
                tail=nullptr;
            }
        }
    }
    void PrintThisShit(){
        Node* tracker=head;
        while(tracker!=nullptr){
            cout<<tracker->data<<" ";
            tracker=tracker->next;
        }
        cout<<endl;
    }
};

// int main(){
//     DoublyLinkedList newList;
//     newList.insertAtHead(5);    //5
//     newList.insertAtTail(2);    //5 2
//     newList.insertAtHead(3);    //3 5 2
//     newList.insertAtTail(4);    //3 5 2 4

//     newList.PrintThisShit();

//     newList.deleteNodeAtPosition(2);
    
//     newList.PrintThisShit();
// }
