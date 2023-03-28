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

bool checkIfSorted(Node *p)
{
    int x = -32768;
    while(p!=NULL)
    {
        if(p->data < x)
        {
            return false;
        }
        x = p->data;
        p = p->next;
    }
    return true;
}

int main()
{
    Node *temp1, *temp2, *temp3;
    int A[] = {32, 55, 76, 91, 99};
    Create(A,5);

    Display(head);
    cout << endl << endl;

    cout << checkIfSorted(head);
    cout << endl << endl;
    return 0;
}