#include <iostream>

using namespace std;

void func1(int n)                           // Tail Recursion
{
    if (n > 0)
    {
        cout << n << " ";
        func1(n-1);
    }
}

void func2(int n)                           // Head Recursion
{
    if (n > 0)
    {
        func2(n-1);
        cout << n << " ";
    }
}

int main()
{
    int x = 3;
    func1(3);
    cout << endl;

    func2(3);
    cout << endl;

    return 0;
}