#include<iostream>

using namespace std;

class Lower_Triangular
{
private:
    int *A;
    int n;
public:
    Lower_Triangular()
    {
        n = 2;
        A = new int [2*(2+1)/2]; 
    }
    Lower_Triangular(int n)
    {
        this-> n = n;
        A = new int [n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Lower_Triangular() 
    {
        delete [] A;
    }
};

void Lower_Triangular :: Set (int i, int j, int x)
{
    if (i >= j)
        A[i*(i-1)/2+j-1] = x;
}

int Lower_Triangular :: Get (int i, int j)
{
    if (i >= j)
        return A[i*(i-1)/2+j-1];
    else
        return 0;
}

void Lower_Triangular :: Display()
{
    int i, j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (i >= j)
                cout << A[i*(i-1)/2+j-1] << "  ";
            else
                cout << "0 " << " ";
        }
        cout << endl;
    }
}

int main()
{
    int d;
    cout << "Enter Dimensions: ";
    cin >> d;

    Lower_Triangular LM(d);

    int x;
    cout << "Enter All Elements: " << endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin >> x;
            LM.Set(i,j,x);
        }
    }

    LM.Display();

    return 0;
}