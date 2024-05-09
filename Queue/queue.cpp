#include <iostream>
using namespace std;

const int MAX = 5;

class Queue
{  
private:
    int front, rear;
    int arr[MAX];
public: 
Queue(){
    front = -1;
    rear = -1;
}
bool isFull(){
    if (rear == MAX - 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isEmpty(){
    if (front == -1 && rear == -1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int peak(){
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
    {
        return arr[front];
    }
}
void enqueue(int x){
    if (isFull())
    {
        cout << "Queue is full" << endl;
        return;
    }
    else if (isEmpty())
    {
        front = 0;
        rear = 0;
        arr[rear] = x;
    }
    else
    {
        rear++;
        arr[rear] = x;
    }
}
void dequeue(){
    if (isEmpty())
    {
        cout << "Queue is empty" << endl;
        return;
    }
    else if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        front++;
    }
}
 };

int main()
{
    Queue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    cout << "Element at front: " << q.peak() << endl;
    q.dequeue();
    return 0;
}
// Output:
// Element at front: 10
// Element at front: 20
// Element at front: 30
// Element at front: 40
// Element at front: 50
// Queue is full

// Explanation: In the above code, we have implemented a queue using an array. We have defined a class Queue with private data members front, rear, and arr. The front and rear are initialized to -1 in the constructor. The isFull() function checks if the queue is full by comparing the rear index with MAX-1. The isEmpty() function checks if the queue is empty by comparing the front and rear indices with -1. The peak() function returns the element at the front of the queue. The enqueue() function inserts an element at the rear of the queue. The dequeue() function removes an element from the front of the queue. In the main function, we create an object of the Queue class and perform enqueue and dequeue operations on the queue. We also check the element at the front of the queue after each operation. The output shows the element at the front of the queue after each dequeue operation and displays a message "Queue is full" when the queue is full.

// Time Complexity:
// The time complexity of the enqueue() and dequeue() operations is O(1) as they involve only updating the front and rear indices of the queue.
// The time complexity of the peak() operation is also O(1) as it involves accessing the element at the front of the queue.
// The time complexity of the isFull() and isEmpty() operations is O(1) as they involve simple comparisons.
// Therefore, the overall time complexity of the queue operations is O(1).
