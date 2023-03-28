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

int Delete(Node *p, int index)
{
    Node *q;
    int x = -1;
    if(index==1)
    {
        x = head->data;
        q = head;
        head = head->next;
        delete q;
        return x;
    }
    else
    {
        q = NULL;
        for(int i=0; i<index-1; i++)
        {
            q = p;
            p = p->next;
        }
        if(p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
        return x;
    }
}

int main()
{
    Node *temp1, *temp2, *temp3;
    int A[] = {32, 55, 76, 91, 65, 45, 71, 15};
    Create(A,8);

    Display(head);
    cout << endl << endl;

    Delete(head, 3);
    cout << endl;

    Display(head);
    return 0;
}