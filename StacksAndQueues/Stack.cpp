// A stack is a last in first out data structure

/*
    The following operations should be included with stack implementation

    1. Push: Insert element at the top of the stack
    2. Pop: Remove element at the top of the stack
    3. isEmpty: Return true if stack is empty
    4. isFull return true if stack has reached maximum allocated capacity
    5. Peek: Return top element without modifying the stack
    6. Size: return the amount of elements present in the stack
*/

// The following is a stack implementation using an array

#include <iostream>
#include <cstdlib>

using namespace std;

// Define the default capacity of the stack
#define SIZE 10

class Stack {
    // private variables
    int *arr;
    int top;
    int capacity;

    public:
        Stack(int size = SIZE); // constructor
        ~Stack(); // destructor

        void push(int);
        int pop();
        int peek();
        int size();
        bool isEmpty();
        bool isFull();
};

Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

Stack::~Stack() {
    delete[] arr;
}

void Stack::push(int x) {
    if (isFull()) {
        cout << "Stack Already Full\n Program Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Inserting " << x << endl;
    arr[++top] = x;
}

int Stack::pop() {
    // check for stack underflow
    if (isEmpty()) {
        cout << "Stack Empty\n Program Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Removing " << peek() << endl;

    // Decrease stack size by 1 and (optionally) return the popped element
    return arr[top--];
}

int Stack::peek() {
    if (!isEmpty()) {
        return arr[top];
    } else {
        exit(EXIT_FAILURE);
    }
}

int Stack::size() {
    return top+1;
}

bool Stack::isEmpty() {
    return top == -1; // should return 1 if empty or 0 if not
}

bool Stack::isFull() {
    return top == capacity - 1;
}