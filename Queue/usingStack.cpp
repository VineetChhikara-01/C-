// implementing Queue using Stacks
#include <iostream>
using namespace std;

class Stack
{
    int *arr;
    int size;
    int top;

public:
    Stack(int s)
    {
        this->size = s;
        arr = new int[size];
        top = -1;
    }

    void push(int data)
    {
        if (full())
        {
            cout << "Queue Full" << endl;
            return;
        }

        arr[++top] = data;
        return;
    }

    void pop()
    {
        if (empty())
        {
            return;
        }
        top--;
    }

    int topEle()
    {
        if (empty())
        {
            return -1;
        }
        return arr[top];
    }

    bool full()
    {
        return top == size - 1;
    }

    bool empty()
    {
        return top == -1;
    }
    int totalsize(){
        return top+1;
    }
};

class Queue
{
    Stack inputStack;
    Stack outputStack;
    int capacity;

public:
    Queue(int s) : inputStack(s), outputStack(s), capacity(5) { }

    void push(int data)
    {
        if(size()==capacity){
            cout<<"Queue Full"<<endl;
            return;
        }
        inputStack.push(data);
    }

    int pop()
    {
        if (empty())
        {
            return -1;
        }
        else if (!inputStack.empty() && outputStack.empty())
        {
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.topEle());
                inputStack.pop();
            }
            int ele = outputStack.topEle();
            outputStack.pop();
            return ele;
        }
        else
        {
            int ele = outputStack.topEle();
            outputStack.pop();
            return ele;
        }
    }

    int top()
    {
        if (empty())
        {
            return -1;
        }
        else if (!inputStack.empty() && outputStack.empty())
        {
            while (!inputStack.empty())
            {
                outputStack.push(inputStack.topEle());
                inputStack.pop();
            }
            return outputStack.topEle();
        }
        else
        {
            return outputStack.topEle();
        }
    }

    bool empty()
    {
        return (inputStack.empty()) && (outputStack.empty());
    }

    int size(){
        return (inputStack.totalsize() + outputStack.totalsize());
    }
};

int main()
{
    Queue s = Queue(5);
    s.push(1);
    s.push(2);
    // cout<<s.empty()<<endl;
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    s.push(6);
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    s.push(6);
    cout << s.top() << endl;
    s.pop();
    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;
}