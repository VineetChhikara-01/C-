#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next = NULL;
    

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

void insertion(Node *& tail,int ele,int data){

    if(tail==NULL){
        Node *temp = new Node(data);
        temp->next = temp;
        tail = temp;
    } else{
        Node *curr = tail;
        while(curr->data!=ele){
            curr = curr->next;
        }
        Node *temp = new Node(data);
        temp->next = curr->next;
        curr->next = temp;
    }
}

void deleteNode(Node* &tail,int ele){
    
    if(tail==NULL){
       cout<<"List is Empty"<<endl;
       return;
    } else{
        Node *temp = tail;
        while(temp->next->data!=ele){
            temp = temp->next;
        }
        Node *prev = temp;
        temp = temp->next;

        if(temp==prev){
            tail = NULL;
        } else if(temp==tail) {
            tail = prev;
        }
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
    }
}

void print(Node* tail){
    if(tail==NULL){
        cout<<"LIST is Empty"<<endl;
        return;
    }
    Node* temp = tail->next;
    cout<<tail->data<<" ";
    while(temp!=tail){
        cout<<temp->data<<" ";
        temp = temp->next;
    } cout<<endl;
}


int main(){
    Node *tail = NULL;
    insertion(tail,5,3);
    print(tail);
    insertion(tail,3,30);
    print(tail);
    insertion(tail,3,15);
    print(tail);
    insertion(tail,15,21);
    print(tail);
    insertion(tail,15,1);
    print(tail);
    insertion(tail,15,2);
    print(tail);
    deleteNode(tail,15);
    print(tail);
    deleteNode(tail,3);
    print(tail);
    deleteNode(tail,2);
    print(tail);
    deleteNode(tail,1);
    print(tail);
    deleteNode(tail,21);
    print(tail);
    deleteNode(tail,30);
    print(tail);
    return 0;
}