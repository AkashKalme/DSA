#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head = NULL;

void Create(int A[], int n)
{
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (int i = 1; i < n; i++)
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
    if (p != NULL)
    {
        cout << p->data << "    ";
        Display(p->next);
    }
}

bool isLoop(Node *f)
{
    Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q!=NULL ? q->next : NULL;
    } while (p && q && p!=q);
    return p == q;
}

int main()
{
    int A[] = {32, 55, 76, 81, 99};
    Create(A, 5);

    Node *temp1 = head->next->next;
    Node *temp2 = head->next->next->next->next;
    temp2->next = temp1;

    // Display(head);
    // cout << endl
    //      << endl;

    cout << isLoop(head);
    cout << endl
         << endl;
    return 0;
}