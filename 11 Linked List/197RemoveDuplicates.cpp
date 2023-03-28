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

void Display(Node *p)
{
    if(p != NULL)
    {
        cout << p->data << "    ";
        Display(p->next);
    }
}

void removeDuplicates(Node *p)
{
    Node *q = p->next;
    while(q != NULL)
    {
        if(p->data != q->data)
        {
            p = q;
            q = q->next;
        }
        else
        {
            p->next = q->next;
            delete q;
            q = p->next;
        }
    }
}

int main()
{
    Node *temp1, *temp2, *temp3;
    int A[] = {32, 32, 76, 91, 91};
    Create(A,5);

    Display(head);
    cout << endl << endl;

    removeDuplicates(head);
    cout << endl << endl;

    Display(head);
    cout << endl << endl;

    return 0;
}