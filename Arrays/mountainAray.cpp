#include<iostream>
using namespace std;

int rotatedSearch(int arr[],int size,int key){
    int start =0;
    int end = size-1;
    int mid = start +(end-start)/2;
    while(start<end){

        if(key==arr[start]){
            return start;
        }
        if(key<arr[start]){
            start = mid+1;
        } else {
            end = mid;
        }
        mid = start+(end-start)/2;
    }
    return start;
}

int main(){
    int n;
    // cin>>n;
    int arr[] = {4,5,7,1,2,3};
    cout<<rotatedSearch(arr,n,3)<<endl;


}