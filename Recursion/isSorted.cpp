#include<iostream>
using namespace std;

void arrayInput(int *arr,int n){
    cout<<"Enter Array Elements"<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
}

bool isSorted(int *arr,int n){
    if(n==0 || n==1){
        return true;
    }

    return isSorted(arr+1,n-1) && arr[0]<=arr[1];
}


int main(){
    int n = 6;
    int arr[6];
    arrayInput(arr,n);
    if(isSorted(arr,n)){
        cout<<"Array is Sorted";
    }
    else{
        cout<<"Not Sorted";
    }
    return 0;
}