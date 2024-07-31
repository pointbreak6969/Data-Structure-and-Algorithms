#include<iostream>
using namespace std;

struct Node {
    int data;
    Node * prev;
    Node* next;
    Node(int value) {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class doublyLinkedList{
    private:
    Node * head;
    Node * tail;
    public:
    doublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void insertAtBeginning(int value) {
        Node * newNode = new Node(value);
        newNode->prev = nullptr;
        newNode->next = head;
        if ( head !=nullptr) {
            head->prev = newNode;
        } else {
            tail = newNode;
        }
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node * newNode = new Node(value);
        newNode->next = nullptr;
        newNode->prev = tail;
        if (tail !=nullptr) {
            tail->next = newNode;
        } else{
            head = newNode;
        }
        tail = newNode;
    }
    void deleteNode(int value) {
        Node* current = head;
        while (current !=nullptr && current->data !=value) {
            current = current->next;
        }
        if (current ==nullptr) {
            cout << "Node with value" << value << "not found" << endl;
            return;
        }
        if (current == head) {
            head = current->next;
            if (head !=nullptr) {
                head->prev = nullptr;
            }else {
                tail = nullptr;
            }
        }else if ( current == tail) {
            tail = current->prev;
            tail->next = nullptr;
        } else {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Node with value" << value << "deleted" <<endl;
    }
    void displayForward() {
        Node *current = head;
        while (current !=nullptr) {
            cout << current->data << " " << endl;
            current = current->next;
        }
    }
    void displayBackward() {
        Node *current = tail;
        while (current !=nullptr) {
            cout << current->data << " " ;
            current = current->prev;
        }
    }
};