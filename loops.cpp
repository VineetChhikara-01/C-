#include<iostream>
using namespace std;

int main(){
    //for loop
    // int n = 5,sum=0;
    // cout<<sum<<endl;
    // for(int i=1;i<=5;i++){
    //     sum = sum + i;
    //     cout<<i<<":"<<sum<<" ";
    // }
    // cout<<"Sum:"<<sum<<endl;
    
    //sum of odd numbers
    // int i=0;
    // while(i<=n){
    //     if(i%2==0){
            
    //     }else{
    //         sum+=i;
    //     }
    //     i++;
    // }
    // cout<<sum<<endl;

    //prime or not
    // int n;
    // cin>>n;
    // int count=0;
    // for(int i=2;i<n;i++){
    //     if(n%i==0){
    //         count=1;
    //     }
    // }
    // if(count==0){
    //     cout<<"Prime";
    // }else{
    //     cout<<"not prime";
    // }

    //factorial
    // int n;
    // cout<<"Enter no.:";
    // cin>>n;
    // int fact=1;
    // for(int i=1;i<=n;i++){
    //     fact=(float)fact*i;
    // }
    // cout<<"Factorial:"<<fact;

    //Sum of N natural no. divisible by 3
    int n;
    cout<<"Enter No.:";
    cin>>n;
    int sum=0;
    for(int i=0;i<=n;i++){
        if(i%3==0){
            sum=sum+i;
        }
    }
    cout<<"Sum is :"<<sum<<endl;
    return 0;
}