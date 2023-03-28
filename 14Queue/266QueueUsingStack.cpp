#include <bits/stdc++.h>

using namespace std;

class Queue
{
    stack<int> eStack;
    stack<int> dStack;
public:
    void Enqueue(int x);
    int Dequeue();
};

void Queue::Enqueue(int x)
{
    eStack.push(x);
}

int Queue::Dequeue()
{
    int x = -1;
    if(dStack.empty())
    {
        if(eStack.empty())
        {
            cout << "Queue Underflow!" << endl;
            return x;
        }
        else
        {
            while(!eStack.empty())
            {
                dStack.push(eStack.top());
                eStack.pop();
            }
        }
    }
    x = dStack.top();
    dStack.pop();
    return x;
}

int main()
{
    Queue Q;
    Q.Enqueue(1);
    Q.Enqueue(2);
    Q.Enqueue(3);
    cout << Q.Dequeue() << endl;
    Q.Enqueue(4);
    cout << Q.Dequeue() << endl;
    Q.Enqueue(5);
    cout << Q.Dequeue() << endl;
    cout << Q.Dequeue() << endl;

    return 0;
}