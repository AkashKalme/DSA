#include<iostream>

using namespace std;

int main()
{
    int A[5];
    int B[5] = {2,4,6,8,10};
    int C[5] = {1,3};
    int D[5] = {0};
    int E[ ] = {1,2,3,4,5,6,7,8};

    for (int i = 0; i < 5; i++)
        cout << &A[i] << endl;

    return 0;
}