#include<iostream>
using namespace std;

// void reverseArr(int array[],int count){
//     int start=0,end=count-1;
//     while (start<end)
//     {
//         swap(array[start],array[end]);
//         start++;
//         end--;
//     }
    
//     for (int i = 0; i < count; i++)
//     {
//         cout<<array[i]<<endl;
//     }
    
// }


    //linear search
    // int a;
    // cout<<"Enter No.:";
    // cin>>a;
    // int ind = -1;
    // for (int i = 0; i < count; i++)
    // {
    //     if (a==array[i])
    //     {
    //         ind = i;
    //         break;
    //     } 
    // }
    // cout<<"Element at index :"<<ind<<endl;
    
    //smallest and largest of array
    // int count = 7,indexs=0,indexl=0;
    // int smallest = INT_MAX,largest = INT_MIN;
    // for (int i = 0; i < count; i++)
    // {
    //     if(array[i]<smallest){
    //         smallest = array[i];
    //         indexs = i;
    //     }
    //     if(array[i]>largest){
    //         largest = array[i];
    //         indexl = i;
    //     }
    // }
    // cout<<"Largest at "<<indexl<<" : "<<largest<<endl;
    // cout<<"Smallest at "<<indexs<<" : "<<smallest<<endl;

//to calculate sum and product of array
// void sumAndProduct(int array[],int sz){
//     int sum=0,product=1;
//     for (int i = 0; i < sz; i++)
//     {
//         sum += array[i];
//         product *= array[i];
//     }
    
//     cout<<"Sum : "<<sum<<endl;
//     cout<<"Product : "<<product;
// }

//Swap max and min
// void swapMinMax(int array[],int sz){
//     int small=INT_MAX,large=INT_MIN,il,is;
//     for (int i = 0; i < sz; i++)
//     {
//         if (array[i]<small)
//         {
//             small = array[i];
//             is = i;
//         }
//         if (array[i]>large)
//         {
//             large = array[i];
//             il = i;
//         }
        
//     }
//     cout<<"Smallest:"<<small<<endl;
//     cout<<"Largest:"<<large<<endl;
//     swap(array[is],array[il]);
// }

//Unique value of array
// void uniqueValue(int arr[],int sz){
    
//     for (int i = 0; i < sz; i++)
//     {
//         bool unique = 1;
//         for (int j = 0; j < sz; j++)
//         {
//             if(i==j){
//                 continue;
//             }
//             else if(arr[i]==arr[j])
//             {
//                 unique = 0;
//             }
            
//         }
//         if(unique){
//         cout<<arr[i]<<endl;
//         }
//     }
// }

//intersaction of two array
// void intersactionOfArray(int arr1[],int arr2[],int sz1,int sz2){

//     for (int i = 0; i < sz1; i++)
//     {
//         for (int j = 0; j < sz2; j++)
//         {
//             if (arr1[i]==arr2[j])
//             {
//                 cout<<arr1[i]<<" ";
//             }
            
//         }
        
//     }
//     cout<<endl;
// }
int main(){
    int array[] = {1,2,3,4,0,33};
    int sz = 6,sz2 = 5;
    int array2[] = {2,4,3,9,0};

    for (int i = 0; i < sz; i++)
    {
        cout<<array[i]<<" ";
    }
    cout<<endl;

    for (int i = 0; i < sz2; i++)
    {
        cout<<array2[i]<<" ";
    }
    cout<<endl;

    // intersactionOfArray(array,array2,sz,sz2);
    
    return 0;
}