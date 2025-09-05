#include <iostream>
#include <map>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }

    ~Node()
    {
        cout << "Node " << this->data << " " << endl;
        // this->next = NULL;
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
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}
// sorted LL
void deleteDuplicates(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    while (curr->next != NULL)
    {
        if (curr->data == curr->next->data)
        {
            Node *nextNode = curr->next->next;
            Node *toDelete = curr->next;
            toDelete->next = NULL;
            delete toDelete;
            curr->next = nextNode;
        }
        else
        {
            curr = curr->next;
        }
    }
}

// unsorted LL
// using two loops
void deleteDuplicatesUS(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    Node *curr = head;
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        Node *prev = curr;
        for (Node *next = curr->next; next != NULL; next = prev->next)
        {
            if (curr->data == next->data)
            {
                prev->next = next->next;
                next->next = NULL;
                delete next;
            }
            else
            {
                prev = next;
            }
        }
    }
}

// using map
void deleteDuplicatesMap(Node *head)
{
    if (head == NULL)
    {
        return;
    }
    map<int, bool> visited;
    Node *prev = head;
    visited[prev->data] = true;
    Node *curr ;
    while (prev != NULL)
    {
        curr = prev->next;
        if(curr==NULL){
            break;
        }
        if (visited[curr->data])
        {
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
        else
        {
            visited[curr->data] = true;
            prev = prev->next;
        }
    }
}


int main()
{
    Node *Node1 = new Node(1);
    Node *head = new Node(6);
    head->next = Node1;
    insertNode(head, 6);
    insertNode(head, 43);
    insertNode(head, 3);
    insertNode(head, 43);
    insertNode(head, 2);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 7);
    print(head);
    // deleteDuplicates(head); //for sorted LL
    // deleteDuplicatesUS(head); //using two loops
    deleteDuplicatesMap(head); // using map
    print(head);
    delete head;
}