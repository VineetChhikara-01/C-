#include<iostream>
using namespace std;

long long int sqrtInt(long long int s,long long int e,int n){
    long long int mid = s + (e-s)/2;
    if(s>=e){
        return s;
    }
    if((mid*mid)==n){
        return mid;
    } else if((mid*mid)>n){
        return sqrtInt(s,mid-1,n);
    } else{
        long long int  ans = sqrtInt(mid+1,e,n);
        if((ans*ans)<=n){
            return ans;
        } else{
            return ans-1;
        }
    }
}

double precision(int n,int pre,double ans){
    double final = ans;
    double factor =1;
    for(int i=0;i<pre;i++){
        factor = factor/10;
        for (double j = final; (j*j) < n; j+=factor)
        {
            final = j;
        }
    }
    return final;
}
int main(){
    int n;
    cout<<"Enter the number ";
    cin>>n;
    long long int Integer = sqrtInt(0,n,n);
    cout<<"Integer Part "<<Integer<<endl;
    cout<<"Enter Presicion Point number ";
    int pre;
    cin>>pre;
    cout<<"Ans with Precision Point "<<precision(n,pre,Integer);
    return 0;
}