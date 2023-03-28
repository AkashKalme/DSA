// Modular Program
#include <iostream>

using namespace std;

int perimeter (int length, int breadth)
{
    int peri;
    peri = 2*(length + breadth);
    return peri;
}

int area (int length, int breadth)
{
    return length*breadth;
}

int main()
{
    int length = 0, breadth = 0;
    cout << "Enter Length and Breadth: ";
    cin >> length >> breadth;

    cout << "Area: " << area(length, breadth) << endl;
    cout << "Perimeter: " << perimeter(length, breadth) << endl;

    return 0;
}