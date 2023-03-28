#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
};

class Queue
{
private:
    int size;
    int front;
    int rear;
    Node **Q;
public:
    Queue(int size)
    {
        this->size = size;
        front = -1;
        rear = -1;
        Q = new Node*[size];
    }

    ~Queue()
    {
        delete []Q;
    }

    bool isEmpty()
    {
        if(front==rear)
            return true;
        return false;
    }

    bool isFull()
    {
        if(rear==size-1)
            return true;
        return false;
    }

    void Enqueue(Node *data)
    {
        if(isFull())
        {
            cout << "Queue is Full!"<< endl;
            return;
        }
        rear++;
        Q[rear] = data;
    }

    Node* Dequeue()
    {
        Node* x = NULL;
        if(isEmpty())
        {
            cout << "Queue is Full!" << endl;
            return x;
        }
        front++;
        x = Q[front];
        return x;
    }
};

class BinaryTree
{
public:
    Node* root;
    BinaryTree();
    ~BinaryTree();
    void Create();
    void PreOrder(Node *p);
    void InOrder(Node *p);
    void PostOrder(Node *p);
    void IPreOrder(Node *p);
    void IInOrder(Node *p);
    void IPostOrder(Node *p);
    void LevelOrder(Node *p);
    int Height(Node *p);
};

BinaryTree::BinaryTree()
{
    root = NULL;
}

BinaryTree::~BinaryTree()
{
    delete root;
}

void BinaryTree::Create()
{
    Node *p, *t;
    Queue Q(100);
    int x;
    cout << "Enter root data: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    Q.Enqueue(root);
    while(!Q.isEmpty())
    {
        p = Q.Dequeue();
        cout << "Enter data for left child of " << p->data << ": ";
        cin >> x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            Q.Enqueue(t);
        }
        cout << "Enter data for right child of " << p->data << ": ";
        cin >> x;
        if(x!=-1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            Q.Enqueue(t);
        }
    }
}

void BinaryTree::PreOrder(Node* p)
{
    if(p)
    {
        cout << p->data << " ";
        PreOrder(p->lchild);
        PreOrder(p->rchild);
    }
}

void BinaryTree::InOrder(Node *p)
{
    if(p)
    {
        InOrder(p->lchild);
        cout << p->data << " ";
        InOrder(p->rchild);
    }
}

void BinaryTree::PostOrder(Node *p)
{
    if(p)
    {
        PostOrder(p->lchild);
        PostOrder(p->rchild);
        cout << p->data << " ";
    }
}

void BinaryTree::LevelOrder(Node* p)
{
    Queue q(100);
    cout << root->data << " ";
    q.Enqueue(root);
    while(!q.isEmpty())
    {
        p = q.Dequeue();
        if(p->lchild)
        {
            cout << p->lchild->data << " ";
            q.Enqueue(p->lchild);
        }
        if(p->rchild)
        {
            cout << p->rchild->data << " ";
            q.Enqueue(p->rchild);
        }
    }
}

int BinaryTree::Height(Node *p)
{
    int l=0;
    int r=0;
    if(p==NULL)
        return 0;
    l = Height(p->lchild);
    r = Height(p->rchild);
    if(l>r)
        return l+1;
    else
        return r+1;
}

int main()
{
    BinaryTree bt;
    bt.Create();
    cout << "\nPreorder Traversal: ";
    bt.PreOrder(bt.root);
    cout << "\nInorder Traversal: ";
    bt.InOrder(bt.root);
    cout << "\nPostorder Traversal: ";
    bt.PostOrder(bt.root);
    cout << "\nLevel Order Traversal: ";
    bt.LevelOrder(bt.root);
    cout << "\nHeight of Binary Tree: " << bt.Height(bt.root) << endl;
    return 0;
}