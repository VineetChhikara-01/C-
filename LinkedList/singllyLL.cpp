#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    

    Node(int data){
        this->data = data;
    }
    
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Node with value "<<value<<" is deleted"<<endl;
    }
};

void insertAtHead(Node* &head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&tail,int data){
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head,Node*& tail,int pos,int data){
    if(pos == 1){
        insertAtHead(head,data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(tail,data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteAtPosition(Node *&head,Node*& tail,int pos){
    if(pos == 1){
        Node *temp =head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* prev;
    Node *curr = head;
    int count = 1;
    while(count<pos){
        prev = curr;
        curr = curr->next;
        count++;
    }
    if(curr->next==NULL){
        tail = prev;
        prev->next = NULL;
        delete curr;
        return;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

void print(Node* &add){
    Node *temp;
    temp = add;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    Node *node1 = new Node(10);
    Node *head = node1;
    // print(head);
    insertAtHead(head,12);
    insertAtHead(head,20);
    // print(head);
    Node *tail = node1;
    insertAtTail(tail,8);
    insertAtTail(tail,10);
    // print(head);
    cout<<"Insertion at Position 5"<<endl;
    insertAtPosition(head,tail,5,11);
    print(head);

    // deleteAtPosition(head,tail,5);
    print(head);
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Head "<<head->data<<endl;
    return 0;
}