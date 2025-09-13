#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;
        Node* random = NULL;

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->random = NULL;
        }

        ~Node(){
            cout<<"Node "<<this->data<<" is deleted"<<endl;
            delete next;
        }
};

void print(Node *head){
    if(head==NULL){
        return;
    }

    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
}

void insertAtTail(Node *& head,Node *& tail,int data){
    Node *newNode = new Node(data);
    if(head==NULL){
        head = newNode;
        tail = newNode;
    } else{
        tail->next = newNode;
        tail = newNode;
    }
}


// time complexity is O(n) and space O(n)
Node* clone(Node *head){
    if(head==NULL){
        return head;
    }

    Node *temp = head;
    // clone with next
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }

    // map
    unordered_map<Node* , Node*> oldToNew;
    Node* original = head;
    Node* cloned = cloneHead;
    while(original!=NULL){
        oldToNew[original] = cloned;
        original = original->next;
        cloned = cloned->next;
    }

    original = head;
    cloned = cloneHead;
    while(original!=NULL){
        cloned->random = oldToNew[original->random];
        cloned = cloned->next;
        original = original->next;
    }

    return cloneHead;
}

// time complexity is O(n^2) and Space O(1)
Node* cloneWithOn(Node* head){
    if(head==NULL){
        return head;
    }

    Node *temp = head;
    // clone with next
    Node *cloneHead = NULL;
    Node *cloneTail = NULL;
    while(temp!=NULL){
        insertAtTail(cloneHead,cloneTail,temp->data);
        temp = temp->next;
    }
    Node* tempHead = head;
    for(Node* i = cloneHead;i!=NULL;i = i->next){
        
        Node* temp = cloneHead;
        Node *temp2 = head;
        while(temp!=NULL && temp2!=NULL && temp2!=tempHead->random){
            temp = temp->next;
            temp2 = temp2->next;
        }
        i->random = temp;
        tempHead = tempHead->next;
    }

    return cloneHead;
}

int main(){
    Node* head = NULL;

    Node* n1 = new Node(1);
    Node* n2 = new Node(2);
    Node* n3 = new Node(3);
    Node* n4 = new Node(4);
    Node* n5 = new Node(5);
    Node* n6 = new Node(6);
    
    head = n1;
    // Next
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = NULL;
    // random
    n1->random = n3;
    n2->random = n1;
    n3->random = n5;
    n4->random = n3;
    n5->random = n2;
    n6->random = n4;


    print(head);
    cout<<"Cloned LL "<<endl;
    Node* cloneHead = clone(head);
    print(cloneHead);
    // O(n)
    print(cloneWithOn(head));
    delete head;
    return 0;
}