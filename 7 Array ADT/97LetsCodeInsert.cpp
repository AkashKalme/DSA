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

void Append (Array *arr, int x)
{
    if (arr->length < arr->size)
        arr->A[arr->length++] = x;
}

void Insert(Array *arr, int index, int x)
{
    int i;
    if (index >= 0 && index <= arr->length)
    {
        for (i = arr->length; i >index; i--)
        {
            arr->A[i] = arr->A[i-1];
        }
        arr->A[index] = x;
        arr->length++;
    }
}

int main()
{
    Array arr = {{2,3,4,5,6},10,5};

    Append(&arr, 10);
    Insert(&arr, 4, 15);
    Display(arr);

    return 0;
}