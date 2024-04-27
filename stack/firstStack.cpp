#include <iostream>
using namespace std;

const int max_size = 5;
class stack {
    private: 
    int stack_arr[max_size];
    int top;

    public: 
    stack(){
        top = -1;
    }
    bool isFull(){
        return (top == max_size -1);
    }
    bool isEmpty(){
        return (top == -1);
    }
    int peek(){
        if (isEmpty()){
            cout << "The stack is empty"<< endl;
            return -1;
        }
        return stack_arr[top];
    }
    void push(int n){
        if (isFull()){
            cout<<"Stack Overflow! Cannot Push item "<<endl;
            return;
        }
        top = top +1;
        stack_arr[top] = n;
    }
    int pop(){
        if (isEmpty()){
            cout<<"Stack Underflow! Cannot pop item"<<endl;
            return -1;
        }
        return stack_arr[top--];
    }
};

int main(){
    stack stack;
stack.push(10);
stack.push(20);
stack.push(30);
cout<< "Top Element"<< stack.peek()<<endl;
cout<<"Popped Element:"<< stack.pop()<<endl;
cout<<"Popped Element" << stack.pop()<<endl;
cout<<"Top Element"<< stack.peek()<<endl;
return 0;
}