#include<iostream>
using namespace std;

int fibonacciLoop(int n){
    if(n==0){
        return 0;
    } 
    if(n==1){
        return 1;
    }
    int i=0,j=1,sum=0;
    for(int k=2;k<=n;k++){
        sum = i+j;
        i=j;
        j=sum;
    }
    return sum;
}
int fibonacciRec(int n){
    if(n==0){
        return 0;
    } 
    if(n==1){
        return 1;
    }
    int ans = fibonacciRec(n-1) + fibonacciRec(n-2);
    return ans;
}

int main(){
    int n;
    cout<<"Enter number";
    cin>>n;
    cout<<endl;
    cout<<fibonacciLoop(n)<<endl;
    cout<<fibonacciRec(n);
    return 0;
}