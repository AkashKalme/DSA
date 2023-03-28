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

int main()
{
    int A[5] = {2,4,6,8,10};

    DoublyLinkedList dll(A, 5);
    dll.Display();
    cout << endl;
    cout << "Length of DLL: " << dll.Length() << endl;
    return 0;
}