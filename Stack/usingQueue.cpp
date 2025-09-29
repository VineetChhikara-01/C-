#include<iostream>
using namespace std;

/*
----Implementing Stack using Queue Data Structure-----
*/
class Queue{
    int front ;
    int rear ;
    int size ;
    int *arr;

    public:
        Queue(int n){
            this->size = n;
            arr = new int[size];
            front = -1;
            rear = -1;
        }

        void push_back(int data){
            if(isFull()){
                cout<<"Data Structure Full"<<endl;
                return;
            }
            
            if(empty()){
                front++;
                rear++;
            } else if(rear==size-1 && front!=0){
                rear=0;
            } else{
                rear++;
            }
            arr[rear] = data;
        }

        void push_front(int data){
            if(isFull()){
                cout<<"Data Structure Full"<<endl;
                return;
            }
            
            if(empty()){
                front++;
                rear++;
            } else if(front==0 && rear!=size-1){
                front=size-1;
            } else {
                front--;
            }
            arr[front] = data;
        }

        void pop_front(){
            if(empty()){
                cout<<"Empty"<<endl;
                return ;
            }

            if(front==rear){
                rear = -1;
                front = -1;
            } else if(front==size-1){
                front=0;
            } else{
                front++;
            }
            return ;
        }

        void pop_back(){
            if(empty()){
                cout<<"Empty"<<endl;
                return ;
            }

            if(front==rear && front!=-1){
                front = -1;
                rear = -1;
            } else if(rear==0 ){
                rear = size-1;
            } else{
                rear--;
            }
        }

        int top(){
            if(empty()){
                return -1;
            }
            return arr[rear];
        }

        bool empty(){

            if(front==-1){
                // cout<<"empty queue"<<endl;
                return 1;
            }
            return 0;
        }

        bool isFull(){
            if((front==0 && rear == size-1) || (rear+1==front)){
                return 1;
            }
            return 0;
        }
};

class Stack{
    
    public:
        Queue q = NULL; 
        Stack(int size){
            q = Queue(size);
        }

        void push(int data){
            q.push_back(data);
        }

        void pop(){
            q.pop_back();
        }

        int top(){
            return q.top();
        }

        bool empty(){
            return q.empty();
        }

        void printStack(){
            print(q);
        }
        private:
         void print(Queue q){
            if(q.empty()){
                return;
            }
            while(!q.empty()){
                cout<<q.top()<<" ";
                q.pop_back();
            }
            cout<<endl;
        }
};




int main(){
    // Queue q = Queue(5);
    // q.empty();
    // q.push_back(1);
    // q.push_back(2);
    // q.push_front(5);
    // q.push_front(4);
    // q.push_front(4);
    // q.push_front(4);
    // print(q);
    Stack s = Stack(5);
    s.push(4);
    s.push(5);
    s.push(1);
    s.push(6);
    s.push(6);
    s.printStack();
    s.empty()?cout<<"Empty"<<endl:cout<<"Not empty"<<endl;
    cout<<s.top();
}