#include<iostream>

using namespace std;

class CircularQueue
{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    CircularQueue(int size);
    ~CircularQueue();
    bool isEmpty();
    bool isFull();
    void Enqueue(int data);
    int Dequeue();
    void Display();
};

CircularQueue::CircularQueue(int size)
{
    this->size = size;
    front = rear = 0;
    Q = new int[this->size];
}

CircularQueue::~CircularQueue()
{
    delete []Q;
}

bool CircularQueue::isEmpty()
{
    if(rear==front)
        return true;
    return false;
}

bool CircularQueue::isFull()
{
    if((rear+1)%size==front)
        return true;
    return false;
}

void CircularQueue::Enqueue(int data)
{
    if(isFull())
        cout << "Queue Overflow!" << endl;
    else
    {
        rear = (rear+1)%size;
        Q[rear] = data;
    }
}

int CircularQueue::Dequeue()
{
    int x = -1;
    if(isEmpty())
        cout << "Queue Underflow!" << endl;
    else
    {
        front = (front+1)%size;
        x = Q[front];
    }
    return x;
}

void CircularQueue::Display()
{
    int i = front+1;
    do
    {
        cout << Q[i] << flush;
        if(i<rear)
            cout << " <- " << flush;
        i = (i+1)%size;
    } while(i!=(rear+1)%size);
}

int main()
{
    CircularQueue Q(7);
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