#include<iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue(int size);
    ~Queue();
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    int Dequeue();
    void Display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = -1;
    rear = -1;
    Q = new int[size];
}

Queue::~Queue()
{
    delete []Q;
}

bool Queue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}

bool Queue::isFull()
{
    if(rear==size-1)
        return true;
    return false;
}

void Queue::Enqueue(int data)
{
    if(isFull())
    {
        cout << "Queue is Full!"<< endl;
        return;
    }
    rear++;
    Q[rear] = data;
}

int Queue::Dequeue()
{
    int x = -1;
    if(isEmpty())
    {
        cout << "Queue is Full!" << endl;
        return x;
    }
    front++;
    x = Q[front];
    return x;
}

void Queue::Display()
{
    int i = 0;
    for(i=front+1; i<=rear; i++)
    {
        cout << Q[i] << flush;
        if(i<rear)
            cout << "<-" << flush;
    }
    cout << endl;
}

int main()
{
    Queue Q(7);
    cout << "Is Empty?  " << Q.isEmpty() << endl;
    cout << "Is Full?   " << Q.isFull() << endl;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    cout << "Is Empty?  " << Q.isEmpty() << endl;
    cout << "Is Full?   " << Q.isFull() << endl;
    Q.Display();
    Q.Dequeue();
    Q.Dequeue();
    Q.Dequeue();
    cout << "Is Empty?  " << Q.isEmpty() << endl;
    cout << "Is Full?   " << Q.isFull() << endl;
    Q.Enqueue(4);
    Q.Enqueue(5);
    Q.Enqueue(6);
    Q.Display();
    return 0;
}