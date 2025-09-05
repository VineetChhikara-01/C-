#include<iostream>
using namespace std;

int main(){
    int deci , binary;
    cout<<"Enter decimal number";
    cin>>deci;

    int pow = 1;
    int ans = 0;
    while(deci>0){
        int rem = deci%2;
        deci = deci/2;
        ans = ans + (rem*pow);
        pow = pow*10;
    }
    cout<<"Binary number is "<<ans<<endl;
    return 0;
}
