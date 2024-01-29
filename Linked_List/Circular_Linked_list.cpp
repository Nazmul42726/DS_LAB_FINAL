#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};

class CircularLinkedList{
private:
    Node* head;

public:
    CircularLinkedList(){
        head=nullptr;
    }
    void insertAtHead(int data){
        Node* nodeToInsert=new Node(data);

        if(head==nullptr){
            head=nodeToInsert;
            head->next=head;
        }
        else{
            nodeToInsert->next=head->next;
            head->next=nodeToInsert;
        }
    }
    void deleteNode(int data){
        if(head==nullptr){
            cout<<"Error: List is empty!"<<endl;
            return;
        }
        Node* current=head;
        Node* previous=nullptr;

        do{
            if(current->data==data){
                if(previous!=nullptr)
                    previous->next=current->next;
                else{
                    if(current->next==head)
                        head=nullptr;
                    else
                        head=current->next;
                }
                delete current;
                return;
            }
            previous=current;
            current=current->next;

        }while(current!=head);

        cout<<"Error: Given data is not found!"<<endl;
    }
    void printList(){
        if(head==nullptr){
            cout<<"Error: List is empty!"<<endl;
            return;
        }
        Node* current=head;
        do{
            cout<<current->data<<" ";
            current=current->next;
        }while(current!=head);
        cout<<endl;
    }

    ~CircularLinkedList(){
        if(head==nullptr) return;

        Node* current=head;
        Node* nextNode;

        do{
            nextNode=current->next;
            delete current;
            current=nextNode;

        }while(current!=head);
    }
};

int main(){
    CircularLinkedList cList;

    cList.insertAtHead(3);
    cList.insertAtHead(2);
    cList.insertAtHead(1);

    cout<<"Circular Linked List: ";
    cList.printList();

    cList.deleteNode(2);

    cout<<"Circular Linked List after deletion: ";
    cList.printList();

    return 0;
}
