#include<iostream>
#include<vector>
using namespace std;

void print(vector<int> arr,int s,int e){
    for (int i = s; i <= e; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int partition(vector<int> &arr,int s,int e){
    int p = s;
    int count = 0;
    for(int i = s+1;i<=e;i++){
        if(arr[i]<=arr[p]){
            count++;
        }
    }
    p += count;
    swap(arr[p],arr[s]);

    int i=s,j=e;
    while(i<p && j>p){
        while(arr[i]<arr[p]){
            i++;
        }
        while(arr[j]>arr[p]){
            j--;
        }
        if(i<p && j>p){
            swap(arr[i],arr[j]);
        }
    }

    return p;
}

void quicksort(vector<int> &arr,int s,int e){
    if(s>=e)
        return;
    int p = partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}

int main(){
    int n;
    cout<<"Enter size of array : ";
    cin>>n;
    vector<int> arr;
    int ele;
    cout<<"Enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin>>ele;
        arr.push_back(ele);
    }
    cout<<"Array : ";
    print(arr,0,n-1);
    quicksort(arr,0,n-1);
    cout<<"Array after quick sort : ";
    print(arr,0,n-1);


    
    return 0;
}