#include<iostream>
#include<vector>
using namespace std;

void seive(vector<int> &prime,int sqroot){
    vector<bool> isprime(sqroot+1,true);
    for(int i=2;i<=sqroot;i++){
        if(isprime[i]){
            prime.push_back(i);
            for(int j=i*i;j<=sqroot;j+=i){
                isprime[j]=false;
            }
        }
    }
}

long long segmentedSeive(int L,int R){
    int sqroot = (sqrt(R))+1;
    vector<int> prime;
    seive(prime,sqroot);
    vector<bool> mark(R-L+1,true);
    if(L==1){
        mark[0] = false;
    } else if(L==0){
        mark[0]=mark[1]=false;
    }
    for(int val:prime){
        int multiple = (val*val);
        while(multiple<L){
            multiple+=val;
        }
        for (int j = multiple; j<=R; j+=val)
        {
            mark[j-L]=false;
        }
    }
    int count = 0;
    long long product = 1;
    vector<int> ans;
    for(int i=0;i<mark.size();i++){
        if(mark[i]){
            count++;
            ans.push_back(i+L);
            product = (product * (i+L))%1000000007;
        }
    }
    return product;
}

int main(){
    int l,r;
    cout<<"enter the value of L:";
    cin>>l;
    cout<<"enter the value of R:";
    cin>>r;
    vector<int> number;
    if(l<0){
        cout<<"L should be a positive";
    } else{
        // number = segmentedSeive(l,r);
        cout<<"Product of Prime numbers between "<<l<<" and "<<r<<" are "<<segmentedSeive(l,r);
    }
    // for(int val : number){
    //     cout<<val<<" ";
    // }
}