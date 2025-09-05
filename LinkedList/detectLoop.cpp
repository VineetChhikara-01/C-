#include<iostream>
#include<map>
using namespace std;

class Node{
    public:
    int data;
    Node *next = nullptr;
    Node(int data){
        this->data = data;
        this->next = nullptr;
    }

    ~Node(){
        int data = this->data ;
        cout<<"Node with data "<<data<<" is deleted"<<endl;
        // if(this->next !=NULL){
            // this->next = NULL;
        // }   
        delete next;     
    }
};

void insertnode(Node *&head,int data){
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}


Node* detectLoop(Node *head){
    map<Node*,bool>visited;
    while(head!=NULL){
        if(visited[head]){
            return head;
        }
        visited[head] = true;
        // cout<<head->data<<":"<<visited[head]<<" ";
        head= head->next;
    }
    // cout<<endl;
    return NULL;
}

void removeLoop(Node *head){
    Node *start = detectLoop(head);
    if(start==NULL){
        return;
    } else{
        Node *temp = start->next;
        while(temp->next != start){
            temp = temp->next;
        }
        temp->next = NULL;
    }
}

void print(Node *head){
    int count = 0;
    while(head!=nullptr && count<=10){
        cout<<head->data<<" ";
        head =head->next;
        count++;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(10);
    Node *tail = head;
    insertnode(head,20);
    insertnode(head,30);
    insertnode(head,40);
    insertnode(head,50);
    insertnode(head,60);
    insertnode(head,70);
    tail->next = head->next->next;
    print(head);
    removeLoop(head);
    print(head);
    delete head;
    return 0;
}