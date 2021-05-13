#include <bits/stdc++.h>
using namespace std;


//Implementation of priority queue using linked list

//Create a linked list Node with and additional property for priority
class Node {
    public:
        int data, priority;
        Node* next;

        Node(int val, int pr) {
            data = val;
            priority = pr;
            next = NULL;
        }
};

class PriorityQueue {  
    public:
    
        void push(Node* &head,int value, int priority) {
            Node* newNode = new Node(value, priority); //create a instance of the Node class for the node to be inserted
            if (head == NULL) {
                head = newNode; //IF the queue is empty, the newNode is the head of the element
                return;
            }

            if (newNode->priority > head->priority) {
                newNode->next = head; //If the incoming node's priority is greater than the priority of the current head, insert that node at the head
                head = newNode;
                return;
            }

            //If the newNode's priority is less than that of the head, traverse the list until we get a lower priority node and insert the node there
            if (newNode->priority < head->priority) {
                Node* temp = head; 
                while(temp->next != NULL && (temp->next->priority > priority)) {
                        temp = temp->next;
                }


                //If the priority is the lowest, it will be added to the end of the list, else somewhere in between other elements
                newNode->next = temp->next;
                temp->next = newNode;
            }
        }


        //Dequeue the current head because it has the highest priority 
        void pop(Node* &head) {
            Node* temp = head; //Store the current head into a temp Node pointer
            head = head->next; //The new head is the next node in the list
            delete temp; //Free up the memory
        } 

        int getFront(Node* &head) {
            if (head == NULL) return -1; //If there are no elements
             
            return head->data; //Return the data in the head which has the highest priority
        }

        bool isEmpty(Node* &head) {
            return head == NULL; //If head is NULL, the list is empty, else it contains something
        }
     
};


int main() {


    //Driver Program
    Node* n = new Node(1,1);
    PriorityQueue* pq;

    pq->push(n,1,1);
    pq->push(n,2,3);
    pq->push(n,3,4);
    pq->push(n,4,5);

    cout << pq->getFront(n) << endl;

    pq->pop(n);

    cout << pq->getFront(n) << endl;


    return 0;
}