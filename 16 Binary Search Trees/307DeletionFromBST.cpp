#include<bits/stdc++.h>

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
    Node* rInsert(Node *p, int key);
    void Inorder(Node *p);
    Node* Search(int key);
    Node* inSucc(Node *p);
    Node* inPred(Node *p);
    int Height(Node *p);
    Node* Delete(Node* p, int key);
};

void BST::Insert(int key)
{

    Node* t = root;
    Node* p;
    Node* r;
    if (root == nullptr){
        p = new Node;
        p->data = key;
        p->lchild = nullptr;
        p->rchild = nullptr;
        root = p;
        return;
    }
    while(t != nullptr){
        r = t;
        if (key < t->data){
            t = t->lchild;
        } else if (key > t->data){
            t = t->rchild;
        } else {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = nullptr;
    p->rchild = nullptr;
    if (key < r->data){
        r->lchild = p;
    } else {
        r->rchild = p;
    }
}

Node* BST::rInsert(Node *p, int key)
{
    Node *t;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if(key < p->data)
    {
        p->lchild = rInsert(p->lchild, key);
    }
    else if(key > p->data)
    {
        p->rchild = rInsert(p->rchild, key);
    }
    return p;
}

void BST::Inorder(Node *p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << "    ";
        Inorder(p->rchild);
    }
}

Node* BST::Search(int key)
{
    Node *t = root;
    while (t)
    {
        if(key == t->data)
            return t;
        else if(key > t->data) 
            t = t->rchild;
        else
            t = t->lchild;
    }
    return NULL;
}

Node* BST::inPred(Node* p)
{
    while(p && p->rchild)
        p = p->rchild;
    return p;
}

Node* BST::inSucc(Node* p)
{
    while(p && p->lchild)
        p = p->lchild;
    return p;
}

int BST::Height(Node* p)
{
    int x, y;
    if(p==NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x>y?x+1:y+1;
}

Node* BST::Delete(Node *p, int key)
{
    Node *q;
    if(p==NULL)
    {
        return NULL;
    }
    if(p->lchild==NULL && p->rchild==NULL)
    {
        if(p==root)
        {
            root = NULL;
        }
        delete p;
        return NULL;
    }

    if(key < p->data)
        p->lchild = Delete(p->lchild, key);
    else if(key > p->data)
        p->rchild = Delete(p->rchild, key);
    else
    {
        if(Height(p->lchild) > Height(p->rchild))
        {
            q = inPred(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = inSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

int main()
{
    BST bst;
    bst.Insert(45);
    bst.Insert(25);
    bst.Insert(75);
    bst.rInsert(bst.getRoot(), 15);
    bst.Inorder(bst.getRoot());
    
    Node* temp = bst.Search(15);
    if (temp != nullptr){
        cout << "\n" << temp->data << endl;
    } else {
        cout << "\n" << "Element not found" << endl;
    }

    bst.Delete(bst.getRoot(), 45);
    bst.Inorder(bst.getRoot());
    return 0;
}