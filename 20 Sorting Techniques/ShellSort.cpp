#include <iostream>

using namespace std;

void shellSort(int A[], int n)
{
    for(int gap=n/2; gap>=1; gap/=2)
    {
        for(int j=gap; j<n; j++)
        {
            int temp = A[j];
            int i = j-gap;
            while(i>=0 && A[i]>temp)
            {
                A[i+gap] = A[i];
                i = i-gap;
            }
            A[i+gap] = temp;
        }
    }
}

int main()
{
    int A[10] = {11, 13, 7, 12, 16, 9, 24, 5, 10, 3};
    shellSort(A, 10);
    for(int i=0; i<10; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}