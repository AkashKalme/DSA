#include <iostream>

using namespace std;

int add (int a, int b)
{
    int c;
    c = a+b;

    return c;
}

int main()
{
    int num1 = 20, num2 = 40, sum;

    sum = add(num1, num2);

    cout << "Sum: " << sum; 
    return 0;
}