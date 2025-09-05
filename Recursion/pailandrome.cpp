#include<iostream>
using namespace std;

bool pailndrome(int i,string &str){
    int n = str.length()-1;
    if(i>=(n-i)){
        return true;
    }
    if(str[i]==str[n-i]){
        return pailndrome(i+1,str);
    } 
    return false;
}

int main(){
    string str = "nitin";
    if (pailndrome(0,str))
    {
        cout<<"It's a pailndrome";
    } else {
        cout<<"Not a pailndrome";
    }
    
    return 0;
}