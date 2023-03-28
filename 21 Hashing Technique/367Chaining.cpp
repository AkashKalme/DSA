#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class HashTable
{
public:
    Node** HT;
    HashTable();
    int hashFunction(int key);
    void insert(int Key);
    int Search(int key);
    ~HashTable();
};

HashTable::HashTable()
{
    HT = new Node*[10];
    for(int i=0; i<10; i++)
    {
        HT[i] = NULL;
    }
}

int HashTable::hashFunction(int key)
{
    return key%10;
}

void HashTable::insert(int key)
{
    int htIdex = hashFunction(key);
    Node* t = new Node;
    t->data = key;
    t->next = NULL;
    if(HT[htIdex] == NULL)
        HT[htIdex] = t;
    else
    {
        Node* p = HT[htIdex];
        Node* q = HT[htIdex];
        while(p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if(q==HT[htIdex])
        {
            t->next = HT[htIdex];
            HT[htIdex] = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}

int HashTable::Search(int key)
{
    int hti = hashFunction(key);
    Node* p = HT[hti];
    while(p)
    {
        if(p->data==key)
            return p->data;
        p = p->next;
    }
    return -1;
}

HashTable::~HashTable()
{
    for(int i=0; i<10; i++)
    {
        Node* p = HT[i];
        while(HT[i])
        {
            HT[i] = HT[i]->next;
            delete p;
            p = HT[i];
        }
    }
    delete [] HT;
}

int main()
{
    int A[] = {16,12,34,25,67,35,67,89,34};
    int n = sizeof(A)/sizeof(A[0]);
    HashTable H;
    for(int i=0; i<n; i++)
    {
        H.insert(A[i]);
    }
    cout << H.Search(25) << endl;
    cout << H.Search(45) << endl;
    return 0;
}