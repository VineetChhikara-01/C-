#include<iostream>
using namespace std;


// Double Ended Queue
class Queue{
    int *arr;
    int size, front, rear;

    public:
        Queue(){
            size = 10001;
            arr = new int[size];
            front = rear = -1;
        }

        Queue(int s){
            this->size = s;
            arr = new int[size];
            front = rear = -1;
        }

        void push_back(int data){
            if(full()){
                cout<<"Queue FULL"<<endl;
                return;
            }

            if(empty()){
                front = rear = 0;
            } else {
                rear = (rear+1)%size;
            }

            arr[rear] = data;
            cout<<"ADDED "<<data<<endl;
            return;
        }

        void push_front(int data){
            if(full()){
                cout<<"Queue FULL"<<endl;
                return;
            }
            
            if(empty()){
                front = rear = 0;
            } else {
                front = (front -1 + size)%size;
            }
            
            arr[front] = data;
            cout<<"ADDED "<<data<<endl;
            return;
        }

        int pop_front(){
            if(empty()){
                return -1;
            }

            int ele = arr[front];
            if(front==rear){
                front = rear = -1;
            } else if(front==size-1 && rear!=0){
                front = 0;
            } else {
                front++;
            }
            return ele;
        }

        int pop_back(){
            if (empty())
            {
                return-1;
            }

            int ele =  arr[rear];
            if(front==rear){
                front = rear = -1;
            } else if(rear==0 && front!=size-1){
                rear = size-1;
            } else{
                rear--;
            }

            return ele;
            
        }

        int top(){
            if(empty()){
                return -1;
            }    
            return arr[front];
        }

        int back(){
            if(empty()){
                return -1;
            }
            return arr[rear];
        }

        bool empty(){
            return (front==-1);
        }

        bool full(){
            return (rear+1)%size==front;
        }
};

void printDS(Queue q){
    if(q.empty()){
        return;
    }
    cout<<"Queue "<<endl;
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop_front();
    }
    cout<<endl;
    return;
}

int main(){
    Queue q = Queue(8);
    q.push_back(4);
    q.push_front(5);
    q.push_back(3);
    q.push_front(2);
    cout<<"Removed "<<q.pop_back()<<endl;
    cout<<"Removed "<<q.pop_front()<<endl;
    q.push_front(1);
    q.push_back(11);
    q.push_back(90);
    q.push_front(6);
    q.push_front(60);
    q.push_front(50);
    q.push_back(10);
    q.push_back(12);
    q.push_back(14);
    cout<<"FUll "<<q.full()<<endl;
    cout<<"Top "<<q.top()<<endl;
    cout<<"Rear "<<q.back()<<endl;
    printDS(q);
}