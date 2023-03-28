#include<iostream>

using namespace std;

class Matrix
{
public:
    int A[10];
    int n;
    void Set(int i, int j, int x);
    int Get(int i, int j);
};

void Set(Matrix *M, int i, int j, int x)
{
    if (i == j)
        M->A[i-1] = x;
}

int Get(Matrix M, int i, int j)
{
    if (i == j)
        return M.A[i-1];
    else
        return 0;
}

void Display(Matrix M)
{
    int i, j;
    for (i=0; i<M.n; i++)
    {
        for (j=0; j<M.n; j++)
        {
            if (i == j)
                cout << M.A[i] << "  ";
            else
                cout << "0" << "  ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix M;
    M.n = 4;

    Set(&M,1,1,5);
    Set(&M,2,2,4);
    Set(&M,3,3,3);
    Set(&M,4,4,2);

    Display(M);

    cout << Get(M,2,2);

    return 0;
}