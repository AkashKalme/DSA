#include<iostream>
using namespace std;

template <class T>

class Arithmetic
{
private:
    T a;
    T b;
public:
    Arithmetic(T a, T b);
    T add();
    T subtract();
};

template <class T>
Arithmetic<T>::Arithmetic(T a, T b)
{
    this -> a = a;
    this -> b = b;
}

template <class T>
T Arithmetic <T> :: add()
{
    T c;
    c = a+b;
    return c;
}

template <class T>
T Arithmetic <T> :: subtract()
{
    T c;
    c = a-b;
    return c;
}

int main()
{
    Arithmetic <int> ar(10, 5);
    cout << "Addition: " << ar.add() << endl;
    cout << "Subtraction: " << ar.subtract() << endl;

    Arithmetic <float> ar1(2.67, 3.58);
    cout << "Addition: " << ar1.add() << endl;
    cout << "Subtraction: " << ar1.subtract() << endl;

    return 0;
}