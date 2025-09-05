#include<iostream>
using namespace std;
// findPivot only work with rotated sorted array else for only sorted array it returns end value of array
int findPivot(int arr[],int start,int end){
    int mid = start + (end-start)/2;
    if(start>=end){
        return start;
    }
    if(arr[mid]>=arr[0]){
        return findPivot(arr,mid+1,end);
    } else {
        return findPivot(arr,start,mid);
    } 
}
int searchB(int arr[],int start,int end,int key){
    if(start>end){
        return -1;
    }
    int mid = start + (end-start)/2;
    if(arr[mid]==key){
        return mid;
    } else if(key<arr[mid]){
        return searchB(arr,start,mid-1,key);
    } else {
        return searchB(arr,mid+1,end,key);
    }  
}

int main(){
    int n = 10;
    int arr[] = {3 ,4, 5, 6 ,7 ,8, 9 ,10 ,11 ,12 };
    int key = 4;
    // int arr[] = {3,4,5,1,2};
    // pivot using recursion and binary Search
    cout<<"The pivot for array of size "<<n-1<<" is at : "<<findPivot(arr,0,n-1)<<endl;
    int pivot1 = findPivot(arr,0,n-1);
    if(key>=arr[pivot1] && key<=arr[n-1]){
        cout<< searchB(arr,pivot1,n-1,key)<<endl;
    } else{
        cout<< searchB(arr,0,pivot1-1,key)<<endl;
    }
    return 0;
}