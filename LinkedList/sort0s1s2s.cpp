// sorting a LL that contains 0, 1 and 2
#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next = nullptr;
    Node(int data)
    {
        this->data = data;
        this->next = nullptr;
    }
    ~Node()
    {
        cout << "Node " << this->data << endl;
        delete next;
    }
};

// insert node at head
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

void insertDumy(Node *&tail, Node *temp)
{
    tail->next = temp;
    tail = temp;
}

// with replacing node data
void sortLLR(Node *head)
{
    if (head == nullptr)
    {
        return;
    }
    int zeroCount = 0, oneCount = 0, twoCount = 0;
    Node *temp = head;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            zeroCount++;
        }
        if (temp->data == 1)
        {
            oneCount++;
        }

        if (temp->data == 2)
        {
            twoCount++;
        }

        temp = temp->next;
    }

    while (head != nullptr)
    {

        if (zeroCount > 0)
        {
            head->data = 0;
            zeroCount--;
        }
        else if (oneCount > 0)
        {
            head->data = 1;
            oneCount--;
        }
        else if (twoCount > 0)
        {
            head->data = 2;
            twoCount--;
        }
        head = head->next;
    }
}

// without replacing the node data
void sortLL(Node *&head)
{
    if (head == nullptr)
    {
        return;
    }
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *temp = head;
    while (temp != NULL)
    {

        if (temp->data == 0)
        {
            insertDumy(zeroTail, temp);
        }
        else if (temp->data == 1)
        {
            insertDumy(oneTail, temp);
        }
        else if (temp->data == 2)
        {
            insertDumy(twoTail, temp);
        }
        temp = temp->next;
    }
    head = zeroHead->next;
    zeroHead->next = nullptr;

    if (oneHead == oneTail)
    {
        zeroTail->next = twoHead->next;
    }
    else
    {
        zeroTail->next = oneHead->next;
        oneTail->next = twoHead->next;
    }
    oneHead->next = nullptr;
    twoHead->next = nullptr;
    delete zeroHead;
    delete oneHead;
    delete twoHead;
}

int main()
{

    Node *head = new Node(2);
    insertNode(head, 1);
    insertNode(head, 0);
    insertNode(head, 0);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 0);
    insertNode(head, 2);
    insertNode(head, 1);
    insertNode(head, 1);
    insertNode(head, 1);
    insertNode(head, 2);
    print(head);
    // sortLL(head);
    sortLLR(head);
    print(head);

    delete head;
    return 0;
}