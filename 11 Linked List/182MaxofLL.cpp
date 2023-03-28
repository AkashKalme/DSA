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
    cout << "Linked List Created!" << endl;
}

void Display(Node *p)
{
    if(p != NULL)
    {
        cout << p->data << "        ";
        Display(p->next);
    }
}

int I_MAX(Node *p)
{
    int M = INT32_MIN;
    while(p)
    {
        if(p->data > M)
            M = p->data;
        p = p->next;
    }
    return M;
}

int R_MAX(Node *p)
{
    int Mx = 0;
    if (p == NULL)
        return INT32_MIN;
    Mx = R_MAX(p->next);
    return Mx > p->data ? Mx : p->data;
}

int main()
{
    int A[] = {32, 55, 76, 91, 65};
    Create(A,5);

    Display(head);

    cout << endl << endl;

    cout << "Maximum Iteratively: " << I_MAX(head);

    cout << endl << endl;

    cout << "Maximum Recursively: " << R_MAX(head);

    cout << endl << endl;
    return 0;
}