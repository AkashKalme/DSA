// Incomplete
#include<iostream>

using namespace std;

class Symmetric
{
private:
    int *A;
    int n;
public:
    Symmetric()
    {
        n = 2;
        A = new int [2*(2+1)/2]; 
    }
    Symmetric(int n)
    {
        this-> n = n;
        A = new int [n*(n+1)/2];
    }
    void Create();
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Symmetric() 
    {
        delete [] A;
    }
};

void Symmetric :: Create()
{
    int x;
    cout << "Enter All Elements: " << endl;
    for(int i=1; i<=n; i++)
    {
        for(int j=1; j<=n; j++)
        {
            cin >> x;
            A[i*(i-1)/2+j-1] = x;
        }
    }
}

void Symmetric :: Set (int i, int j, int x)
{
    if (i >= j)
        A[i*(i-1)/2+j-1] = x;
}

int Symmetric :: Get (int i, int j)
{
    if (i >= j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}

void Symmetric :: Display()
{
    int i, j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
                cout << A[i*(i-1)/2+j-1] << "  ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    Symmetric SM(d);

    SM.Create();

    SM.Display();

    return 0;
}