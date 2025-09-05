#include<iostream>
using namespace std;

int sumOfArray(int arr[],int n){
    if(n==0){
        return 0;
    }
    return sumOfArray(arr+1,n-1) + arr[0];
}

int main(){
    int arr[] ={ 1,4,2,6,3,6,7,100};
    cout<<"Sum of Elemnts of Array is "<<sumOfArray(arr,8);
    return 0;
}