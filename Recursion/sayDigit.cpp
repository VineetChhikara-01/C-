#include<iostream>
using namespace std;

void sayDigit(int n){
    if((n) == 0){
        return;
    }
    
    string arr[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
    int rem = n%10;
    n=n/10;
    sayDigit(n);
    cout<<" "<<arr[rem];
}

int main(){
    int n;
    cout<<"Enter the number ";
    cin>>n;
    sayDigit(n);
    return 0;
}