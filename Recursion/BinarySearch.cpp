#include<iostream>
using namespace std;

bool binarySearch(int arr[],int start,int end,int key){
    if(start>end){
        return 0;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        return 1;
    } else if(arr[mid]>key){
        return binarySearch(arr,start,mid-1,key);
    } else{
        return binarySearch(arr,mid+1,end,key);
    }
}

int main(){
    int key;
    cout<<"Enter Element to search :";
    cin>>key;
    int n=10;
    int arr[]={1,4,5,6,8,10,18,75,90,100};
    cout<<"Element is "<<((binarySearch(arr,0,n-1,key))?"Present":"Absent");
    return 0;
}