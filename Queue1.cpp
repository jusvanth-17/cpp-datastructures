// Queue
#include <iostream>
#define SIZE 5
using namespace std;

class Queue
{
private:
    int items[SIZE], front, rear;

public:
    Queue()
    {
        front = -1;
        rear = -1;
    }

    bool isFull()
    {
        if (rear == SIZE - 1 && front == 0)
        {
            return true;
        }
        return false;
    }

    bool isEmpty()
    {
        if (front == -1)
        {
            return true;
        }
        return false;
    }

    void enQueue(int element)
    {
        if (isFull())
        {
            cout << "Queue is Full.." << endl;
            return;
        }
        if (front == -1)
            front = 0;
        rear++;
        items[rear] = element;

        cout << element << " is Inserted.." << endl;
    }

    void deQueue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty..";
            return;
        }

        front++;

        if (front > rear)
        {
            front = rear = -1;
        }
        cout << items[front - 1] << " is Removed.." << endl;
    }

    void printQueue()
    {
        if (isEmpty())
        {
            cout << "The Queue is Empty..";
            return;
        }
        for (int i = front; i <= rear; i++)
        {
            cout << items[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    Queue q;
    q.enQueue(26);
    q.printQueue();
    q.enQueue(36);
    q.printQueue();
    q.enQueue(46);
    q.printQueue();
    q.enQueue(56);
    q.printQueue();
    q.enQueue(26);
    q.printQueue();
    q.deQueue();
    q.printQueue();
    q.deQueue();
    q.printQueue();
    return 0;
}