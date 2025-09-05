// Divide a Circular Linked List into two circular half


#include <iostream>
#include <vector>
using namespace std;

class Node {
    public:
        int data;
        Node * next = NULL;
        Node(int data){
            this->data = data;
            this->next =NULL;
        }
        ~Node(){
            cout<<"Node "<<this->data<<endl;
            delete next;
        }
};

void insertNode(Node *& head,int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *head){
    if(head == NULL){
        return;
    }
    Node *temp = head->next;
    cout<<head->data<<" ";
    while(temp!=head && temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int lengthOfLL(Node *head){
    
    if(head==NULL){
        return 0;
    }
    int count =1;
    Node *temp = head->next;
    while(temp!=head && temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to divide int two halfs

vector<Node*> divideList(Node *head,int size){
    vector<Node*> new_list;
    if(head==NULL || head->next==head){
        new_list.push_back(head);
        new_list.push_back(NULL);
        return new_list;
    }
    
    new_list.push_back(head);
    int half1 = (size+1)/2;
    
    Node *temp = head;
    // first half
    while(--half1){
        temp = temp->next;
    }
    cout<<"hjbvh";
    
    Node *head2 = temp->next;
    cout<<" vjhgvh";
    temp->next = head;

    cout<<"Second half process";
    // print(head);

    // second half
    Node *temp2 = head2;
    while(temp2->next!=head){
        temp2 = temp2->next;
    }
    temp2->next = head2;
    new_list.push_back(head2);

    return new_list;
}

// remove loop from circular LL
void removeLoop(Node *head){
    if(head==NULL){
        return ; 
    }
    Node *curr = head->next;
    while(curr->next!=head){
        curr = curr->next;
    }
    curr->next = NULL;
}

int main(){

    Node *head = new Node(1);
    Node *tail = head;
    insertNode(head,2);
    insertNode(head,3);
    insertNode(head,4);
    insertNode(head,5);
    insertNode(head,6);
    tail->next = head;
    int size = lengthOfLL(head);
    cout<<"Length of LL "<<size<<endl;
    print(head);
    cout<<((size+1)/2)<<endl;
    vector<Node*> arr = divideList(head,size);
    cout<<"List";
    for (int i = 0; i < 2; i++)
    {
        cout<<arr[i]->data<<" ";
    }
    cout<<endl;
    cout<<"First Half ";
    print(arr[0]);
    cout<<"Second Half ";
    print(arr[1]);
    removeLoop(arr[0]);
    removeLoop(arr[1]);
    delete arr[0];
    delete arr[1];
    return 0;
}