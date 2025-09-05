#include<iostream>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

void sort(vector<int>& arr,int n){
    // int n = arr.size();
    if(n==0 || n==1){
        return;
    }
    bool swapped = false;
    for(int i=0;i<n-1;i++){
        if(arr[i]>arr[i+1]){
            swap(arr[i],arr[i+1]);
            swapped = true;
        }
    }
    if(!swapped){
        return;
    }
    sort(arr,n-1);
}

int main(){
    vector<int> arr = {55,44,323,7,2,12};
    cout<<"Before Sorting : ";
    print(arr);
    cout<<"After Sorting : ";
    sort(arr,6);
    print(arr);
    return 0;
}