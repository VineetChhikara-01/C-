#include <iostream>
using namespace std;

class Node
{
public:
    Node *prev = NULL;
    Node *next = NULL;
    int data;

    Node(int data)
    {
        this->data = data;
        prev = NULL;
        next = NULL;
    }

    ~Node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << "The node deleted had the data:" << value << endl;
    }
};
void print(Node *head)
{
    Node *temp = head->next;
    cout << "LL: " << head->data << " ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}

void insertElementAtHead(Node *& head, int data)
{
    Node *newNode = new Node(data);
    newNode->next = head;
    newNode->prev  = NULL;
    head->prev = newNode;
    head = newNode;
}

void reverseList(Node *&head){
    Node *curr = head;
    Node *prev =NULL;
    Node *next;
    while(curr!=NULL){
        next = curr->next;
        curr->prev = next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

int main()
{
    Node *node = new Node(10);

    Node *head = node;
    insertElementAtHead(head, 101);
    insertElementAtHead(head, 15);
    insertElementAtHead(head, 1);
    insertElementAtHead(head, 23);
    insertElementAtHead(head, 243);

    print(head);
    cout<<"Reverse ";
    reverseList(head);
    print(head);
    cout<<"head after reverse ";
    cout<<head->data<<endl;
    return 0;
}