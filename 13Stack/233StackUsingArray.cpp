#include <iostream>

using namespace std;

class Stack
{
private:
    int size;
    int top;
    int *s;
public:
    Stack(int size);
    ~Stack();
    bool isFull();
    bool isEmpty();
    void push(int x);
    int pop();
    int peek(int index);
    int stackTop();
    void Display();
};

Stack::Stack(int size)
{
    this->size = size;
    top = -1;
    s = new int[size];
}

Stack::~Stack()
{
    delete s;
}

bool Stack::isFull()
{
    return top==size-1;
}

bool Stack::isEmpty()
{
    return top==-1;
}

void Stack::push(int x)
{
    if(isFull())
        cout << "Stack Overflow" << endl;
    else
    {
        top++;
        s[top] = x;
    }
}

int Stack::pop()
{
    int x = -1;
    if(isEmpty())
        cout << "Stack Underflow" << endl;
    else
    {
        x = s[top];
        top--;
    }
    return x;
}

int Stack::peek(int index)
{
    int x = -1;
    if(top-index+1<0 || top-index+1>=size)
        cout << "Invalid Index" << endl;
    else
    {
        x = s[top-index+1];
    }
    return x;
}

int Stack::stackTop()
{
    if(isEmpty())
        return -1;
    else
        return s[top];
}

void Stack::Display()
{
    if(isEmpty())
        cout << "Stack is Empty!" << endl;
    else
    {
        for(int i=top; i>=0; i--)
            cout << s[i] << " | " << flush;
        cout << endl;
    }
}

int main()
{
    Stack st(5);

    cout << "Stack Underflow: " << st.isEmpty() << endl;

    cout << "Stack Overflow: " << st.isFull() << endl;

    st.push(12);
    cout << "Stack: ";
    st.Display();
    st.push(4);
    st.push(45);
    st.push(25);
    cout << "Stack: ";
    st.Display();
    st.push(7);
    cout << "Stack: ";
    st.Display();
    st.push(5);
    st.pop();
    cout << "Stack: ";
    st.Display();
    cout << "Stack Top: " << st.stackTop() << endl;
    cout << "Peek 3: " << st.peek(3) <<endl; 

    cout << "Stack Underflow: " << st.isEmpty() << endl;

    cout << "Stack Overflow: " << st.isFull() << endl;
    return 0;
}