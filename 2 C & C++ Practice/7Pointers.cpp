#include <iostream>

using namespace std;

int main()
{
    int a = 10;
    int *p;
    p = &a;

    int b[5] = {2,4,6,8,10};
    int *q;
    q = b;

    cout << a << endl;
    cout << &a << endl;
    cout << p << endl;
    cout << *p << endl;

    cout << b << endl;
    cout << &b << endl;
    cout << q << endl;
    cout << *q << endl;

    for (int i = 0; i < 5; i++)
    {
        cout << q[i] << " ";
        cout << b[i] << " ";
    }

    return 0;
}