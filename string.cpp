// #include<iostream>
// using namespace std;
// #include<string>
// void reverse(char ch[],int start,int size){
//     int end = size-1;
//     while(start<=end){
//         swap(ch[start++],ch[end--]);
//     }
// }

// int length(char ch[]){
//     int count=0;
//     int i=0;
//     while(ch[i]!='\0'){
//         count++;
//         i++;
//     }
//     return count;
// }

// int main(){
//     string s ;
//     getline(cin,s);
//     cout<<s<<endl;
//     int n=s.size();
//     int st=0;
//     int end = n-1;
//     char ch[n+1] ;
//     ch[n]='\0';
//     int ind=0;
//     int swapInd=0;
//     while(st<=end){
        
//         if((s[st]==' ') || (s[st]=='\0')){
//             int endInd = length(ch);
//             cout<<"swapInd "<<swapInd<<endl;
//             cout<<"End Index for "<<st<<" is "<<endInd<<endl;
//             cout<<"BEfore Reverse (CH)"<<endl;
//             cout<<ch<<endl;
//             reverse(ch,swapInd,endInd);
//             cout<<"After Reverse (CH)"<<endl;
//             cout<<ch<<endl;
//             swapInd = endInd-1;
//             st++;
//         } else{
//             cout<<"Value of String for "<<st<<" is "<<s[st]<<endl;
//             ch[ind] = s[st];
//             st++;
//             ind++;
//         }
//     }
//     cout<<ch<<endl;
//     // cout<<reverse(ch,0,length(ch))<<endl;
    
//     return 0;
// }
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
    string s;
    getline(cin, s);
    int start = 0;
    int n = s.length();

    for (int i = 0; i <= n; i++) {
        if (i == n || s[i] == ' ') {
            reverse(s.begin() + start, s.begin() + i); 
            start = i + 1; 
        }
    }
    cout << s << endl;
    return 0;
}