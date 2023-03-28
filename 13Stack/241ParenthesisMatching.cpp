#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    char data;
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
    void push(char val);
    char pop();
    char peek(int index);
    char stackTop();
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

void Stack::push(char val)
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

char Stack::pop()
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

char Stack::peek(int index)
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

char Stack::stackTop()
{
    if(top)
        return top->data;
    return -1;
}

bool isBalanced(char *e)
{
    Stack st;
    for(int i=0; i<strlen(e); i++)
    {
        if(e[i]=='(')
            st.push(e[i]);
        else if(e[i]==')')
        {
            if(st.isEmpty())
                return false;
            else
                st.pop();
        }
    }
    return st.isEmpty();
}

int main()
{
    char exp[] = "((a+b)*c+(e*f))";

    cout << isBalanced(exp) << endl;
    return 0;
}