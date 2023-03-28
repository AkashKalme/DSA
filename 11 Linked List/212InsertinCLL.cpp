#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class CircularLinkedList
{
private:
    Node *head;

public:
    CircularLinkedList()
    {
        head = NULL;
    }
    CircularLinkedList(int A[], int n);
    void Display();
    void RDisplay(Node *p);
    int Length();
    void Insert(int index, int x);
    Node *getHead()
    {
        return head;
    }
    ~CircularLinkedList();
};

CircularLinkedList ::CircularLinkedList(int *A, int n)
{
    Node *t;
    Node *tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList ::Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}

void CircularLinkedList ::RDisplay(Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        flag = 1;
        cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

CircularLinkedList::~CircularLinkedList()
{
    Node *p = head;
    while (p->next != head)
    {
        p = p->next;
    }
    while (p != head)
    {
        p->next = head->next;
        delete head;
        head = p->next;
    }
    if (p == head)
    {
        delete head;
        head = nullptr;
    }
}

void CircularLinkedList::Insert(int index, int x)
{
    Node *t, *p;
    p = head;
    if (index < 0 || index > Length())
    {
        cout << "Invalid Input" << endl;
        return;
    }
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        if (p == NULL)
        {
            t = head;
            t->next = head;
        }
        else
        {
            while (p->next != head)
            {
                p = p->next;
            }
            p->next = t;
            t->next = head;
            head = t;
        }
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

int CircularLinkedList::Length()
{
    int len = 1;
    Node *p = head;
    do
    {
        len++;
        p = p->next;
    } while (p->next != head);
    return len;
}

int main()
{
    int A[5] = {2, 4, 6, 8, 10};

    CircularLinkedList cll(A, 5);

    Node *h = cll.getHead();
    cll.Display();
    cout << endl;
    cll.RDisplay(h);
    cout << endl;
    cout << cll.Length() << endl;
    cout << endl;
    cll.Insert(0, 12);
    cll.Display();
    cout << endl;
    cout << cll.Length() << endl;
    cout << endl;

    return 0;
}