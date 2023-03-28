#include <iostream>

using namespace std;

int main()
{
    int a = 20;
    int &r = a;

    cout << a << endl << r << endl;

    r++;

    cout << a << endl << r << endl;

    int b = 40;
    r = b;

    cout << a << endl << r << endl << b << endl;

    return 0;
}