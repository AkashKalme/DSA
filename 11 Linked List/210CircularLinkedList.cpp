#include<bits/stdc++.h>

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
    Node *getHead()
    {
        return head;
    }
    ~CircularLinkedList();
};

CircularLinkedList :: CircularLinkedList(int *A, int n)
{
    Node *t;
    Node *tail;

    head = new Node;

    head->data = A[0];
    head->next = head;
    tail = head;

    for(int i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = tail->next;
        tail->next = t;
        tail = t;
    }
}

void CircularLinkedList :: Display()
{
    Node *p = head;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while(p != head);
}

void CircularLinkedList :: RDisplay(Node *p)
{
    static int flag = 0;
    if(p!=head || flag==0)
    {
        flag = 1;
        cout << p->data << " ";
        RDisplay(p->next);
    }
    flag = 0;
}

CircularLinkedList::~CircularLinkedList() 
{
    Node* p = head;
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

int main()
{
    int A[5] = {2, 4, 6, 8, 10};

    CircularLinkedList cll(A, 5);

    Node *h = cll.getHead();
    cll.Display();
    cout << endl;
    cll.RDisplay(h);

    return 0;
}