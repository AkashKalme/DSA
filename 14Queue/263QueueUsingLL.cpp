#include<iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

class Queue
{
private:
    Node *front;
    Node *rear;
public:
    Queue();
    ~Queue();
    bool isEmpty();
    void Enqueue(int x);
    int Dequeue();
    void Display();
};

Queue::Queue()
{
    front = rear = NULL;
}

Queue::~Queue()
{
    Node* p=front;
    while(front)
    {
        front = front->next;
        delete p;
        p = front;
    }
}

bool Queue::isEmpty()
{
    if(front==NULL)
        return true;
    return false;
}

void Queue::Enqueue(int x)
{
    Node* t = new Node;
    if(t==NULL)
        cout << "Queue Overflow!" << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if(isEmpty())
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int Queue::Dequeue()
{
    int x = -1;
    Node* p;
    if(isEmpty())
        cout << "Queue Underflow!" << endl;
    else
    {
        p = front;
        x = p->data;
        front = front->next;
        delete p;
    }
    return x;
}

void Queue::Display()
{
    Node* p = front;
    while(p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}

int main()
{
    Queue Q;

    cout << "Is Empty?" << Q.isEmpty() << endl;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    cout << "Is Empty?" << Q.isEmpty() << endl;
    Q.Display();
    cout << endl;
    Q.Dequeue();
    Q.Dequeue();
    Q.Display();
    cout << endl;
    cout << "Is Empty?" << Q.isEmpty() << endl;
    Q.Dequeue();
    cout << "Is Empty?" << Q.isEmpty() << endl;
    Q.Display();

    return 0;
}