#include<iostream>

using namespace std;

int main()
{
    int A[5] = {2,4,6,8,10};
    int *p;
    int i;
    
    p = new int[5];
    p[0] = 1;
    p[1] = 3;
    p[2] = 5;
    p[3] = 7;
    p[4] = 9;

    for (i = 0; i < 5; i++)
        cout << A[i] << " ";
    
    cout << endl;

    for (i = 0; i < 5; i++)
        cout << p[i] << " ";
    return 0;
}
