#include<iostream>

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

    for (int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "Created Linked List!" << endl;
}

int Count(Node *p)
{
    if(p==NULL)
        return 0;
    else
        return Count(p->next)+1;
}

void Display(Node *p)
{
    if(p!=NULL)
    {
        cout << p->data << "    ";
        Display(p->next);
    }
}

void Insert(Node *p, int index, int x)
{
    Node *t;
    if(index<0 || index>Count(p))
        return;
    t = new Node;
    t->data = x;
    if(index == 0)
    {
        t->next = head;
        head = t;
    }
    else
    {
        for(int i=0; i<index-1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}

int main()
{
    int A[] = {24,78,65};
    Create(A,3);
    cout << endl;
    Display(head);
    cout << endl;
    Insert(head,0,45);
    Insert(head, 1, 27);
    cout << endl;
    Display(head);
    return 0;
}