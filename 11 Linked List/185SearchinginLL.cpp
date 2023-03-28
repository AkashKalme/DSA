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

Node* I_LSearch(Node *p, int key)
{
    while (p != NULL)
    {
        if(key == p->data)
            return p;
        p = p->next;
    }
    return NULL;
}

Node* R_LSearch(Node *p, int key)
{
    if(p == NULL)
        return NULL;
    if(key == p->data)
        return p;
    R_LSearch(p->next, key);
}

Node* Im_LSearch(Node* p, int key)
{
    Node *q = NULL;
    while (p != NULL)
    {
        if(key == p->data)
        {
            q->next = p->next;
            p->next = head;
            head = p;
            return p;
        }
        q = p;
        p = p->next;
    }
}

int main()
{
    Node *temp1, *temp2, *temp3;
    int A[] = {32, 55, 76, 91, 65, 45, 71, 15};
    Create(A,8);

    Display(head);
    cout << endl << endl;

    temp1 = I_LSearch(head, 45);
    if (temp1)
        cout << "Key " << temp1->data << " is Found!" << endl;
    else
        cout << "Key is NOT Found!" << endl;
    cout << endl;

    temp2 = R_LSearch(head, 7);
    if (temp2)
        cout << "Key " << temp2->data << " is Found!" << endl;
    else
        cout << "Key is NOT Found!" << endl;
    cout << endl;

    temp3 = Im_LSearch(head, 71);
    if (temp3)
        cout << "Key " << temp3->data << " is Found!" << endl;
    else
        cout << "Key is NOT Found!" << endl;
    cout << endl;
    Display(head);
    cout << endl << endl;

    return 0;
}