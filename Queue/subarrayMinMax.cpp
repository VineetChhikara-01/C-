#include<iostream>
#include<queue>
using namespace std;

// brute force 
int solveN2(int *arr,int n,int k){
    int ans = 0;
    for(int i=0;i<n-k+1;i++){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int j=i;j<i+k;j++){
            mini = min(mini,arr[j]);
            maxi = max(maxi,arr[j]);
        }
        ans += mini+maxi;
    }
    return ans;
}

// using deque
int solve(int *arr,int n,int k){
    int ans = 0;
    deque<int> mini(k);
    deque<int> maxi(k);
    for(int i=0;i<k;i++){
        while(!mini.empty() && arr[i]<= arr[mini.back()]){
            mini.pop_back();
        }
        while(!maxi.empty() && arr[i]>=arr[maxi.back()]){
            maxi.pop_back();
        }
        mini.push_back(i);
        maxi.push_back(i);
    }
    ans += arr[mini.front()] + arr[maxi.front()];
    for(int i=k;i<n;i++){
        
        // remove the element if it is not in window
        if(!mini.empty() && i-mini.front()>=k){
            mini.pop_front();
        }
        if(!maxi.empty() && i-maxi.front()>=k){
            maxi.pop_front();
        }
        
        // removing element if we get smaller element than the last element
        while(!mini.empty() && arr[i]<= arr[mini.back()]){
            mini.pop_back();
        }
        // removing element if we get element greater element than the last element
        while(!maxi.empty() && arr[i]>=arr[maxi.back()]){
            maxi.pop_back();
        }

        mini.push_back(i);
        maxi.push_back(i);
        ans += arr[mini.front()] + arr[maxi.front()];
    }
    return ans;
}
int main(){
    int arr[10] = {2,5,-1,7,-3,-1,-2,0,5,-10};
    int k = 4;
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<solveN2(arr,n,k)<<endl;
    cout<<solve(arr,n,k)<<endl;
}