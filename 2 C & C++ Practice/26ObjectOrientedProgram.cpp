// Object Oriented Program
#include <iostream>

using namespace std;

class Rectangle
{
private:
    int length;
    int breadth;

public:
    void initialize(int l, int b)
    {
        length = l;
        breadth = b;
    }

    int perimeter ()
    {
        int peri;
        peri = 2*(length + breadth);
        return peri;
    }

    int area ()
    {
        return length*breadth;
    }
};

int main()
{
    Rectangle r;

    int l, b;
    cout << "Enter Length and Breadth: ";
    cin >> l >> b;

    r.initialize(l, b);
    cout << "Area: " << r.area() << endl;
    cout << "Perimeter: " << r.perimeter() << endl;

    return 0;
}