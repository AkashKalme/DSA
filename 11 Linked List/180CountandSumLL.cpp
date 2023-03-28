#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
}*head = NULL;

void Create(int A[], int n)
{
    int i;
    Node *t, *last;
    head = new Node;
    head->data = A[0];
    head->next = NULL;
    last = head;

    for (i=1; i<n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    cout << "Created Linked List!" << endl;
}

void R_Display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << "    ";
        R_Display(p->next);
    }
}

int I_Count(Node *p)
{
    int c = 0;
    while (p == NULL)
    {
        c++;
        p = p->next;
    }
    return c;
}

int R_Count(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return R_Count(p->next)+1;
}

int I_Add(Node *p)
{
    int sum = 0;
    while (p)
    {
        sum += p->data;
        p = p->next;
    }
    return sum;
}

int R_Add(Node *p)
{
    if (p == NULL)
        return 0;
    else
        return R_Add(p->next)+p->data;
}

int main()
{
    Node *temp;
    int A[] = {2,4,6,8,10};
    Create(A,5);
    cout << endl;
    R_Display(head);
    cout << endl << endl;
    cout << I_Count(head) << "      " << R_Count(head);
    cout << endl << endl;
    cout << I_Add(head) << "        " << R_Add(head);
    return 0;
}