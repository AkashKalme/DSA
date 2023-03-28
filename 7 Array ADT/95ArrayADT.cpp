#include<iostream>

using namespace std;

class Array
{
public:
    int *A;
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

class Array2
{
public:
    int A[10];
    int size;
    int length;
};

void Display(Array2 arr)
{
    int i;
    cout << "\nElements of Array: ";
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
}


int main()
{
    Array arr;
    int n, i;
    cout << "Enter the Size of Array: ";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    cout << "Enter Number of Elements in Array: ";
    cin >> n;
    cout << "\nEnter Elements of Array: ";
    for (i = 0; i < n; i++)
    {
        cin >> arr.A[i];
    }
    arr.length = n;


    Array2 arr2 = {{2,4,6,8,10},10,5};

    Display(arr);
    Display(arr2);

    return 0;
}