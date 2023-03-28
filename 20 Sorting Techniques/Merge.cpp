#include <iostream>

using namespace std;

void Merge2(int A[], int B[], int m, int n)
{
    int i,j,k;
    i = j = k = 0;
    int C[m+n];
    while(i<m && j<n)
    {
        if(A[i]<=B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
    for(; i<m; i++)
        C[k++] = A[i];
    for(; j<n; j++)
        C[k++] = B[j];

    for(int i=0; i<m+n; i++)
    {
        cout << C[i] << " ";
    }
    cout << endl;
}

void Merge1(int A[], int l, int mid, int h)
{
    int B[h+1];
    int i,j,k;
    i=l;
    j=mid+1;
    k=l;
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for(; i<=mid; i++)
        B[k++] = A[i];
    for(; j<=h; j++)
        B[k++] = A[j];
    for(int i=l; i<=h; i++)
        A[i] = B[i];
    for(int i=l; i<=h; i++)
        cout << A[i] << " ";
}

int main()
{
    int A[5] = {2,4,6,8,10};
    int B[5] = {1,3,4,5,7};
    Merge2(A, B, 5, 5);
    cout << endl;
    int C[10] = {2,4,6,8,10,1,3,5,7,9};
    Merge1(C, 0, 4, 9);
    return 0;
}