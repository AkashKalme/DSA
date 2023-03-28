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
    void push(int val);
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

bool isOperand(char x)
{
    if(x=='+' || x=='-' || x=='*' || x=='/')
        return 0;
    else
        return 1;
}

int precedence(char x)
{
    if(x=='+' || x=='-')
        return 1;
    else if(x=='*' || x=='/')
        return 2;
    return 0;
}

string InfixtoPostfix(string infix)
{
    Stack st;
    string postfix = "";
    int i=0;
    while(infix[i]!='\0')
    {
        if(isOperand(infix[i]))
        {
            postfix += infix[i++];
        }
        else
        {
            if(precedence(infix[i])>precedence(st.stackTop()))
                st.push(infix[i++]);
            else
                postfix += st.pop();
        }
    }
    while(!st.isEmpty())
        postfix += st.pop();
    return postfix;
}

int main()
{
    string exp = "a+b-c*d/e";
    string res = InfixtoPostfix(exp);
    cout << res << endl;
    return 0;
}