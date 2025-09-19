#include<iostream>
using namespace std;
#include<stack>

class Stack{
    private:
        int size;
        int top = -1;
        int *arr;
    public:
        //constructor to get the size of stack
        Stack(int size){
            this->size = size;
            arr = new int[size];
        }
        // push function to add element to the top
        void push(int data){
            if(top< size-1){
                top++;
                arr[top] = data;
            }
            else{
                cout<<"Stack Overflow"<<endl;
            }
        }
        // pop function to remove the top element
        void pop(){
            if(top>=0){
                cout<<"Pop "<<arr[top]<<endl;
                top--;
            } else{
                cout<<"Stack Underflow"<<endl;
            }
        }
        // peek or top function to get the top element
        int peek(){
            if(top>=0){
                cout<<"Top "<<arr[top]<<endl;
                return arr[top];
            }
            else {
                cout<<"Empty stack"<<endl;
                return -1;
            }
        }
        // is empty function to check if stack is empty
        bool isEmpty(){
            if(top>=0){
                return 1;
            } 
            return 0;
        }
};

int main(){

    /*
    // using STL
    stack<int> st;
    st.push(1); //push 1
    st.push(2); //push 2
    st.push(3); //push 3
    st.push(4); //push 4
    st.pop();  //pops 4 
    st.pop();  //pops 3
    cout<<st.top()<<endl; //returns 2
    cout<<st.empty()<<endl; 
    */

    // using the class Stack
    Stack st = Stack(5);
    st.push(2);
    st.push(32);
    st.push(5);
    st.push(23);
    st.pop();
    st.pop();
    st.peek();
    st.isEmpty() ? cout<<"Not Empty"<<endl : cout<<"Empty Stack"<<endl ; 

}