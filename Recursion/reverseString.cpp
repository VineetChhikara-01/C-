#include<iostream>
using namespace std;

// void reverse(long int s,long int e,string &st){
//     if(s>e){
//         return;
//     }
//     swap(st[s],st[e]);
//     s++;
//     e--;
//     reverse(s,e,st);
// }
void reverse(int i,string& str){
    int n = str.length()-1;
    cout<<str<<endl;
    if(i>=(n-i)){
        return;
    }
    swap(str[i],str[n-i]);
    reverse(i+1,str);
}
int main(){
    string s = "tera yaar defaulter";
    reverse(0,s);
    cout<<s.length()<<endl;
    cout<<"Reversed string is "<<s;
    return 0;
}