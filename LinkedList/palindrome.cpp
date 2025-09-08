#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
    

    Node(int data){
        this->data = data;
    }
    
    ~Node(){
        
        cout<<"Node  "<<this->data<<endl;
        delete next;
    }
};

void insertNode(Node* &head,int data){
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
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

bool checkPalindromeArray(Node *head){
    if(head==NULL || head->next==NULL){
        return true;
    }

    vector<int> arr;
    Node *temp = head;
    while(temp!=NULL){
        arr.push_back(temp->data);
        temp = temp->next;
    }

    for(int i=0,j=arr.size()-1;i<=j;i++,j--){
        if (arr[i]!=arr[j])
        {           
            return false;
        }
    }
    return true;
}

Node* middle(Node *head){
    Node *slow = head;
    Node *fast = head->next;
    while(fast!=NULL && fast->next!=NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
        }
    }
    return slow;
}

Node* reverse(Node *head){
    Node *prev = NULL;
    Node *curr  = head;
    Node *next ;

    while(curr!=NULL){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool check(Node* head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    Node *curr = head;
    Node *mid = middle(head);
    Node* temp = reverse(mid->next);
    bool ans = true;
    while(temp!=NULL){
        if(curr->data != temp->data){
            ans = false;
            break;
        }
        curr = curr->next;
        temp = temp->next;
    }

    temp = reverse(mid->next);

    return ans;
    
}

int main(){
    Node *head = new Node(1);
    insertNode(head,1);
    insertNode(head,2);
    // insertNode(head,2);
    insertNode(head,1);
    print(head);

    // check(head);

    if(check(head)){
        cout<<"palindrome"<<endl;
    } else{
        cout<<"Not Palindrome"<<endl;
    }
}