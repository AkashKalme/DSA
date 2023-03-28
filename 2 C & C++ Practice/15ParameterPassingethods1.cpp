// Pass by Value
#include <iostream>

using namespace std;

int increment (int a, int b)
{
    a++;
    cout << a << endl;

    b--;
    cout << b << endl << endl;

    return 0;
}

int main()
{
    int num1 = 10, num2 = 20;
    increment(num1, num2);
    cout << num1 << endl;
    cout << num2 << endl;

    return 0;
}