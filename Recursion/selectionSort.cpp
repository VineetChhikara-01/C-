#include<iostream>
using namespace std;

void print(vector<int> arr){
    for(int i=0;i<arr.size();i++){
        cout<<arr[i]<<" ";
    } cout<<endl;
}

void sort(vector<int>& arr,int s,int n){
    if(n==0 || n==1){
        return ;
    }
    if(s>=(n-1)){
        return;
    }
    int mini = s;
    int i;
    for( i =s+1 ;i<n-1;i++){
        if(arr[i]<arr[mini]){
            mini = i;
        }
    }
    swap(arr[mini],arr[s]);
    sort(arr,s+1,n);
}

int main(){
    vector<int> arr = {4,2,6,1,9,10};
    cout<<"Before Sorting : ";
    print(arr);
    cout<<"After Sorting : ";
    sort(arr,0,6);
    print(arr);
    return 0;
}