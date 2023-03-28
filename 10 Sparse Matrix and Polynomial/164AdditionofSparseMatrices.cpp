// Incorrect Output
#include<iostream>

using namespace std;

class Element
{
public:
    int i;
    int j;
    int x;
};

class Sparse
{
    int m;
    int n;
    int num;
    Element *ele;
public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        ele = new Element [this -> num];
    }

    ~Sparse()
    {
        delete [] ele;
    }

    Sparse operator+(Sparse &S);
    friend istream & operator>> (istream &is, Sparse &s);
    friend ostream & operator<< (ostream &os, Sparse &s);
};

    Sparse Sparse :: operator+(Sparse &S)
    {
        int i, j, k;
        if (m!=S.m || n!=S.n)
            return Sparse(0,0,0);
        Sparse *Sum = new Sparse(m, n, num+S.num);
        i=j=k=0;
        while (i<num && j<S.num)
        {
            if(ele[i].i < S.ele[j].i)
                Sum->ele[k++] = ele[i++]; 
            else if(ele[i].i > S.ele[j].i)
                Sum->ele[k++] = ele[j++];
            else
            {
                if(ele[i].j < S.ele[j].j)
                    Sum->ele[k++] = ele[i++]; 
                else if(ele[i].j > S.ele[j].j)
                    Sum->ele[k++] = ele[j++];
                else
                {
                    Sum->ele[k] = ele[i];
                    Sum->ele[k++].x = ele[i++].x + S.ele[j++].x;
                }
            }
        }
        for(; i<num; i++)
        {
            Sum->ele[k++] = ele[i];
        }
        for(; j<S.num; j++)
        {
            Sum->ele[k++] = S.ele[j];
        }
        Sum->num = k;
        return *Sum;
    }

    istream & operator>> (istream &is, Sparse &s)    
    {
        cout << "Enter Non-Zero Elements: " << endl;
        for (int i=0; i<s.num; i++)
            cin >> s.ele[i].i >> s.ele[i].j >> s.ele[i].x;
        return is;
    }

    ostream & operator<< (ostream &os, Sparse &s)    
    {
        int k = 0;
        for (int i=0; i<s.m; i++)
        {
            for (int j=0; j<s.n; j++)
            {
                if(s.ele[k].i == i && s.ele[k].j == j)
                    cout << s.ele[k++].x << "  ";
                else
                    cout << "0" << "  ";
            }
            cout << endl;
        }
        return os;
    }

int main()
{
    Sparse S1(5,5,5);
    Sparse S2(5,5,5);

    cin >> S1;
    cin >> S2;

    Sparse S3 = S1 + S2;

    cout << "First Matrix: " << endl << S1;
    cout << "Second Matrix: " << endl << S2;
    cout << "SUM Matrix: " << endl << S3;


    return 0;
}