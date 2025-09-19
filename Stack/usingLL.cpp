#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next = NULL;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

        ~Node(){
            this->next = NULL;
            delete next;
        }
};

class Stack{
    private:
        int count = 0;
        Node* head = NULL;
        int size;

    public:
        Stack(int size){
            this->size = size;
        }

        void push(int data){
            if(count<size){
                if(head==NULL){
                    head = new Node(data);
                    cout<<"Push "<<data<<endl;
                    count++;
                }
                else {
                    Node* temp = new Node(data);
                    temp->next = head;
                    head = temp;
                    cout<<"Push "<<data<<endl;
                    count++;
                }
            }
            else {
                cout<<"Stack overflow"<<endl;
            }
        }

        void pop(){
            if(count>0 ){
                cout<<"Pop "<<head->data<<endl;
                head = head->next;
                count--;
            } else {
                cout<<"Stack underflow"<<endl;
            }
        }

        int top(){
            if(count>0){
                cout<<"top "<<head->data<<endl;
                return head->data;
            }
            return -1;
        }

        bool isEmpty(){
            if(count>0){
                return 0;
            }
            return 1;
        }


};

int main(){

    Stack st = Stack(5);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    st.push(6);
    st.pop();
    st.pop();
    st.pop();
    st.top();
    st.isEmpty() ? cout<<"Empty Stack"<<endl : cout<<"Not Empty"<<endl ;
    st.pop();
    st.pop();
    st.pop();
    st.isEmpty() ? cout<<"Empty Stack"<<endl : cout<<"Not Empty"<<endl ;

}