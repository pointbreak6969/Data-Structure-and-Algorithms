#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Queue{
    private:
    Node *front;
    Node* rear;
    public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }
    bool isEmpty() {
        return front == nullptr;
    }
    void enqueue(int value) {
        Node * newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

    }
    void dequeue() {
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        Node * temp = front;
        cout << front->data << "has been dequeued" << endl;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
    }
    int peek() {
        if (isEmpty()){
            cout << "Queue is empty" << endl;
            return;
        }
        return front->data;
    }
};