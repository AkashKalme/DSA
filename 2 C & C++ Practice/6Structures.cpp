#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    struct Rectangle r1 ={10,5};

    cout << sizeof(r1) << endl;

    cout << r1.length << endl;
    cout << r1.breadth << endl;

    r1.length = 45;
    r1.breadth = 20;

    cout << r1.length << endl;
    cout << r1.breadth << endl;

    return 0;    
}