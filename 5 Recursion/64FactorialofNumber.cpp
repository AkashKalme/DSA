#include<iostream>

using namespace std;

int factorial(int n)
{
    if (n == 0)
        return 1;
    return factorial(n-1)*n;
}

int Ifactorial(int n)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
        fact *= i;
    return fact;
}

int main()
{
    cout << factorial(5) << endl;
    cout << Ifactorial(5) << endl;

    return 0;
}