//CircularLinkedList

#include <iostream>
using namespace std;

class CircularLL
{
public:
    int data;
    CircularLL *next;
    CircularLL(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void insertElement(CircularLL *&tail, int element, int data)
{
    if (tail == NULL)
    {
        CircularLL *node = new CircularLL(data);
        tail = node;
        node->next = node;
    }
    else
    {
        CircularLL *temp = tail;
        while (temp->data != element)
        {
            temp = temp->next;
        }
        CircularLL *newNode = new CircularLL(data);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void print(CircularLL *&tail)
{
    CircularLL *temp = tail;
    do
    {
        cout << tail->data << " ";
        tail = tail->next;
    } while (temp != tail);
    cout << endl;
}

int main()
{
    CircularLL *tail = NULL;
    insertElement(tail, 5, 30);
    print(tail);
    insertElement(tail, 30, 35);
    print(tail);
    return 0;
}