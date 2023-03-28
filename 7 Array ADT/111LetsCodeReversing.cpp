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

void Reverse(Array *arr)
{
    int *B;
    int i, j;
    B = new int[arr->length];
    for(i = arr->length-1,j = 0; i >= 0; i--, j++)
        B[j] = arr->A[i];
    for (i = 0; i < arr->length; i++)
        arr->A[i] = B[i];
}

void Reverse2(Array *arr)
{
    int i, j;
    for (i = 0, j = arr->length-1; i < j; i++, j--)
        swap(&arr->A[i], &arr->A[j]);
}

int main()
{
    Array arr = {{2,4,6,8,10},10,5};

    Display(arr);
    cout << endl;
    Reverse(&arr);
    Display(arr);
    cout << endl;
    Reverse2(&arr);
    Display(arr);
    cout << endl;

    return 0;
}