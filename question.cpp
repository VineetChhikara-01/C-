#include<iostream>
#include<vector>
using namespace std;

// int binarysearch(int vec[],int search,int low,int high){
//     int mid = low+(high-low)/2;
//     if(vec[mid]==search){
//         return mid+1;
//     } else if (vec[mid]>search){
//         return binarysearch(vec,search,low,mid-1);
//     } else {
//         return binarysearch(vec,search,mid+1,high);
//     }
//     return -1;
// }

void product(int vec[],int n){
    int product=1;
    int vec2[n];
    for(int i=0;i<n;i++){
        product=1;
        for(int j=0;j<n;j++){
            if(i==j){
                continue;
            } else {
                product *= vec[j];
            }
        }
        vec2[i] = product;
    }
    cout<<"Product with self array : ";
    for(int val=0 ;val<n;val++){
        cout<<vec2[val]<<" ";
    }
    return ;
}
int main(){

    int n;
    cout<<"Enter number of elements : ";
    cin>>n;
    int vec[n];
    cout<<"Enter list of elements : ";
    for(int i=0;i<n;i++){
        cin>>vec[i];
    }
    for(int val=0 ;val<n;val++){
        cout<<vec[val]<<" ";
    }
    cout<<endl;
    
    product(vec,n);

    // int search;
    // cout<<"Enter element to search : ";
    // cin>>search;
    // cout<<"Element found at "<<binarysearch(vec,search,0,n-1);
    // cout<<endl<<"Array : ";
    // for(int val=0;val<n;val++){
    //     cout<<vec[val]<<" ";
    // }
    // int n,j,max = INT_MIN,min = INT_MAX,sum=0,average;
    // cout<<"Enter number of elements : ";
    // cin>>j;
    // for(int i=0;i<j;i++){
    //     cout<<"Enter "<<i+1<<" element :";
    //     cin>>n;
    //     //sum
    //     sum+=n;
    //     //max
    //     if(max<n){
    //         max = n;
    //     }
    //     //min
    //     if(min>n){
    //         min = n;
    //     }
    // }
    // cout<<"Sum : "<<sum<<endl;
    // cout<<"Average : "<<(float)sum/n<<endl;
    // cout<<"MINIMUM : "<<min<<endl;
    // cout<<"MAXIMUM : "<<max<<endl;
    return 0;
}