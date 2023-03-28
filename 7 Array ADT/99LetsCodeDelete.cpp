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

int Delete(Array *arr, int index)
{
    int x = 0;
    int i;
    if(index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        for (i = index; i < arr->length-1; i++)
        {
            arr->A[i] = arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int main()
{
    Array arr = {{2,3,4,5,6},10,5};

    Append(&arr, 10);
    Insert(&arr, 4, 15);
    Delete(&arr, 2);
    Display(arr);

    return 0;
}