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

int Binary_Search(Array arr, int key)
{
    int low, mid, high;
    low = 0;
    high = arr.length-1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Recursive_BinarySearch(Array arr, int low, int high, int key)
{
    int mid;
    if (low <= high)
    {
        mid = (low + high) / 2;
        if (key == arr.A[mid])
            return mid;
        else if (key < arr.A[mid])
            return Recursive_BinarySearch(arr, low, mid-1, key);
        else
            return Recursive_BinarySearch(arr, mid+1, high, key);
    }
    return -1;
}

int main()
{
    Array arr = {{2,4,6,8,10},10,5};

    Display(arr);
    cout << endl;
    cout << Binary_Search(arr, 4);
    cout << endl;
    cout << Recursive_BinarySearch(arr, 0, arr.length, 5);
    cout << endl;

    return 0;
}