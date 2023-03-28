#include<iostream>

using namespace std;

int sum(int n)
{
    if (n == 0)
        return 0;
    return sum(n-1)+n;
}

int Isum(int n)
{
    int i_sum = 0;
    for (int i = 0; i <= n; i++)
        i_sum += i;
    return i_sum;
}

int main()
{
    cout << sum(10) << endl;

    cout << Isum(10) << endl;

    return 0;
}