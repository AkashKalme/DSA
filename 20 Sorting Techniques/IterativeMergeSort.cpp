#include <iostream>

using namespace std;

void Merge(int A[], int l, int mid, int h)
{
    int i,j,k;
    int B[100];
    i = l;
    k = l;
    j = mid+1;
    while(i<=mid && j<=h)
    {
        if(A[i]<A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    while(i<=mid)
        B[k++] = A[i++];
    while(j<=h)
        B[k++] = A[j++];

    for(int i=l; i<=h; i++)
        A[i] = B[i];
}
void iMergeSort(int A[], int n)
{
    int p,i,l,mid,h;
    for(p=2; p<=n; p=p*2)
    {
        for(i=0; i+p-1<n; i=i+p)
        {
            l = i;
            h = i+p-1;
            mid = (l+h)/2;
            Merge(A, l, mid, h);
        }
        if(p/2<n)
            Merge(A, 0, p/2-1, n);
    }
}

int main()
{
    int A[10] = {61,48,24,9,1,87,34,67,99,78};
    iMergeSort(A, 10);
    cout << "Merge Sort: ";
    for(int i=0; i<10; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}