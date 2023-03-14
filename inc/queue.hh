#ifndef QUEUE_HH
#define QUEUE_HH

#include <iostream>

using namespace std;

struct Elem {
    int value;
    Elem* next;
};

class Queue {
public:
    Queue() {
        head = nullptr;
        tail = nullptr;
    }
    
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }
    
    void enqueue(int value) {
        Elem* newElem = new Elem();
        newElem->value = value;
        newElem->next = nullptr;
        if (isEmpty()) {
            head = newElem;
        }
        else {
            tail->next = newElem;
        }
        tail = newElem;
    }
    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return;
        }
        Elem* temp = head;
        head = head->next;
        if (isEmpty()) {
            tail = nullptr;
        }
        delete temp;
    }
    
    int front() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return head->value;
    }
    
    int rear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return tail->value;
    }
    
    bool isEmpty() {
        return head == nullptr;
    }
    
private:
    Elem* head;
    Elem* tail;
};


#endif