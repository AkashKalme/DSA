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

void Insert_Sort(Array *arr, int x)
{
    int i = arr->length-1;
    if (arr->length == arr->size)
        return;
    while (i >= 0 && arr->A[i] > x)
    {
        arr->A[i+1] = arr->A[i];
        i--;
    }
    arr->A[i+1] = x;
    arr->length++;
}

int isSorted(Array arr)
{
    int i;
    for (i = 0; i < arr.length-1; i++)
    {
        if (arr.A[i] > arr.A[i+1])
            return false;
    }
    return true;
}

void Rearrange(Array *arr)
{
    int i, j;
    i = 0;
    j = arr->length-1;
    while (i<j)
    {
        while (arr->A[i] < 0)
            i++;
        while (arr->A[j] >= 0)
            j--;
        if (i<j)
            swap(arr->A[i], arr->A[j]);
    }
}

int main()
{
    Array arr = {{-2,-4,2,4,6,8,10},10,7};

    Display(arr);
    cout << endl;
    Insert_Sort(&arr, 7);
    Display(arr);
    cout << endl;
    cout << isSorted(arr);
    cout << endl;
    Rearrange(&arr);
    Display(arr);

    return 0;
}