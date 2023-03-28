#include<iostream>

using namespace std;

int Power1(int m, int n)
{
    if (n == 0)
        return 1;
    return Power1(m, n-1)*m;
}

int Power2(int m, int n)
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return Power2(m*m, n/2);
    else
        return m*Power2(m*m, (n-1)/2);
}

int main()
{
    cout << Power1(2,9) << endl;
    cout << Power2(2,9) << endl;

    return 0;
}