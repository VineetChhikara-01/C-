#include<iostream>
using namespace std;

int main(){
    int count;
    cout<<"Enter value :";
    cin>>count;
    
    //top
    for (int i = 0; i < count; i++)
    {
        //stars
        for (int j = 0; j <= i; j++)
        {
            cout<<"*";
        }
        //space
        for(int j=2*(count-i-1); j>0 ; j--)
        {
            cout<<" ";
        }
        //stars
        for (int j = 0; j <= i; j++)
        {
            cout<<"*";
        }
        cout<<endl;
    }
    //bottom
    for (int i = count; i > 0; i--)
    {
        //stars
        for (int j = i; j > 0; j--)
        {
            cout<<"*";
        }
        //space
        for(int j=0; j<2*(count-i); j++)
        {
            cout<<" ";
        }
        //stars
        for (int j = i; j > 0; j--)
        {
            cout<<"*";
        }

        cout<<endl;

    }
    
    
    
    return 0;
}