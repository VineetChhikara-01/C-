#include<iostream>
using namespace std;

int main(){
    int row;
    cout<<"Enter the number of rows";
    cin >> row;
    int **arr = new int*[row];
    int *size = new int[row];
    cout<<"enter the number of columns for each row"<<endl;

    for(int i=0;i<row;i++){
        cin>>size[i];
    }
    for(int i=0;i<row;i++){
        arr[i] = new int[size[i]];
    }
    cout<<"enter the elements of jaggered array"<<endl;
    for(int i=0;i<row;i++){
        for (int j = 0; j < size[i]; j++)
        {
            cin>>arr[i][j];
        }
    }
    cout<<"Jaggered Array"<<endl;
    for(int i=0;i<row;i++){
        for (int j = 0; j < size[i]; j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }
    for (int i = 0; i < row; i++)
    {
        delete arr[i];
    }
    delete[] arr;
    delete[] size;
    
    return 0;
}