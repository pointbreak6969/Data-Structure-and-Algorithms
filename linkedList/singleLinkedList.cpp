#include <iostream>

using namespace std;


struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
private:
    Node* head;

public:

    SinglyLinkedList() {
        head = nullptr;
    }


    ~SinglyLinkedList() {

        Node* current = head;
        while (current != nullptr) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
    }


    void insertAtBeginning(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    void insertAtEnd(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }


    void deleteFromBeginning() {
        if (head == nullptr) {
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    

    void deleteFromEnd() {
        if (head == nullptr) {
            return;
        }

    
        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* current = head;
        Node* prev = nullptr;


        while (current->next != nullptr) {
            prev = current;
            current = current->next;
        }

     
        prev->next = nullptr;
        delete current;
    }

 
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    SinglyLinkedList myList;

    myList.insertAtBeginning(5); 
    myList.insertAtBeginning(4); 
    myList.insertAtBeginning(3); 
    myList.insertAtBeginning(2);
    myList.insertAtEnd(6);       

    myList.display(); 

    myList.deleteFromEnd(); 


    myList.deleteFromBeginning(); 
    myList.display(); 

    return 0;
}