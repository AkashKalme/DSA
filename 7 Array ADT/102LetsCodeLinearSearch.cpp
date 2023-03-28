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

void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

int Linear_Search(Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key ==arr->A[i])
            return i;
    }
    return -1;
}

int Transposition_Linear_Search(Array *arr, int key)
{
    int i;
    for (i = 0; i < arr->length; i++)
    {
        if (key ==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int main()
{

    Array arr = {{2,4,6,8,10},10,5};

    Display(arr);
    cout << endl;
    cout << Linear_Search(&arr,4);
    cout << endl;
    cout << Transposition_Linear_Search(&arr, 6);
    cout << endl;
    Display(arr);

    return 0;
}