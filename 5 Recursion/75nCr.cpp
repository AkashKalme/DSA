#include<iostream>

using namespace std;

int fact(int n)
{
    if (n == 0)
        return 1;
    return fact(n-1)*n;
}

int nCr(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n-r);
    return t1/(t2*t3);
}

int nCr2(int n, int r)
{
    if (r==0 || n==r)
        return 1;
    return nCr2(n-1,r-1) + nCr2(n-1,r);
}

int main()
{
    cout << nCr(5,2) << endl;
    cout << nCr2(5,2) << endl;

    return 0;
}