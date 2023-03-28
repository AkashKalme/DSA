#include<iostream>

using namespace std;

int main()
{
    char A[] = "abde";
    char B[] = "abcd";
    int i, j;
    for (i=0,j=0; A[i]!='\0',B[i]!='\0';i++,j++)
    {
        if (A[i] != B[j])
            break;
    }
    if (A[i] == B[j])
        cout << "Equal" << endl;
    else if (A[i] < B[j])
        cout << "Smaller" << endl;
    else
        cout << "Greater" << endl;

    char C[] = "madam";
    int k=0, l;
    for (l = 0; C[l] != 0; l++){}
    int res = 0;
    while (k <= l)
    {
        if (C[k] == C[l-1])
        {
            res = 1;
        }
        else
        {
            res = 0;
            break;
        }
        k++;
        l--;
    }
    if (res == 1)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}