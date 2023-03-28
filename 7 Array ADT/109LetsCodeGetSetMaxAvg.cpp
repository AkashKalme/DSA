#include<iostream>

using namespace std;

class Array
{
public:
    int A[10];
    int size;
    int length;
};

void Display(Array arr)
{
    int i;
    cout << "\nElements of Array: ";
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}

int Get(Array arr, int index)
{
    if (index >= 0 && index < arr.length)
        return arr.A[index];
    return -1;
}

void Set(Array *arr, int index, int x)
{
    if (index >= 0 && index < arr->length)
        arr->A[index] = x;
}

int Max(Array arr)
{
    int max = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] > max)
            max = arr.A[i];
    }
    return max;
}

int Min(Array arr)
{
    int min = arr.A[0];
    for (int i = 0; i < arr.length; i++)
    {
        if (arr.A[i] < min)
            min = arr.A[i];
    }
    return min;
}

int Sum(Array arr)
{
    int S = 0;
    for (int i = 0; i <arr.length; i++)
        S += arr.A[i];
    return S;
}

int Avg(Array arr)
{
    return (float)Sum(arr)/arr.length;
}

int main()
{

    Array arr = {{2,4,6,8,10},10,5};

    Display(arr);
    cout << endl;
    cout << Get(arr, 4);
    cout << endl;
    Set(&arr, 2, 5);
    Display(arr);
    cout << endl;
    cout << Max(arr);
    cout << endl;
    cout << Min(arr);
    cout << endl;
    cout << Sum(arr);
    cout << endl;
    cout << Avg(arr);

    cout << endl;

    return 0;
}