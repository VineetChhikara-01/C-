#include <iostream>
using namespace std;
long long int power(int a, int b)
{
    long long int ans = 1;
    if (b == 0)
    {
        return 1;
    }
    if (b == 1)
    {
        return a;
    }
    ans = power(a, b / 2);
    if (!(b & 1))
    {
        return (ans * ans);
    }
    else
    {
        return (a * ans * ans);
    }
}

int main()
{
    cout << power(10, 10) << endl;
    return 0;
}