#include <iostream>
using namespace std;
struct Node {
    int data;
    Node *next;
    Node(int value){
        data = value;
        next = nullptr;
    }
};

class Stack{
    private:
    Node *top;
    public:
    Stack() {
        top = nullptr;
    }
    bool isEmpty() {
        return top == nullptr;
    }
    void push(int value) {
        Node * newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        cout << value << "pushed to stack" << endl;
    }
    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        Node *temp = top;
        top = top->next;
        cout << temp->data << "has been popped" << endl;
        delete temp;
    }
    int peek() {
         if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        return top->data;
    }
};