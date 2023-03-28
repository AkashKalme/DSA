#include <iostream>

using namespace std;

class DEQueue
{
private:
    int front;
    int rear;
    int size;
    int* Q;
public:
    DEQueue(int size);
    ~DEQueue();
    bool isEmpty();
    bool isFull();
    void enqueueFront(int x);
    void enqueueRear(int x);
    int dequeueFront();
    int dequeueRear();
    void Display();
};

DEQueue::DEQueue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

DEQueue::~DEQueue()
{
    delete[] Q;
}

bool DEQueue::isEmpty()
{
    if(front==rear)
        return true;
    return false;
}

bool DEQueue::isFull()
{
    if(rear==size-1)
        return true;
    return false;
}

void DEQueue::enqueueFront(int x)
{
    if(front==-1)
        cout << "DEQueue Overflow!" << endl;
    else
    {
        Q[front] = x;
        front--;
    }
}

void DEQueue::enqueueRear(int x)
{
    if(isFull())
        cout << "DEQueue Overflow!" << endl;
    else
    {
        rear++;
        Q[rear] = x;
    }
}

int DEQueue::dequeueFront()
{
    int x = -1;
    if(isEmpty())
        cout << "DEQueue Underflow!" << endl;
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}

int DEQueue::dequeueRear()
{
    int x = -1;
    if(rear==-1)
        cout << "DEQueue Underflow!" << endl;
    else
    {
        x = Q[rear];
        rear--;
    }
    return x;
}

void DEQueue::Display()
{
    for(int i=front+1; i<=rear; i++)
    {
        cout << Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    DEQueue Q(5);
    cout << "Is Empty? " << Q.isEmpty() << endl;
    cout << "Is Full? " << Q.isFull() << endl;
    Q.enqueueRear(1);
    Q.enqueueRear(2);
    Q.enqueueRear(3);
    Q.enqueueRear(4);
    Q.enqueueRear(5);
    Q.Display();
    cout << "Is Empty? " << Q.isEmpty() << endl;
    cout << "Is Full? " << Q.isFull() << endl;
    Q.enqueueRear(6);
    cout << Q.dequeueFront() << endl;
    cout << Q.dequeueFront() << endl;
    cout << Q.dequeueRear() << endl;
    cout << Q.dequeueRear() << endl;
    Q.Display();
    cout << "Is Empty? " << Q.isEmpty() << endl;
    cout << "Is Full? " << Q.isFull() << endl;
    Q.enqueueFront(7);
    Q.Display();
    cout << "Is Empty? " << Q.isEmpty() << endl;
    cout << "Is Full? " << Q.isFull() << endl;
    return 0;
}