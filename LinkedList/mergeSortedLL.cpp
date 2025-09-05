// merge two sorted linked list
#include <iostream>
using namespace std;

class Node
{

public:
    int data;
    Node *next = nullptr;

    Node(int d)
    {
        this->data = d;
        this->next = nullptr;
    }

    ~Node()
    {
        cout << "Node " << this->data << endl;
        delete next;
    }
};

void insertNode(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void print(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *temp = head->next;
    cout << head->data << " ";
    while (temp != head && temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node *mergeLL(Node *head1, Node *head2)
{
    if (head1 == nullptr)
    {
        return head2;
    }
    if (head2 == nullptr)
    {
        return head1;
    }
    if(head1->data>head2->data){
        Node *dumy = head1;
        head1 = head2;
        head2 = dumy;
    }
    Node *prev = head1;
    Node *curr = head1->next;
    Node *temp = head2;
    while (temp != NULL && curr != NULL)
    {

        int d1 = prev->data;
        int d3 = curr->data;
        int d2 = temp->data;
        if (d1 <= d2 && d2 <= d3)
        {
            prev->next = temp;
            Node *next = temp->next;
            temp->next = curr;
            temp = next;
            prev = prev->next;
        }
        else
        {
            prev = curr;
            curr = curr->next;
        }
    }
    if(temp!=nullptr){
        prev->next = temp;
    }

    return head1;
}

int main()
{
    Node *head1 = new Node(2);
    insertNode(head1, 1);
    insertNode(head1, 1);
    insertNode(head1, 1);
    Node *head2 = new Node(1);
    insertNode(head2, 1);
    insertNode(head2, 1);
    insertNode(head2, 1);
    insertNode(head2, 1);
    print(head1);
    print(head2);
    Node *head = mergeLL(head2, head1);
    print(head);
    delete head;
}
