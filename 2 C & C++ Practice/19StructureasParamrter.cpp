#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void func1 (struct Rectangle *p)
{
    cout << p->length << endl;
    cout << p->breadth << endl;
}

struct Rectangle *fun()
{
    struct Rectangle *q;
    q = new Rectangle;

    q -> length = 15;
    q -> breadth = 20;

    return q;
};

int main()
{
    struct Rectangle r1 = {10, 20};
    func1 (&r1);

    struct Rectangle *ptr = fun();
    cout << ptr->length << endl;
    cout << ptr->breadth << endl;

    return 0;
}