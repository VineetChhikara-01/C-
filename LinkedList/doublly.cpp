#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *prev;
        Node *next;
    

    Node(int data){
        this->data = data;
        Node *prev = NULL;
        Node *next =NULL;
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

void insertAtHead(Node* &head,Node *&tail,int data){
    if(head==NULL){
        Node *newNode = new Node(data);
        head =newNode;
        tail =newNode;
    } else{
        Node *newNode = new Node(data);
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void insertAtTail(Node* & head,Node *&tail,int data){
    if(tail==NULL){
        Node *newNode = new Node(data);
        head =newNode;
        tail =newNode;
    } else{
        Node *newNode = new Node(data);
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void insertAtPosition(Node* &head,Node*& tail,int pos,int data){
    if(pos == 1){
        insertAtHead(head,tail,data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while(count<pos-1){
        temp = temp->next;
        count++;
    }
    if(temp->next==NULL){
        insertAtTail(head,tail,data);
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next ->prev = newNode;
    temp->next = newNode;
}

void deleteAtPosition(Node *&head,Node*& tail,int pos){
    if(pos == 1){
        Node *temp =head;
        head->next -> prev = NULL;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    Node* last;
    Node *curr = head;
    int count = 1;
    while(count<pos){
        last = curr;
        curr = curr->next;
        count++;
    }
    if(curr->next==NULL){
        last->next = NULL;
        curr->prev = NULL;
        tail = last;
        delete curr;
        return;
    }
    last->next = curr->next;
    curr->next->prev = last;
    curr->prev = NULL;
    curr->next = NULL;
    delete curr;
}

void print(Node* &head){
    Node *temp;
    temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}
int main(){
    // Node *node1 = new Node(10);
    Node *head = NULL;
    Node *tail = NULL;
    print(head);
    insertAtHead(head,tail,12);
    insertAtHead(head,tail,20);
    print(head);
    insertAtTail(head,tail,8);
    insertAtTail(head,tail,0);
    print(head);
    cout<<"Insertion at Position 5"<<endl;
    insertAtPosition(head,tail,4,11);
    print(head);

    deleteAtPosition(head,tail,3);
    print(head);
    cout<<"Tail "<<tail->data<<endl;
    cout<<"Head "<<head->data<<endl;
    return 0;
}