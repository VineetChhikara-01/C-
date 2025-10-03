#include<iostream>
using namespace std;
#include<queue>
#include<stack>


void print(queue<int> q){
    if(q.empty()){
        return;
    }
    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    } cout<<endl;

}

// interleave the first half of queue with second half queue whose size is even
void interleave(queue<int> &q){
    if(q.empty()){
        return;
    }
    stack<int> s;
    int size = q.size();
    int i=0;
    while(i<(size)/2){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    i=0;
    while(i<(size)/2){
        q.push(q.front());
        q.pop();
        i++;
    }
    i = 0;
    while(i<(size)/2){
        s.push(q.front());
        q.pop();
        i++;
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
        q.push(q.front());
        q.pop();
    }

}
int main(){
    queue<int> q;
    q.push(11); 
    q.push(12); 
    q.push(13); 
    q.push(14); 
    q.push(15); 
    q.push(16); 
    q.push(17); 
    q.push(18);
    print(q);
    interleave(q);
    print(q);
}
