#include <iostream>
using namespace std;

void printArray(int arr[], int size)
{
    cout << "Printing Array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void inputArray(int arr[], int size)
{
    cout << "Enter the elements of arr" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
}
int sumOfArray(int arr[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}
void reverseArray(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    for (int i = 0; i < size / 2; i++)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
}
void alternateReverse(int arr[], int size)
{
    int i = 0;
    while (i < (size - 1))
    {
        swap(arr[i], arr[i + 1]);
        i += 2;
    }
    cout << "Alternate Reverse";
}
int uniqueElement(int arr[], int size)
{
    int unique = 0;
    for (int i = 0; i < size; i++)
    {
        unique ^= arr[i];
    }
    return unique;
}
int duplicateEle(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int duplicate = arr[i];
        for (int j = i + 1; j < size; j++)
        {
            if (!(duplicate ^ arr[j]))
            {
                return arr[i];
            }
        }
    }
    return -1;
}
int duplicateOptimised(int arr[],int size){
    int ans=0;
    for(int i=0;i<size;i++){
        ans^=arr[i];
    }
    for(int i=1;i<size;i++){
        ans^=i;
    }
    return ans;
}
int interssection(int arr1[],int arr2[],int N,int M){
    bool value =0;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(arr1[i]<arr2[j]) 
            break;
            if(arr1[i]==arr2[j]){
                cout<<arr1[i]<<" ";
                arr2[j]=INT_MIN;
                value = 1;
                break;
            }
        }
    }
        if(value){
            return 0;
        }
    return -1;
}
int main()
{
    int size;
    cout << "Enter size of Array:";
    cin >> size;
    int size2;
    cout << "Enter size of Second Array:";
    cin >> size2;
    int arr[100];
    int arr2[100];
    inputArray(arr, size);
    printArray(arr, size);
    inputArray(arr2, size2);
    printArray(arr2, size2);
    interssection(arr, arr2, size, size2);
    // cout<<"Sum of Array : "<<sumOfArray(arr,size)<<endl;
    // reverseArray(arr,size);
    // printArray(arr,size);
    // alternateReverse(arr,size);
    // printArray(arr,size);
    // cout<<"unique element: "<<uniqueElement(arr,size)<<endl;
    // cout << "duplicate element: " << duplicateOptimised(arr, size) << endl;
    // int min = arr[0];
    // int max = arr[0];
    // for (int i = 1; i < size; i++)
    // {
    //     if (arr[i] < min)
    //     {
    //         min = arr[i];
    //     }
    //     if (arr[i] > max)
    //     {
    //         max = arr[i];
    //     }
    // }
    // cout << "Min: " << min << endl
    //      << "Max: " << max;
}
