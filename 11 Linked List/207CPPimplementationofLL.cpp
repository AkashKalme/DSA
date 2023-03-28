#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class LinkedList
{
private:
    Node *head;
public:
    LinkedList()
    {
        head = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();

    void Display();
    void Insert(int index, int val);
    int Delete(int index);
    int Length();
};

LinkedList::LinkedList(int A[], int n)
{
    Node *last = NULL, *t;
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
}

LinkedList::~LinkedList()
{
    Node *p = head;
    while(p)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void LinkedList::Display()
{
    Node *p = head;
    while (p)
    {
        cout << p->data << "    ";
        p = p->next;
    }
    cout << endl;
}

void LinkedList::Insert(int index, int val)
{
    Node *t, *p = head;
    if(index<0 || index>Length())
        return;

    t = new Node;
    t->data = val;
    t->next = NULL;

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

int LinkedList::Length()
{
    int count = 0;
    Node *p = head;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}

int LinkedList::Delete(int index)
{
    Node *p, *q = NULL;
    int x = -1;
    if(index<1 || index>Length())
        return -1;
    if(index==1)
    {
        p = head;
        head = head->next;
        x = p->data;
        delete p;
    }
    else
    {
        p = head;
        for(int i=0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[5] = {2,5,6,7,8};
    LinkedList ll(A, 5);

    ll.Display();

    ll.Insert(3, 4);

    ll.Display();

    ll.Delete(2);

    ll.Display();
    return 0;
}