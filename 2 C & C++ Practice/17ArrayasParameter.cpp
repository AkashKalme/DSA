#include <iostream>

using namespace std;

void func1(int *A, int n)
{
    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
    
    cout << endl;

    A[0] = 2;

    for (int i = 0; i < n; i++)
        cout << A[i] << " ";
}

int *func2 (int size)
{
    int *p;
    p = new int[size];

    for(int i = 0; i < size; i++)
        p[i] = i+1;
    
    return p;
}

int main()
{
    int A[] = {1,3,5,7,9};
    int n = 5;

    func1(A, 5);
    cout << endl;

    int *ptr, sz = 5;
    ptr = func2(sz);

    for(int i = 0; i < sz; i++)
        cout << ptr[i] << " ";

    cout << endl;

    return 0;
}