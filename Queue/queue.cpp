#include <iostream>
using namespace std;
int max_size = 5;
class Queue
{
private:
    int front, rear, arr[];

public:
    Queue()
    {
        front = -1;
        rear = -1;
        arr[max_size];
    }
    bool isFull()
    {
        return rear == max_size - 1;
    }
    bool isEmpty()
    {
        return (rear == -1) && (front == -1);
    }
    void peekFront()
    {
        int front = arr[front];
        cout<< "The front element is " << front <<endl;
    }
    void peekLast()
    {
        int last = arr[rear];
       cout<< "The last element is" << last <<endl;
    }
    void size()
    {
        if (isEmpty())
        {
            return;
        }
        int size = rear - front + 1;
        cout<<" The size of an array is" << size << endl;
    }
    void enqueue(int value)
    {
        if (isFull())
        {
            cout << "The queue is full " << endl;
            return;
        };
        if (isEmpty())
        {
            front =  rear = 0;
        }
        arr[++rear] = value;
        cout << value << " is enqueued in queue" << endl;
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "The queue is empty";
        }
        int item = arr[front++];
        cout << "the dequeued item is " << item << endl;
        if (front > rear)
        {
            front = rear = -1;
        }
    }
};

int main()
{
    Queue obj;
    obj.enqueue(50);
    obj.dequeue();
    obj.enqueue(100);
    obj.enqueue(200);
    obj.enqueue(300);
    obj.size();
    obj.peekFront();
    obj.peekLast();
    return 0;
}