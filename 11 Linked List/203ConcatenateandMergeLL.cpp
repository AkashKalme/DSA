// Not Working
#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
} *head1 = NULL, *head2 = NULL, *concat, *m;

void Create1(int A[], int n)
{
    Node *t, *last;
    head1 = new Node;
    head1->data = A[0];
    head1->next = NULL;
    last = head1;

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

void Create2(int A[], int n)
{
    Node *t2, *last2;
    head2 = new Node;
    head2->data = A[0];
    head2->next = NULL;
    last2 = head2;

    for (int i = 1; i < n; i++)
    {
        t2 = new Node;
        t2->data = A[i];
        t2->next = NULL;
        last2->next = t2;
        last2 = t2;
    }
    cout << "Created Linked List!" << endl;
}

void Concatenate(Node *p, Node *q)
{
    concat = p;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}

Node *mergeTwoLists(Node *list1, Node *list2)
{
    Node *last = NULL;

    if (list1->data <= list2->data)
    {
        m = last = list1;
        list1 = list1->next;
        m->next = last->next = NULL;
    }
    else
    {
        m = last = list2;
        list2 = list2->next;
        m->next = last->next = NULL;
    }

    while (list1 && list2)
    {
        if (list1->data <= list2->data)
        {
            last->next = list1;
            list1 = list1->next;
            last = last->next;
            last->next = NULL;
        }
        else
        {
            last->next = list2;
            list2 = list2->next;
            last = last->next;
            last->next = NULL;
        }
    }

    if(list1)
        last = list1;
    if(list2)
        last = list2;
    return m;
}

void Display(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << "    ";
        p = p->next;
    }
}

int main()
{
    Node *temp1, *temp2, *temp3;
    int A[] = {32, 55, 76, 81, 99};
    Create1(A, 5);
    int B[] = {42, 57, 66, 72, 91};
    Create2(B, 5);

    cout << "First: ";
    Display(head1);
    cout << endl
         << endl;

    cout << "Second: ";
    Display(head2);
    cout << endl
         << endl;

    cout << "Conactenated List: ";
    Concatenate(head1, head2);
    Display(concat);
    cout << endl
         << endl;

    cout << "Merged List: ";
    Display(mergeTwoLists(head1, head2));
    cout << endl
         << endl;

    return 0;
}