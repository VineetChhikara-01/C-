#include<iostream>
using namespace std;

int linearSearch(int arr[],int key,int n){
    if(n==0){
        return 0;
    }
    if(arr[0]==key){
        return n-n;
    }
   return n-linearSearch(arr+1,key,n-1)+1;
}

int main(){
    int arr[] ={ 1,4,2,6,3,6,7,100,4,3};
    cout<<"Key is at Index "<<(linearSearch(arr,100,10));
    return 0;
}