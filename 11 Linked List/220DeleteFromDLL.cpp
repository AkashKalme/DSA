#include<iostream>

using namespace std;

class Node
{
public:
    Node *prev;
    int data;
    Node *next;
};

class DoublyLinkedList
{
private:
    Node *head;
public:
    DoublyLinkedList()
    {
        head->prev = NULL;
        head->next = NULL;
    }
    DoublyLinkedList(int A[], int n);
    void Display();
    int Length();
    ~DoublyLinkedList();
    void Insert(int index, int x);
    int Delete(int index);
};

DoublyLinkedList::DoublyLinkedList(int A[], int n)
{
    Node *t, *tail;
    head = new Node;
    head->prev = NULL;
    head->data = A[0];
    head->next = NULL;
    tail = head;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->prev = tail;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

DoublyLinkedList::~DoublyLinkedList()
{
    Node *p = head;
    while(p)
    {
        head = head->next;
        delete p;
        p = head;
    }
}

void DoublyLinkedList::Display()
{
    Node *p = head;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}

int DoublyLinkedList::Length()
{
    int len = 0;
    Node *p = head;
    while(p)
    {
        len++;
        p = p->next;
    }
    return len;
}

void DoublyLinkedList::Insert(int index, int x)
{
    Node *t;
    if(index<0 || index>Length())
        return;
    if(index == 0)
    {
        t = new Node;
        t->data = x;
        t->prev = NULL;
        t->next = head;
        head->prev = t;
        head = t;
    }
    else
    {
        Node *p = head;
        for(int i=0; i<index-1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        if(p->next)
            p->next->prev = t;
        p->next = t;
    }
}

int DoublyLinkedList::Delete(int index)
{
    Node *p = head;
    int x = -1;
    if(index<0 || index>Length())
        return -1;
    
    if(index==1)
    {
        head = head->next;
        if(head)
            head->prev = NULL;
        x = head->data;
        delete p;
    }
    else
    {
        for(int i=0; i<index-1; i++)
            p = p->next;
        p->prev->next = p->next;
        if(p->next)
            p->next->prev = p->prev;
        x = p->data;
        delete p;
    }
    return x;
}

int main()
{
    int A[5] = {2,4,6,8,10};

    DoublyLinkedList dll(A, 5);
    dll.Display();
    cout << endl;
    cout << "Length of DLL: " << dll.Length() << endl;
    dll.Insert(5, 12);
    cout << endl;
    dll.Display();
    cout << endl;
    dll.Delete(6);
    cout << endl;
    dll.Display();
    cout << endl;

    return 0;
}