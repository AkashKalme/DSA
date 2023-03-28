#include<iostream>

using namespace std;

int main()
{
    int *p, *q;
    p = new int[5];
    p[0] = 3; p[1] = 5; p[2] = 2; p[3] = 8; p[4] = 7;
    for (int i = 0; i < 5; i++)
        cout << p[i] << " ";
    cout << endl;

    q = new int[10];
    q[5] = 4; q[6] = 9; q[7] = 3; q[8] = 1; q[9] = 11; 
    for (int i = 0; i < 5; i++)
        q[i] = p[i];
    
    delete [] p;
    p = q;
    q = NULL;

    for (int i = 0; i < 10; i++)
        cout << p[i] << " ";

    return 0;
}