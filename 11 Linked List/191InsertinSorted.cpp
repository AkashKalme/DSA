#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
}*head = NULL;

void Create(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "Created Linked List!" << endl;
}

void Insert(Node *p, int x)
{
    Node *t, *q=NULL;
    t = new Node;
    t->data = x;
    t->next = NULL;
    if(head==NULL)
        head = t;
    else
    {
        while (p && p->data<x)
        {
            q = p;
            p = p->next;
        }
        if(p==head)
        {
            t->next = head;
            head = t;
        }
        else
        {
            t = new Node;
            t->data = x;
            t->next = q->next;
            q->next = t;
        }
    }
}

void Display(Node *p)
{
    if(p!=NULL)
    {
        cout << p->data << "  ";
        Display(p->next);
    }
}

int main()
{
    int A[] = {10,20,30,40,50};
    Create(A, 5);
    Insert(head, 25);
    Insert(head, 60);
    Insert(head, 5);
    Display(head);
    return 0;
}