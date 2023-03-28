#include<iostream>

using namespace std;

class Array
{
public:
    int A[20];
    int size;
    int length;
    void Display();
    void Find_Missing();
};

void Array::Display()
{
    int i;
    cout << "\nElements of Array: ";
    for (i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
}

void Array::Find_Missing()
{
    int Sum = 0, Sum2;
    for (int i = 0; i < length; i++)
    {
        Sum = Sum + A[i];
    }
    int n = A[length-1];
    Sum2 = (n*(n+1))/2;
    int Missing = Sum2 - Sum;
    cout << Missing;
}



int main()
{
    Array arr = {{1,2,3,4,5,6,8,9,10,11,12},20,11};

    arr.Display();
    cout << endl;
    arr.Find_Missing();

    return 0;
}