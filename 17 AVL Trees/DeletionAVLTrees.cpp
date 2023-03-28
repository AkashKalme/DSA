#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
    Node* lchild;
    int data;
    Node* rchild;
    int height;
};

class AVL
{
public:
    Node* root;

    AVL()
    {
        root = NULL;
    }
    int nodeHeight(Node* p);
    int balanceFactor(Node* p);
    Node* LLRotation(Node* p);
    Node* RRRotation(Node* p);
    Node* LRRotation(Node* p);
    Node* RLRotation(Node* p);
    Node* InPre(Node* p);
    Node* InSucc(Node* p);

    Node* rInsert(Node* p, int key);

    Node* Delete(Node* p, int key);

    void Inorder(Node* p);
    void Inorder()
    {
        Inorder(root);
    }
    Node* getRoot()
    {
        return root;
    }
};

int AVL::nodeHeight(Node* p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;

    return (hl>hr) ? (hl+1) : (hr+1);
}

int AVL::balanceFactor(Node* p)
{
    int hl, hr;
    hl = (p && p->lchild) ? p->lchild->height : 0;
    hr = (p && p->rchild) ? p->rchild->height : 0;
    return hl-hr;
}

Node* AVL::LLRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = p;
    p->lchild = plr;

    p->height = nodeHeight(p);
    pl->height = nodeHeight(pl);

    if(root==p)
        root = pl;
    return pl;
}

Node* AVL::RRRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = p;
    p->rchild = prl;

    p->height = nodeHeight(p);
    pr->height = nodeHeight(pr);

    if(root==p)
        root = pr;
    return pr;
}

Node* AVL::LRRotation(Node* p)
{
    Node* pl = p->lchild;
    Node* plr = pl->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = nodeHeight(pl);
    p->height = nodeHeight(p);
    plr->height = nodeHeight(plr);

    if(root==p)
        root = plr;
    return plr;
}

Node* AVL::RLRotation(Node* p)
{
    Node* pr = p->rchild;
    Node* prl = pr->lchild;

    pr->lchild = prl->rchild;
    p->rchild = prl->lchild;

    prl->lchild = pr;
    prl->rchild = p;

    pr->height = nodeHeight(pr);
    p->height = nodeHeight(p);
    prl->height = nodeHeight(prl);

    if(root==p)
        root = prl;
    return prl;
}

Node* AVL::rInsert(Node* p, int key)
{
    Node *t;
    if(p==NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;
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

    p->height = nodeHeight(p);

    if(balanceFactor(p)==2 && balanceFactor(p->lchild)==1)
    {
        return LLRotation(p);
    }
    else if(balanceFactor(p)==2 && balanceFactor(p->lchild)==-1)
    {
        return LRRotation(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==-1)
    {
        return RRRotation(p);
    }
    else if(balanceFactor(p)==-2 && balanceFactor(p->rchild)==1)
    {
        return RLRotation(p);
    }
    return p;
}

Node* AVL::InPre(Node *p) {
    while (p && p->rchild != nullptr){
        p = p->rchild;
    }
    return p;
}

Node* AVL::InSucc(Node *p) {
    while (p && p->lchild != nullptr){
        p = p->lchild;
    }
    return p;
}

Node* AVL::Delete(Node *p, int key) {
    if (p == nullptr){
        return nullptr;
    }

    if (p->lchild == nullptr && p->rchild == nullptr){
        if (p == root){
            root = nullptr;
        }
        delete p;
        return nullptr;
    }

    if (key < p->data){
        p->lchild = Delete(p->lchild, key);
    } else if (key > p->data){
        p->rchild = Delete(p->rchild, key);
    } else {
        Node* q;
        if (nodeHeight(p->lchild) > nodeHeight(p->rchild)){
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }

    // Update height
    p->height = nodeHeight(p);

    // Balance Factor and Rotation
    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1) {  // L1 Rotation
        return LLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1){  // L-1 Rotation
        return LRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == -1){  // R-1 Rotation
        return RRRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 1){  // R1 Rotation
        return RLRotation(p);
    } else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 0){  // L0 Rotation
        return LLRotation(p);
    } else if (balanceFactor(p) == -2 && balanceFactor(p->rchild) == 0){  // R0 Rotation
        return RRRotation(p);
    }
 
    return p;
}

void AVL::Inorder(Node* p)
{
    if(p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}

int main()
{
    AVL tlr;
    tlr.root = tlr.rInsert(tlr.root, 50);
    tlr.root = tlr.rInsert(tlr.root, 10);
    tlr.root = tlr.rInsert(tlr.root, 20);
    tlr.root = tlr.rInsert(tlr.root, 28);
    tlr.root = tlr.rInsert(tlr.root, 15);

    tlr.Inorder();
    cout << endl;
    tlr.Delete(tlr.root, 28);

    tlr.Inorder();
    return 0;
}