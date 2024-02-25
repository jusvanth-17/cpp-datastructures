#include<iostream>
using namespace std;

#define MAX 10

class stack {
    int top;
public:
    int a[MAX];
    stack() { top = -1; }
    bool push(int x);
    int pop();
    int peek();
    bool isempty();
};

bool stack::push(int x) {
    if (top >= (MAX - 1)) {
        cout << "stack overflow\n";
        return false;
    }
    else {
        a[++top] = x;
        cout << x << " pushed into stack\n";
        return true;
    }
}

int stack::pop() {
    if (top < 0) {
        cout << "stack underflow\n";
        return 0;
    }
    else {
        int x = a[top--];
        return x;
    }
}

int stack::peek() {
    if (top < 0) {
        cout << "stack is empty\n";
        return 0;
    }
    else {
        return a[top];
    }
}

bool stack::isempty() {
    return (top < 0);
}

int main() {
    stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << s.pop() << " popped from stack\n";
    cout << "Top element is: " << s.peek() << endl;
    cout << "Elements present in stack: ";
    while (!s.isempty()) {
        cout << s.peek() << " ";
        s.pop();
    }
    return 0;
}
