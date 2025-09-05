#include<iostream>
using namespace std;

//Minimun of 2 nos.
// int minimum(int a,int b){
//     if(a<b)
//         return a;
//     else
//         return b;
// }

//Sum of N natural Nos.
// int sumOfN(int n){
//     int sum=0;
//     for (int i = 1; i <= n; i++)
//     {
//         sum = sum +i;
//     }
//     return sum;
//}

//Factorial of N
// int factOfN(int n){
//     int fact=1;
//     for (int i = 1; i <= n; i++)
//     {
//         fact = fact*i;
//     }
//     return fact;
// }

// int sumofnos(int num){
//     int sum=0;
//     for (int i = num; i>0 ; i--)
//     {
//         int lastdigit = num%10;
//         sum += lastdigit;
//         num = num/10;
//     }
//     return sum;
// }

// int nCr (int n,int r){
//     int a=factOfN(n);
//     int b=factOfN(r);
//     int c=factOfN(n-r);
//     return a/(b*c);
// }

// int isPrime(int n){
//     bool isPrime=1 ;
//     for (int i = 2; i < n; i++)
//     {
//         if(n%i==0){
//             isPrime = 0;
//         }
//     }
//     if(isPrime) {
//         cout<<"Prime No."<<endl;
//     }  else {
//         cout<<"Not Prime";
//     }
// return 0;
// }


// void allPrime(int n){
    
//     for (int i = 2; i < n; i++)
//     {
//         bool isPrime = 1;
//        for (int j = 2; j < i; j++)
//         {
//             if(i%j==0){
//                 isPrime = 0;
//             } 
//         } 
    
//         if(isPrime){
//             cout<<i<<" ";
//         }
//     }
//     cout<<endl;
// } 

void fibonachi(int n){
    int fibo0= 0,fibo1=1,fibocurr;
    cout<<0<<" "<<1<<" ";
    for (int i = 2; i < n; i++)
    {
        fibocurr= fibo1 + fibo0;
        fibo0 = fibo1;
        fibo1 = fibocurr;
        cout<<fibocurr<<" ";
    }
    
}
int main(){
    int a;
    cout<<"Enter no.:";
    cin>>a;

    fibonachi(a);
    return 0;
}

