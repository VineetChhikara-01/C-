#include <iostream>
using namespace std;


// linear queue
class Queue
{
    int *arr;
    int front;
    int rear;
    int size;

public:
    Queue()
    {
        size = 10000;
        arr = new int[size];
        front = -1;
        rear = -1;
    }
    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
        cout<<"Size"<<this->size<<endl;
    }



    void push(int data)
    {
        if (full())
        {
            cout << "Stack Full" << endl;
            return;
        }

        if (empty())
        {
            rear = front = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
        cout<<"added "<<data<<endl;
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        int ele = arr[front];

        if (front == rear)
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

    bool empty()
    {
        return front == -1;
    }

    bool full()
    {
        return (rear == size - 1);
    }
};

int main()
{
    Queue q = Queue(5);
    cout<<q.empty()<<endl;
    cout<<q.full()<<endl;
    q.push(1);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(3);
    q.push(3);
    q.push(2);
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    cout<<q.pop()<<endl;
    
}