#include<iostream>

using namespace std;

class Diagonal
{
private:
    int *A;
    int n;
public:
    Diagonal()
    {
        n = 2;
        A = new int [2]; 
    }
    Diagonal(int n)
    {
        this-> n = n;
        A = new int [n];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Diagonal() 
    {
        delete [] A;
    }
};

void Diagonal :: Set (int i, int j, int x)
{
    if (i == j)
        A[i-1] = x;
}

int Diagonal :: Get (int i, int j)
{
    if (i == j)
        return A[i-1];
    else
        return 0;
}

void Diagonal :: Display()
{
    int i, j;
    for (i=0; i<n; i++)
    {
        for (j=0; j<n; j++)
        {
            if (i == j)
                cout << A[i] << "  ";
            else
                cout << "0 " << " ";
        }
        cout << endl;
    }
}

int main()
{
    Diagonal D(4);

    D.Set(1,1,3);
    D.Set(2,2,6);
    D.Set(3,3,9);
    D.Set(4,4,8);

    D.Display();

    cout << D.Get(2,2);

    return 0;
}