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

const int SIZE = 100;

class Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
    int count;
public:
    Queue(int size = SIZE);
    ~Queue();

    void pop();
    void push(int x);
    int peek();
    int size();
    bool isEmpty();
    bool isFull();
};

// Constructor
Queue::Queue(int size) {
    arr = new int[size];
    capacity = size;
    front = 0;
    rear = -1;
    count = 0;
}
// Destructor
Queue::~Queue() {
    delete arr;
}
// pop an element from the queue
void Queue::pop() {
    if (isEmpty()) {
        cout << "Underflow\n";
    }
    front = (front + 1) % capacity;
    count--;
}
// push an element to the queue
void Queue::push(int e) {
    if (isFull()) {
        cout << "Overflow\n";
        return;
    }
    rear = (rear + 1) % capacity;
    arr[rear] = e;
    count++;
}
// return the top of the Queue
int Queue::peek() {
    if (isEmpty()) {
        cout << "Underflow\n";
        return -1;
    }
    return arr[front];
}
// check if Queue is empty
bool Queue::isEmpty() {
    return count == 0;
}
// check if Queue is full
bool Queue::isFull() {
    return count == capacity;
}
// return the size of the queue
int Queue::size() {
    return count;
}

int main() {
    Queue q = Queue(12);
    q.push(14);
    cout << q.peek() << endl;
    q.pop();
    cout << q.isEmpty() << endl;
    return 0;
}
