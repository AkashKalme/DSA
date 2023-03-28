#include <iostream>

using namespace std;

int main()
{
    int Arr[5];
    Arr[0] = 15;
    Arr[3] = 25;

    for (int i = 0; i < 5; i++)
    {
        cout << Arr[i] << "  ";
    }
    cout << endl;
    int Arr2[] = {12,15,4,8,6,7,4,2};
    cout << sizeof(Arr2) << endl;

    return 0;
}