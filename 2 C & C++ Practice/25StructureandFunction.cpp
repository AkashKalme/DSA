// Structure and Function Program
#include <iostream>

using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

void initialize(struct Rectangle *r, int l, int b)
{
    r -> length = l;
    r -> breadth = b;
}

int perimeter (struct Rectangle r)
{
    int peri;
    peri = 2*(r.length + r.breadth);
    return peri;
}

int area (struct Rectangle r)
{
    return r.length*r.breadth;
}

int main()
{
    Rectangle r = {0, 0};

    int l, b;
    cout << "Enter Length and Breadth: ";
    cin >> l >> b;

    initialize(&r, l, b);
    cout << "Area: " << area(r) << endl;
    cout << "Perimeter: " << perimeter(r) << endl;

    return 0;
}