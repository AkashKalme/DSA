#include <iostream>

using namespace std;

template<class T>
void print(T& vec, int n, string s)
{
    cout << s << ": [" << flush;
    for(int i=0; i<n; i++)
    {
        cout << vec[i] << flush;
        if(i<n-1)
            cout << ", " << flush;
    }
    cout << "]" << endl << endl;
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l;
    int j = h;

    while(true)
    {
        while(i<=j && A[i]<=pivot)
        {
            i++;
        }
        while(i<=j && A[j]>pivot)
        {
            j--;
        }
        if(j<i)
            break;
        else
            swap(&A[i], &A[j]);
    }
    swap(&A[l], &A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int j;
    if(l<h)
    {
        j = partition(A, l, h);
        quickSort(A, l, j-1);
        quickSort(A, j+1, h);
    }
}

int main()
{
    int A[10] = {10, 78, 412, 185, 25, 85, 92, 25, 45, 12};

    quickSort(A, 0, 10);
    print(A, 10, "Quick Sort");
    cout << endl;

    return 0;
}