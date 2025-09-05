#include<iostream>
using namespace std;

int main(){
   int a,b;
   cout<<"Enter a and b :";
   cin>>a>>b;
   char c;
   cout<<"Enter operator(+,-,*,/,%) :";
   cin>>c;
   switch (c)
   {
   case '+' :
    cout<<"Sum:"<<a+b;
    break;
   case '-':
    cout<<"Subtraction :"<<a-b;
    break;
   case '*':
    cout<<"Multiplication:"<<a*b;
    break;
   case '/':
    if(b==0)
    cout<<"denominator can't be 0";
    else
    cout<<"Division:"<<(float)a/b;
    break;
   case '%':
    if(b==0)
    cout<<"Can't divide.";
    else
    cout<<"Modulous:"<<a%b; 
    break;
   default :
    cout<<"Wrong operator entered.";
    break;
   }
    return 0;
}
