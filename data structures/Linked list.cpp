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
#include <sstream>
#define ll long long
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
public:
   
    Node* head;
    Node* tail;
    int size;
    MyLinkedList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        if (index >= size) return -1;
        Node* cur = this->head;
        while(index--) cur = cur->next;
        return cur->val;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        size++;
        Node* root = new Node(val);
        root->next = head;
        this->head = root;
        if (size == 1) this->tail = this->head;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        size++;
        Node* newTail = new Node(val);
        this->tail->next = newTail;
        this->tail = newTail;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if (index > size || index < 0) return;
        if (index == 0) {
            addAtHead(val);
            return;
        }
        if (index == size) {
            addAtTail(val);
            return;
        }
        size++;
        Node* cur = this->head;
        while(--index) cur = cur->next;
        Node* newNode = new Node(val);
        newNode->next = cur->next;
        cur->next = newNode;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        if (index >= size || index < 0) return;
        if (index == 0) {
            if (size == 1) {
                delete(this->head);
                delete(this->tail);
            } else {
                Node* newHead = this->head->next;
                delete(this->head);
                this->head = newHead;
            }
            size--;
            return;
        }
        if (index == size - 1) {
            Node* cur = this->head;
            while(--index) cur = cur->next;
            delete cur->next;
            this->tail = cur;
            size--;
            return;
        }
        Node* cur = this->head;
        while(--index) cur = cur->next;
        Node* right = cur->next->next;
        delete(cur->next);
        cur->next = right;
        size--;
    }
};

int main() {
    MyLinkedList list = MyLinkedList();
    assert(list.size == 0);
    list.addAtIndex(0, 10);
    list.addAtIndex(0, 20);
    list.addAtIndex(1, 30);
    assert(list.size == 3);
    assert(list.head->val == 20);
    assert(list.tail->val == 10);
    list.addAtHead(1);
    assert(list.head->val == 1);
    assert(list.size == 4);
    list.addAtHead(2);
    assert(list.head->val == 2);
    assert(list.size == 5);
    list.addAtIndex(0, 12);
    assert(list.get(0) == 12);
    list.addAtIndex(1, 15);
    assert(list.get(1) == 15);
    // insert at tail
    list.addAtIndex(list.size, 99);
    assert(list.tail->val == 99);
    // delete from tail
    list.deleteAtIndex(list.size - 1);
    assert(list.tail->val != 99);
    // delete at head
    list.deleteAtIndex(0);
    assert(list.head->val != 12);
    list.addAtIndex(2, 1234);
    assert(list.get(2) == 1234);
    list.deleteAtIndex(2);
    assert(list.get(2) != 1234);
    return 0;
}

