#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

class Stack
{
private:
    Node *top;
public:
    Stack();
    ~Stack();
    bool isEmpty();
    bool isFull();
    void push(int val);
    int pop();
    int peek(int index);
    int stackTop();
};

Stack::Stack()
{
    top = NULL;
}

Stack::~Stack()
{
    Node *p = top;
    while(top)
    {
        top = top->next;
        delete top;
        p = top;
    }
}

bool Stack::isFull()
{
    Node * t = new Node;
    bool r = t ? 0 : 1;
    delete t;
    return r;
}

bool Stack::isEmpty()
{
    return top ? 0 : 1;
}

void Stack::push(int val)
{
    if(isFull())
        cout << "Stack Overflow!" << endl;
    else
    {
        Node *t = new Node;
        t->data = val;
        t->next = top;
        top = t;
    }
}

int Stack::pop()
{
    Node *p;
    int x = -1;
    if(isEmpty())
        cout << "Stack Underflow!" << endl;
    else
    {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::peek(int index)
{
    if(isEmpty())
        return -1;
    else
    {
        Node *p = top;
        for(int i=0; p!=NULL && i<index-1; i++)
        {
            p = p->next;
        }
        if(p)
            return p->data;
        else
            return -1;
    }
}

int Stack::stackTop()
{
    if(top)
        return top->data;
    return -1;
}

int main()
{
    Stack st;

    cout << "Is stack Empty? " << st.isEmpty() << endl;
    cout << "Is stack Full? " << st.isFull() << endl;

    st.push(10);
    st.push(20);
    st.push(30);
    // cout << st.pop() << endl;
    cout << st.peek(3) << endl;
    cout << st.stackTop() << endl;
    return 0;
}