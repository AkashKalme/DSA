#include<iostream>

using namespace std;

// Simple Recursive Function
int func1(int n)
{
        if (n > 0)
    {
        return func1(n-1) + n;
    }
    return 0;
}

// Recursive Function using Static Variable
int func2(int n)
{
    static int x = 0;
    if (n > 0)
    {
        x++;
        return func2(n-1) + x;
    }
    return 0;
}

// Recursive Function using Global Variable
int y = 0;
int func3(int n)
{
    if (n > 0)
    {
        y++;
        return func3(n-1) + y;
    }
    return 0;
}

int main()
{
    int a = 5;
    cout << "Simple Recursive Function: " << func1(a) << endl;
    cout << "Recursive Function using Static Variable: " << func2(a) << endl;
    cout << "Recursive Function using Global Variable 1: " << func3(a) << endl;
    cout << "Recursive Function using Global Variable 2: " << func3(a) << endl;
    return 0;
}