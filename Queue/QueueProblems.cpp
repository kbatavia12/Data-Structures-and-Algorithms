#include <bits/stdc++.h>
using namespace std;



//Check if a queue can be sorted into another queue using a stack
//https://www.geeksforgeeks.org/check-queue-can-sorted-another-queue-using-stack/

bool checkSorted(int n, queue<int> q) {
    int expectedElement = 1;
    queue<int> sortedQueue;
    stack<int> checkStack;

    while(!q.empty()) {
        int front = q.front();
        q.pop();

        if (front == expectedElement) {
            expectedElement++;
            sortedQueue.push(front);
        } else {
            if (checkStack.empty())
                checkStack.push(front);
            else if (checkStack.top() < front) 
                return 0;
            else 
                checkStack.push(front); 
        }

        while((!checkStack.empty()) && (checkStack.top() == expectedElement)) {  
            checkStack.pop();
            expectedElement++;

        }

    }

    if ((expectedElement = n + 1) && checkStack.empty()) {
        return 1;
    }
    return 0;

}

//Reverse a queue using a stack
void reverseQueue(queue<int> &A) {
    stack<int> temp;

    while(!A.empty()) {
        temp.push(A.front());
        A.pop();
    }

    while(!temp.empty()) {
        A.push(temp.top());
        temp.pop();
    }

}

//reverse the queue recursively
queue<int> reverseQueueRecursive(queue<int> A) {
    if (A.empty()) {
        return A;
    } else {
        int front = A.front();
        A.pop();
        A = reverseQueueRecursive(A);
        A.push(front);
        return A;
    }
}


int main() {

       //Driver program 
    queue<int> pass;
    pass.push(5);
    pass.push(3);
    pass.push(2);
    pass.push(1);
    pass.push(4);
    
    //Sorted queue problem Line: 07
    // bool ans = checkSorted(5, pass);
    // cout << ans;

    //Reverse a queue Line: 44
    // cout << pass.front() << endl;
    // reverseQueue(pass);
    // cout << pass.front() << endl;


    //Reverse a queue recursively Line:60
    // cout << pass.front() << endl;
    // reverseQueue(pass);
    // cout << pass.front() << endl;



}