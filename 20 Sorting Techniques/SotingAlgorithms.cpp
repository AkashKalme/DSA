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

void bubbleSort(int A[], int n)
{
    bool flag = 0;
    for(int i=0; i<n-1; i++)
    {
        flag = 0;
        for(int j=0; j<n-1-i; j++)
        {
            if(A[j] > A[j+1])
            {
                swap(&A[j], &A[j+1]);
                flag = 1;
            }
        }
        if(!flag)
            break;
    }
}

void insertionSort(int A[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j = i-1;
        int x = A[i];
        while(j>-1 && A[j]>x)
        {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = x;
    }
}

void selectionSort(int A[], int n)
{
    int i, j, k;
    for(int i=0; i<n-1; i++)
    {
        for(j=k=i; j<n; j++)
        {
            if(A[j]<A[k])
                k = j;
        }
        swap(&A[i], &A[k]);
    }
}

int main()
{
    int A[10] = {10, 78, 412, 185, 25, 85, 92, 25, 45, 12};

    // bubbleSort(A, 10);
    // print(A, 10, "Bubble Sort");
    // cout << endl;

    // insertionSort(A, 10);
    // print(A, 10, "Insertion Sort");
    // cout << endl;

    selectionSort(A, 10);
    print(A, 10, "Selection Sort");
    cout << endl;
    return 0;
}