#include<iostream>
using namespace std;


int main(){
    int n;
    cout<<"Enter size of array:";
    cin>>n;
    int arr[n];
    cout<<"Enter array elements:";
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Array "<<endl;
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"Subarray"<<endl;
    int st = 0;
    int maxSum = INT_MIN;
    for(int st=0;st<n;st++){
        int currSum = 0;
        for(int j=st;j<n;j++){
            currSum += arr[j];
            maxSum = max(currSum,maxSum);
        }
        
    }
    cout<<maxSum;

    return 0;
} 