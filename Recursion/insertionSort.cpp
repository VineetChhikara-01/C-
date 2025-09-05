#include<iostream>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

void sort(vector<int>& arr,int n){
    if(n==0 || n==1){
        return;
    }

    sort(arr,n-1);

    for(int i=n-1;i>0;i--){
        if(arr[i]<arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
    }
}

int main(){
    vector<int> arr = {65,4,-3,2,-1,0};
    cout<<"Before Sorting : ";
    print(arr);
    cout<<"After Sorting : ";
    sort(arr,6);
    print(arr);
    return 0;
}