#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void Insert(int A[], int n)
{
    int temp, i = n;
    temp = A[n];
    while(i>1 && temp>A[i/2])
    {
        A[i] = A[i/2];
        i = i/2;
    }
    A[i] = temp;
}

void Delete(int A[], int n)
{
    int val, x, i, j;
    val = A[1];
    x = A[n];
    A[1] = A[n];
    A[n] = val;
    i = 1;
    j = 2*i;
    while(j < n-1)
    {
        if(A[j+1] > A[j])
            j = j+1;
        if(A[i]<A[j])
        {
            swap(A[i], A[j]);
            i = j;
            j = 2*j;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    int H[8] = {0,21,32,61,94,34,11,21};
    for(int i=2; i<8; i++)
    {
        Insert(H, i);
    }
    for(int i=1; i<8; i++)
    {
        cout << H[i] << " ";
    }
    cout << endl;
    for(int i=7; i>1; i--)
    {
        Delete(H, i);
    }
    for(int i=1; i<8; i++)
    {
        cout << H[i] << " ";
    }
    cout << endl;

    return 0;
}