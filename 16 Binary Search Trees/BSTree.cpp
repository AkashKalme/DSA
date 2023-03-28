#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node *lchild, *rchild;

public:
    Node *root;
    friend class BST;
    Node()
    {
        data = -1;
        lchild = rchild = NULL;
        root = NULL;
    }
    Node(int data)
    {
        this->data = data;
        lchild = rchild = NULL;
        root = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST()
    {
        root = NULL;
    }
    Node *getRoot()
    {
        return root;
    }
    void Insert(int key);
    void Inorder(Node *p);
    Node *Search(int key);
};

void BST::Insert(int key)
{

    Node *t = root;
    Node *p;
    Node *r;
    if (root == nullptr)
    {
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
    while (t != nullptr)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

void BST::Inorder(Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << "    ";
        Inorder(p->rchild);
    }
}

Node *BST::Search(int key)
{
    Node *t = root;
    while (t)
    {
        if (key == t->data)
            return t;
        else if (key > t->data)
            t = t->rchild;
        else
            t = t->lchild;
    }
    return NULL;
}

int main()
{
    BST bst;
    int B[100] = {5, 12, 15, 24, 25, 38, 93, 81, 69, 39, 22, 92, 65, 59, 41, 70, 23, 96, 98, 80, 52, 85, 37, 74, 28, 63, 31, 35, 48, 33, 56, 21, 40, 77, 95, 67, 57, 58, 66, 87, 16, 14, 36, 7, 4, 68, 11, 84, 47, 43, 20, 82, 76, 1, 24, 75, 73, 30, 91, 42, 51, 10, 8, 3, 60, 29, 49, 18, 19, 9, 88, 55, 54, 78, 72, 64, 61, 13, 34, 71, 44, 46, 83, 27, 50, 17, 26, 2, 6, 45, 53, 99, 32, 62, 97, 90, 86, 89, 94, 100};

    bst.Inorder(bst.getRoot());

    Node *temp = bst.Search(15);
    if (temp != nullptr)
    {
        cout << "\n"
            << temp->data << endl;
    }
    else
    {
        cout << "\n"
            << "Element not found" << endl;
    }
    return 0;
}