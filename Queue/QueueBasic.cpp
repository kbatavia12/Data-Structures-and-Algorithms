#include <bits/stdc++.h>
using namespace std;

//Implementing a queue using array
class Queue
{
public:
    int front, rear, size; //Initialize the front index, rear index and the size of the queue
    unsigned capacity;     //The capacity of the queue
    int *array;            //The array which holds the actual queue

    //Initialize the queue with all the specified parameters
    Queue *createQueue(unsigned c)
    {
        // Queue* queue = new Queue();
        this->capacity = c;
        this->front = this->size = 0;
        this->rear = this->capacity - 1;
        this->array = new int[this->capacity];
        return this;
    }

    //If queue is not full, add the item at the rear index and increment the size
    void enqueue(int item)
    {
        if (isFull())
            return;

        rear = (rear + 1) % capacity;
        array[rear] = item;
        size++;
    }

    //If the queue is not empty, change the front and return the front item
    int dequeue()
    {
        if (isEmpty())
            return INT_MIN;

        int item = array[front];
        front = (front + 1) % capacity;
        size--;
        return item;
    }

    //get the front of the queue
    int getFront()
    {
        return array[front];
    }

    //get the rear of the queue
    int getRear()
    {
        return array[rear];
    }

    //Check if the queue is full
    bool isFull()
    {
        return (size == capacity);
    }

    //Check if the queue is empty
    bool isEmpty()
    {
        return (size == 0);
    }
};

//Implementing Queue using 2 stacks
//https://www.hackerrank.com/challenges/ctci-queue-using-two-stacks/problem?h_r=internal-search
class MyQueue
{

public:
    stack<int> s1, s2;
    void push(int x)
    {

        s1.push(x);
    }

    void pop()
    {

        if (s2.empty())
        {
            while (!s1.empty())
            {
                int top = s1.top();
                s1.pop();
                s2.push(top);
            }
        }
        s2.pop();
    }

    int front()
    {
        if (s2.empty())
        {
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }

        return s2.top();
    }
};

//Palindrome using stacks and queues
//https://www.hackerrank.com/challenges/30-queues-stacks/problem?h_r=internal-search

class Solution
{

public:
    queue<char> q1;
    stack<char> s1;

    void pushCharacter(char ch)
    {
        s1.push(ch);
    }

    void enqueueCharacter(char ch)
    {
        q1.push(ch);
    }

    char popCharacter()
    {
        if (!s1.empty())
        {
            char topChar = s1.top();
            s1.pop();
            return topChar;
        }
        else
        {
            return '\0';
        }
    }

    char dequeueCharacter()
    {
        if (!q1.empty())
        {
            char front = q1.front();
            q1.pop();
            return front;
        }
        else
        {
            return '\0';
        }
    }

    // The palindrome code is in the main function
};


int main()
{

    // MyQueue* obj = new MyQueue();

    // obj->push(1);
    // obj->push(2);
    // obj->push(3);

    // cout << "Queue Front: "<< obj->front() << endl;

    // Solution* obj = new Solution();

    // string s = "nitin";

    // int count = 0;

    // for (auto i: s) {
    //     obj->pushCharacter(i);
    //     obj->enqueueCharacter(i);
    // }

    // while(!obj->s1.empty() && !obj->q1.empty()) {
    //     char topChar = obj->s1.top();
    //     char frontChar = obj->q1.front();

    //     if (topChar == frontChar) {
    //         obj->s1.pop();
    //         obj->q1.pop();
    //         count++;
    //     } else {
    //         cout << "Not a palindrome!";
    //         break;
    //     }
    // }

    // if (count == s.length()) cout << "String is a palindrome!";

    // Queue* queue = new Queue();

    // queue->createQueue(5);

    // queue->enqueue(1);
    // queue->enqueue(2);
    // queue->enqueue(3);
    // queue->enqueue(4);

    // cout << queue->getFront() << endl;

    // cout << queue->dequeue() << endl;
    // cout << queue->getFront() << endl;



    return 0;
}