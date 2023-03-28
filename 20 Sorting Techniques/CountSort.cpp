#include <iostream>

using namespace std;

int findMax(int A[], int n)
{
    int x = -1;
    for(int i=0; i<n; i++)
    {
        if(A[i]>x)
            x = A[i];
    }
    return x;
}

void countSort(int A[], int n)
{
    int x = findMax(A, n);
    int count[x+1] = {0};
    for(int i=0; i<n; i++)
    {
        count[A[i]]++;
    }
    int i = 0;
    int j = 0;
    while(i<x+1)
    {
        if(count[i]>0)
        {
            A[j++] = i;
            count[i]--;
        }
        else
            i++;
    }
}

int main()
{
    int A[10] = {9,5,8,3,6,5,10,14,16,3};
    countSort(A, 10);
    for(int i=0; i<10; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}