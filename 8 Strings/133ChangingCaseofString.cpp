#include<iostream>

using namespace std;

int main()
{
    char A[] = "WELCOME";
    int i;
    for (i = 0; A[i] != '\0'; i++)
    {
        A[i] = A[i] + 32;
    }
    cout << A << endl;

    cout << endl;

    char B[] = "welcome";
    int j;
    for (j = 0; B[j] != '\0'; j++)
    {
        B[j] = B[j] - 32;
    }
    cout << B << endl;

    cout << endl;

    char C[] = "wElCoMe";
    int k;
    for (k = 0; C[k] != '\0'; k++)
    {
        if (C[k] >= 65 && C[k] <= 90)
            C[k] += 32;
        else if (C[k] >= 97 && C[k] <= 122)
            C[k] -= 32;
    }
    cout << C << endl;

    return 0;
}