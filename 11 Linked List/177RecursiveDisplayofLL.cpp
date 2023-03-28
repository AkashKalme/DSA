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

void I_Display(Node *p)
{
    p = head;
    while (p != NULL)
    {
        cout << p->data << "    ";
        p = p->next;
    }
}

void R_Display(Node *p)
{
    if (p != NULL)
    {
        cout << p->data << "    ";
        R_Display(p->next);
    }
}

void R_Display_Rev(Node *p)
{
    if (p != NULL)
    {
        R_Display_Rev(p->next);
        cout << p->data << "    ";
    }

}

int main()
{
    Node *temp;
    int A[] = {2,4,6,8,10};
    Create(A,5);
    I_Display(head);
    cout << endl << endl;
    R_Display(head);
    cout << endl << endl;
    R_Display_Rev(head);
    return 0;
}