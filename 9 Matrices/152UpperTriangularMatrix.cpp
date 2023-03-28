#include<iostream>

using namespace std;

class Upper_Triangular
{
private:
    int *A;
    int n;
public:
    Upper_Triangular()
    {
        n = 2;
        A = new int [2*(2+1)/2]; 
    }
    Upper_Triangular(int n)
    {
        this-> n = n;
        A = new int [n*(n+1)/2];
    }
    void Set(int i, int j, int x);
    int Get(int i, int j);
    void Display();
    ~Upper_Triangular() 
    {
        delete [] A;
    }
};

void Upper_Triangular :: Set (int i, int j, int x)
{
    if (i <= j)
        A[(i-1)*n-(i-2)*(i-1)/2+(j-1)] = x;
}

int Upper_Triangular :: Get (int i, int j)
{
    if (i <= j)
        return A[(i-1)*n-(i-2)*(i-1)/2+(j-1)];
    else
        return 0;
}

void Upper_Triangular :: Display()
{
    int i, j;
    for (i=1; i<=n; i++)
    {
        for (j=1; j<=n; j++)
        {
            if (i <= j)
                cout << A[(i-1)*n-(i-2)*(i-1)/2+(j-1)] << "  ";
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

    Upper_Triangular UM(d);

    int x;
    cout << "Enter All Elements: " << endl;
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin >> x;
            UM.Set(i,j,x);
        }
    }

    UM.Display();

    return 0;
}