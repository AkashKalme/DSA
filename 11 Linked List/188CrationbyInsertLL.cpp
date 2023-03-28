#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
}*head=NULL;

void Insert(int x)
{
    Node *t, *last;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(head==NULL)
    {
        head = last = t;
    }
    else
    {
        last->data = x;
        last->next = t;
        last = t;
    }
    cout << "Inserted " << x << "!" << endl;
}

void Display(Node *p)
{
    if(p!=NULL)
    {
        cout << p->data << "    ";
        Display(p->next);
    }
}

int main()
{
    Insert(10);
    Insert(20);
    Insert(30);
    Display(head);
    return 0;
}