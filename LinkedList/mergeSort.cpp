#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = NULL;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node " << this->data << endl;
        delete next;
    }
};

void insertAtTail(Node* &tail,int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

void print(Node* head){
    if(head==NULL)
        return ;
    
    while(head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
    }
    cout<<endl;
    
    return;
}

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node *merge(Node *left, Node *right)
{
    if (left == NULL)
        return right;
    if (right == NULL)
        return right;

    Node *ans = new Node(-1);
    Node *temp = ans;
    while (left != NULL && right != NULL)
    {
        if (left->data < right->data)
        {
            temp->next = left;
            left = left->next;
            temp = temp->next;
        }
        else
        {
            temp->next = right;
            right = right->next;
            temp = temp->next;
        }
    }

    while (left != NULL)
    {
        temp->next = left;
        left = left->next;
        temp = temp->next;
    }
    while (right != NULL)
    {
        temp->next = right;
        right = right->next;
        temp = temp->next;
    }

    ans = ans->next;
    return ans;
}

Node *mergeSort(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    Node *mid = findMid(head);

    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    return merge(left, right);
}

int main(){
    Node* head = new Node(1);
    Node *tail = head;
    insertAtTail(tail,3); 
    insertAtTail(tail,23); 
    insertAtTail(tail,2); 
    insertAtTail(tail,4); 
    insertAtTail(tail,43); 
    insertAtTail(tail,78); 
    insertAtTail(tail,10);
    insertAtTail(tail,10);
    print(head);

    Node* ans = mergeSort(head);

    print(ans);

    delete head;
    
    return 0;
}