// Incomplete
#include<iostream>

using namespace std;

class Array
{
private:
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:
    Array()
    {
        size = 10;
        length = 0;
        A = new int[size];
    }

    Array(int sz)
    {
        size = sz;
        length = 0;
        A = new int[size];
    }
    ~Array()
    {
        delete []A;
    }

    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Linear_Search(int key);
    int Binary_Search(int key);
    int Get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    float Avg();
    void Reverse();
    void Reverse2();
    Array* Merge(Array *arr2);
    Array* Union(Array *arr2);
    Array* Intersection(Array *arr2);
    Array* Difference(Array *arr2);
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

void Array::Append(int x)
{
        if (length < size)
        A[length++] = x;
}

void Array::Insert(int index, int x)
{
    int i;
    if (index >= 0 && index <= length)
    {
        for (i = length; i > index; i--)
        {
            A[i] = A[i-1];
        }
        A[index] = x;
        length++;
    }
}

int Array::Linear_Search(int key)
{
    int i;
    for (i = 0; i < length; i++)
    {
        if (key == A[i])
            return i;
    }
    return -1;
}

int Array::Binary_Search(int key)
{
    int low, mid, high;
    low = 0;
    high = length-1;
    while (low <= high)
    {
        mid = (high + low) / 2;
        if (key == A[mid])
            return mid;
        else if (key < A[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int Array::Get(int index)
{
    if (index >= 0 && index < length)
        return A[index];
    return -1;
}

void Array::Set(int index, int x)
{
    if (index >= 0 && index < length)
        A[index] = x;
}

int Array::Max()
{
    int max = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

int Array::Min()
{
    int min = A[0];
    for (int i = 0; i < length; i++)
    {
        if (A[i] < min)
            min = A[i];
    }
    return min;
}

int Array::Sum()
{
    int S = 0;
    for (int i = 0; i < length; i++)
        S += A[i];
    return S;
}

float Array::Avg()
{
    return (float)Sum()/length;
}

void Array::Reverse()
{
    int *B;
    int i, j;
    B = new int[length];
    for(i = length-1,j = 0; i >= 0; i--, j++)
        B[j] = A[i];
    for (i = 0; i < length; i++)
        A[i] = B[i];
}

void Array::Reverse2()
{
    int i, j;
    for (i = 0, j = length-1; i < j; i++, j--)
        swap(&A[i], &A[j]);
}

/* Array* Merge(Array arr2)
{
    int i, j, k;
    i=j=k=0;
    
    Array *arr3 = new Array(length +arr2.length);
    
    while (i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else
            arr3->A[k++] = arr2.A[j++];
    }
    for (; i<length; i++)
        arr3->A[k++] = A[i];
    for (; j<length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = length + arr2.length;
    arr3->size = 10;

    return arr3;
}

Array* Union(Array arr2)
{
    int i, j, k;
    i=j=k=0;
    
    Array *arr3 = new Array(length +arr2.length);
    
    while (i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            arr3->A[k++] = arr2.A[j++];
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    for (; i<length; i++)
        arr3->A[k++] = A[i];
    for (; j<length; j++)
        arr3->A[k++] = arr2.A[j];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

Array* Intersection(Array arr2)
{
    int i, j, k;
    i=j=k=0;
    
    Array *arr3 = new Array(length +arr2.length);
    
    while (i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            i++;
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            arr3->A[k++] = A[i++];
            j++;
        }
    }
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}

Array* Difference(Array arr2)
{
    int i, j, k;
    i=j=k=0;
    
    Array *arr3 = new Array(length +arr2.length);
    
    while (i < length && j < arr2.length)
    {
        if(A[i] < arr2.A[j])
            arr3->A[k++] = A[i++];
        else if (arr2.A[j] < A[i])
            j++;
        else
        {
            i++;
            j++;
        }
    }
    for (; i<length; i++)
        arr3->A[k++] = A[i];
    arr3->length = k;
    arr3->size = 10;

    return arr3;
}       */

int main()
{
    Array *arr1;
    int ch, sz;
    int x, index;

    cout << "Enter Size of Array: ";
    cin >> sz;
    arr1 = new Array(sz);



    return 0;
}