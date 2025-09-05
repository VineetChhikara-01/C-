#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> arr, int s, int e)
{
    for (int i = 0; i <= e; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void merge(vector<int> &arr, int s, int e)
{
    int mid = s + (e - s) / 2;

    int l1 = mid - s + 1;
    int l2 = e - mid;
    int *arr1 = new int[l1];
    int *arr2 = new int[l2];
    // Array 1
    int ind = s;
    for (int i = 0; i < l1; i++)
    {
        arr1[i] = arr[ind++];
    }

    // Array 2
    ind = mid+1;
    for (int i = 0; i < l2; i++)
    {
        arr2[i] = arr[ind++];
    }
    int i = 0, j = 0;
    int im = s;
    while (i < l1 && j < l2)
    {
        if (arr1[i] > arr2[j]){
            arr[im++] = arr2[j++];
        } else {
            arr[im++] = arr1[i++];
        }
    }
    while (i < l1)
    {
        arr[im++] = arr1[i++];
    }
    while (j < l2)
    {
        arr[im++] = arr2[j++];
    }
    delete[] arr1;
    delete[] arr2;
}

void mergeSort(vector<int> &arr, int s, int e)
{
    if (s >= e)
        return;
    int mid = s + (e - s) / 2;

    mergeSort(arr, s, mid);
    mergeSort(arr, mid + 1, e);

    merge(arr, s, e);
}

int main()
{
    int n;
    cout << "Enter size of array : ";
    cin >> n;
    vector<int> arr;
    int ele;
    cout << "Enter the elements of array : ";
    for (int i = 0; i < n; i++)
    {
        cin >> ele;
        arr.push_back(ele);
    }
    cout << "Array : ";
    print(arr, 0, n - 1);
    mergeSort(arr, 0, n - 1);
    cout<<"Array after Sorting: ";
    print(arr, 0, n - 1);
    return 0;
}