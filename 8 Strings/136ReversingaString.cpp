#include<iostream>

using namespace std;

int main()
{
    char A[] = "Python";
    char B[7];
    int i, j;
    for (i = 0; A[i] != 0; i++){}
    i = i - 1;
    for (j = 0; i >= 0; i--,j++)
    {
        B[j] = A[i];
    }
    B[j] = '\0';
    cout << B << endl;

    char C[] = "python";
    char t;
    int i2, j2;
    for (j2 = 0; C[j2] != '\0'; j2++){}
    j2 = j2 - 1;
    for (i2 = 0; i2 < j2; i2++,j2--)
    {
        t = C[i];
        C[i] = C[j];
        C[j] = t;
    }
    cout << C << endl;

    return 0;
}