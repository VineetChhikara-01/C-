#include<iostream>
using namespace std;

// void deciToBinary(int deci){
//     int ans=0,pow=1,rem;
//     while(deci>0){
//         rem=deci%2;
//         deci=deci/2;
//         ans=ans+(rem*pow);
//         pow=pow*10;
//     }
//     cout<<ans;
// }

// void binaryToDeci(int n){
//     int ans=0,pow=1,rem,divi=10;
//     while (n>0)
//     {
//         rem=n%divi;
//         n=n/divi;
//         ans=ans+(rem*pow);
//         pow=pow*2;
//     }
//     cout<<ans;
// }

// void reverseInt(int n){
//     int rem=0,no=0,count=1,N=n;
//     while (N>0)
//     {
//         N=N/10;
//         count *= 10;
//     }
//     while (n>0)
//     {
//         rem = n % 10;
//         n = n/10;
//         count /=  10;
//         no += (rem*count);
//     }
//     cout<<"No. :"<<no;
// }


// void powerOfTwo(int n){ 
//    while (n%2==0)
//    {
//     n/=2;
//    }
//    if (n==1)
//    {
//     cout<<"Power of 2";
//    } else{
//     cout<<"Not";
//    }
// }

void powerOfTwoWithoutLoops(int n)
{
    int count=0;
    while(n>0){
        if (n & 1)
        {
            count++;
        }
        n>>=1;
    }
    if (count==1)
    {
        cout<<"2";
    } else {
        cout<<"not";
    }
    
}
int main(){
    int a;
    cout<<"Enter no.";
    cin>>a;
    powerOfTwoWithoutLoops(a);
    // reverseInt(a);
    //powerOfTwo(a);
    return 0;
}