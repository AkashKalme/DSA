#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main ()
{
    struct Rectangle r = {10,5};
    cout << r.length << endl << r.breadth << endl;
    struct Rectangle *p = &r;
    cout << p -> length << endl << p -> breadth << endl;

    Rectangle *q;
    p = (struct Rectangle *) malloc(sizeof(struct Rectangle));
    q -> length = 20;
    q -> breadth = 30;
    cout << q -> length << endl << q -> breadth << endl;

    return 0;
}