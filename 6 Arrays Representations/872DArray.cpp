#include <iostream>

using namespace std;

int main()
{
    int i, j;
    int A[3][4] = {{1,2,3,4},{2,4,6,8},{3,5,7,9}};
    
    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];

    int **C;
    C = new int*[3];
    C[0] = new int[4];
    C[1] = new int[4];
    C[2] = new int[4];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            B[i][j] = i+j;
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            C[i][j] = i*j;
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << endl;

    return 0;
}