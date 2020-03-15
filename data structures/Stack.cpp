#include <iostream>
#include <assert.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <string.h>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;

const int MAX_SIZE = 1e5;

class Stack {
private:
    int *arr;
    int capacity;
    int top;
public:
    Stack(int size = MAX_SIZE);
    ~Stack();
    
    bool push(int);
    int pop();
    int peek();
    
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor
Stack::Stack(int size) {
    arr = new int[size];
    capacity = size;
    top = -1;
}

// Deconstructor
Stack::~Stack() {
    delete arr; // free memory allocated
}

// Push element e to the stack
bool Stack::push(int e) {
    if (isFull()) {
        cout << "OverFlow\n";
        return false;
    }
    arr[++top] = e;
    return true;
}
// Pop top element from the stack
int Stack::pop() {
    if (isEmpty()) {
        cout << "UnderFlow\n";
        return 0;
    }
    return arr[top--];
}
// Return top element in the stack
int Stack::peek() {
    if (isEmpty()) {
        cout << "Empty stack\n";
        return 0;
    } else {
        return arr[top];
    }
}
// Return size of the stack
int Stack::size() {
    return top + 1;
}
// Check if stack is empty
bool Stack::isEmpty() {
    return top == -1;
}
// Check if stack is full
bool Stack::isFull() {
    return top + 1 == capacity;
}
int main() {
    Stack s = Stack(2);
    s.push(1);
    s.push(2);
    cout << s.peek() << endl;
    s.push(3);
    cout << s.peek() << endl;
    s.pop();
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    return 0;
}
