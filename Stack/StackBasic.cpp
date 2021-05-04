#include <bits/stdc++.h>
using namespace std;

#define stackSize 500


//Implementation of Stack using arrays
class Stack {
    int top; //The top element of the stack

    public: 
        int a[stackSize]; //The array used for the stack
        Stack() {
            top = -1; //Init the top to -1 as the stack is empty
        }

    bool push(int val) {
        if (top >= (stackSize - 1)) { 
            cout << "Push: Stack Overflow>> XD" << endl; //Stack overflows if the Nth value is reached and it is full
            return 0;
        } else {
            a[++top] = val; //Increment the top of the stack by 1 and add the element to the top
            cout << "Pushed the value in the stack!" << endl;
            return 1;
        }
    }

    int pop() {
        if (top < 0) {
            cout << "Pop: Stack UnderFlow!" << endl; //Cannot pop the element if the stack is empty
            return 0;
        } else {
            int topValue = a[top--]; //Store the value at the topth position and decrement the top
            return topValue;
        }
    }

    int peek() {
        if(top < 0) {
            cout << "Peek: Stack UnderFlow!!" << endl; //Cannot get the element if the stack is empty
            return 0;
        } else {
            int topValue = a[top]; //Get the element at the topth position
            return topValue;
        }
    }

    bool isEmpty() {
        return (top < 0); //Check if the stack is empty using the top value
    }

    void printStack() {
        int traversal = top;
        if (top < 0) {
            cout << "Print: Stack UnderFlow" << endl;
            return;
        } else {
            while(traversal != -1) {
                cout << a[traversal] << endl;
                traversal--;
            }
        }

    }

    int getTop() {
        return top;
    }

};




int main() {

    Stack stack;

    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    
    stack.printStack();

    cout << stack.peek() << endl;


    return 0;
}

