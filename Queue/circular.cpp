#include <iostream>
using namespace std;


// circular Queue
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10001;
        arr = new int[size];
        rear = front = -1;
    }

    Queue(int s)
    {
        size = s;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Queue Full" << endl;
            return;
        }

        if (empty())
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        cout << "Added" << data << endl;
        arr[rear] = data;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }

        int ele = arr[front];

        if (front == size - 1 && rear < front)
        {
            front = 0;
        }
        else if (front == rear)
        {
            front = rear = -1;
        }
        else
        {
            front++;
        }

        return ele;
    }

    int top()
    {
        if (empty())
        {
            return -1;
        }
        return arr[front];
    }

    bool full()
    {
        return (front == 0 && rear == size - 1) || (rear == front - 1);
    }

    bool empty()
    {
        return front == -1;
    }
};

void printDS(Queue q)
{
    if (q.empty())
    {
        return;
    }
    cout<<"Queue ";
    while (!q.empty())
    {
        cout << q.top() << " ";
        q.pop();
    }
    cout << endl;
    return;
}

int main()
{
    Queue q = Queue(6);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    cout << "removed" << q.pop() << endl;
    cout << "removed" << q.pop() << endl;
    cout << q.full() << endl;
    cout << q.empty() << endl;
    q.push(6);
    q.push(9);
    q.push(8);
    q.push(7);
    q.push(7);
    q.push(7);
    printDS(q);
}
