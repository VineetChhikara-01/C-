#include <iostream>
using namespace std;
// int AP(int n){
//     return (3*n)+7;
// }
int setBits(int a, int b){
    int bits =0;
    while(a!=0 || b!=0){
        if(a&1){
            bits++;
        }
        if(b&1){
            bits++;
        }
        a >>=1;
        b>>=1;
    }
    return bits;
}
int fibonaci(int n){
    int a=0,b=1;
    int ans=0;
    while(n>2){
        ans = a+b;
        a=b;
        b=ans;
        n--;
    }
    return ans;
}
int main()
{
    // char c = 'A';
    // while (i < n)
    // {
    //     int j = 0;
    //     while (j <= i)
    //     {
    //         cout << char('A'+n-i+j-1) <<" ";
    //         j++;
    //         // c++;
    //     }
    //     cout << endl;
    //     i++;
    // }
    // int n;
    // cin >> n;
    // switch(1){
    //     case 1:
    //         cout<<"100 rupee note :"<<n/100<<endl;
    //         n%=100;
    //     case 2:
    //         cout<<"50 repee note :"<<n/50<<endl;
    //         n%=50;
    //     case 3:
    //         cout<<"20 rupee note :"<<n/20<<endl;
    //         n%=20;
    //     case 4:
    //         cout<<"10 rupee note :"<<n/10<<endl;
    //         n%=10;
    //     case 5:
    //         cout<<"5 rupee note :"<<n/5<<endl;
    //         n%=5;
    //     case 6:
    //         cout<<"2 rupee note :"<<n/2<<endl;
    //         n%=2;
    //     case 7:
    //         cout<<"1 rupee note :"<<n<<endl;
    //         n%=1;
    // }
    // int i = 0;
    // while (i < n)
    // {
    //     int j = 0;
    //     while(j< n-i){
    //         cout<<j+1;
    //         j++;
    //     }
    //     j=0;
    //     while(j<i){
    //         cout<<"*";
    //         j++;
    //     }
    //     j=0;
    //      while(j<i){
    //         cout<<"*";
    //         j++;
    //     }
    //     j=0;
    //     while(j<n-i){
    //         cout<<n-i-j;
    //         j++;
    //     }
    //     cout << endl;
    //     i++;
    // }
    int n,b;
    cout<<"Input ";
    cin>>n;
    // cout<<"Total bits:"<<setBits(n,b);
    cout<<"Fibonacci for "<<n<<" term is "<<fibonaci(n);
    }