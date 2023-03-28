#include <iostream>

using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int B[100];
    int i,j,k;
    i = l;
    j = mid+1;
    k = l;
    while(i<=mid && j<=h)
    {
        if(A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while(i<=mid)
        B[k++] = A[i++];
    while (j<=h)
    {
        B[k++] = A[j++];
    }
    for(int i=l; i<=h; i++)
        A[i] = B[i];
}

void rMergeSort(int A[], int l, int h)
{
    if(l<h)
    {
        int mid = (l+h)/2;
        rMergeSort(A, l, mid);
        rMergeSort(A, mid+1, h);
        Merge(A, l, mid, h);
    }
}

int main()
{
    int A[10] = {45,76,23,34,12,76,98,67,12,9};
    rMergeSort(A, 0, 9);
    for(int i=0; i<10; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}