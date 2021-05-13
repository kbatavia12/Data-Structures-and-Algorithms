#include <bits/stdc++.h>
using namespace std;


class ListNode {
    public:
        int data; //The core data
        ListNode* next; // The pointer to next node

    ListNode(int val) {
        data = val; //Init the data
    }

};


// Print a list from the given start point
void printLinkedList(ListNode* head) {
    //Iterate from start to the end of the linked list
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

void insertNodeAtHead(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);

    if (head != NULL) {
        newNode->next = head; // The next ptr of the newNode is the current head
        head = newNode; //The newNode is the new Head
    } else {
        head = newNode; //If there is no head, then the newNode becomes the first and the last node
        head->next = NULL;
    }


}

//Inserts a node after the given node
void insertAfterGivenNode(ListNode* givenNode, int value) {
    ListNode* newNode = new ListNode(value);

    if (givenNode != NULL) {
        newNode->next = givenNode->next; // Point the newNode to the current next node of the givenNode
        givenNode->next = newNode; //Point the givenNode to the newNode
    } else {
        return; //Do nothing if the givenNode is NULL
    }

}


void insertNodeAtEnd(ListNode* &head, int value) {
    ListNode* newNode = new ListNode(value);
    ListNode* temp = head; //This the temp node we will use to traverse through the list

    if (head == NULL) {
        head = newNode; //If head is null the newNode will be the first and the last node
        return;
    }

    while(temp->next != NULL) {
        temp = temp->next; //Iterate till the last node
    }

    temp->next = newNode; //Point the current last node to the newNode
    newNode->next = NULL; //Point the new last node to NULL

}

void deleteGivenNode(ListNode* &head, int key) {
    ListNode* temp = head; //Traversal node

    if (head == NULL) {
        cout << "The list is empty!" << endl; //Return if there are no elements in the linked list
        return;
    }


    while(temp!= NULL) {
        if (temp->next->data == key) { //If the next node has to be deleted
            temp->next = temp->next->next; //Point the current node to the next node of the deleting node
            return;
        }
        temp = temp->next;
    }

    delete temp->next; //Free up the memory
}

// TODO: Learn how to delete nodes recursively

void deleteNodeAtGivenPosition(ListNode* &head, int pos) {
    int count = 0; //keep track of number of elements
    ListNode* temp = head; //Traversal node
    if (head == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    while(temp!= NULL) {
        if (count == pos - 1 && temp->next != NULL) { //Check if we are on the previous node of the given node 
            temp->next = temp->next->next; //Skip and change the pointer
            return; 
        }
        temp = temp->next;
        count++; 
    }

    delete temp->next; //Free up the memory
    
}

void deleteLinkedList(ListNode* &head) {
    ListNode* temp = head;
    ListNode* currentNode = head;
    
    if (head == NULL) {
        cout << "The list is empty!" << endl;
        return;
    }

    while(temp!=NULL) {
        temp = currentNode->next;
        delete currentNode;
        currentNode = temp;
    }

    head = NULL;


}

int getLength(ListNode* head) {
        int count = 0; //Keep track of elements
        ListNode* temp = head; //Traversal node
        while(temp!=NULL) {
            count++; 
            temp = temp->next;
        }

        return count;
}   

int getLengthRecursive(ListNode* head) {
        if (head == NULL) {
            return 0;
        }

        return 1 + getLengthRecursive(head->next); //Recursive call with the next pointer as the head
}

bool isPresentInList(ListNode* head, int x) {
        ListNode* temp = head;

        if (head == NULL) return 0; //Return 0 if there is no element in the list

        while(temp != NULL) {
            if (temp->data == x) {
                return 1; //Return true if data matches
            }
            temp = temp->next;
        }

        return 0;
}

int getNthNode(ListNode* head, int index) {
    int count = 0; //Initialize the position counter
    ListNode*temp = head;

    while(temp != NULL) {
        if (count == index) {
            return temp->data; //Return the data in the list when we reach the position
        }
        temp = temp->next;
        ++count; //Increment the count after each traversal
    }

    return 0;
    
}

int getNthNodeRecursive(ListNode* head, int index) {
    int count = 0;
    ListNode* temp = head;
    if (count == index) return temp->data; //Return the data if we get the node
    else return getNthNodeRecursive(temp->next, index-1); //Recursively call the function with the next node and the position - 1

}

int getMiddleOfLinkedList(ListNode* head) {
    ListNode* slow = head; //Will increment by 1
    ListNode* fast = head; //Will increment by 2

    //The main idea is that when the fast pointer moves twice as fast the slow pointer, when the fast pointer reaches the end, the slow pointer reaches the middle

    if (head != NULL) {
        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next; //Skip a node always
            slow = slow->next; 
        }
    }

    return slow->data; //Return the data of the slow pointer

}

int countNumberOfOccurences(ListNode* head, int value) {
    int count = 0;

    while(head != NULL) {
        if (head->data == value) {
            ++count;
        }
        head = head->next;
    }

    return count;

}

//TODO Finish the cycle program
bool detectCycle(ListNode* head) {

}

int getNthNodeValueFromLast(ListNode* head, int pos) {
    ListNode* reference = head;
    ListNode* main = head;

    for(int i = 0; i < pos;i++) {
        reference = reference->next;
    }

    while(reference!=NULL) {
        main = main->next;
        reference = reference->next;
    }

    return main->data;
}

//Reverse a linked list using stack
ListNode* reverseList(ListNode* &head) {
    ListNode* temp = head; //Traversal node
    stack<ListNode*> st; //Stack to store the nodes

    while(temp->next != NULL) {
        st.push(temp); //Push all the nodes into the stack
        temp = temp->next;
    }

    head = temp; //Initialize head to temp to attach elements in the reverse order
    while(!st.empty()) { 
        temp->next = st.top(); //attach top element of the stack to the list  
        temp = temp->next; 
        st.pop(); //Pop the element from the stack
    }

    temp->next = NULL; //After the last element is popped, change its next pointer to NULL
    return head; //Return the head

}



int main() {
    //Create nodes
    ListNode* head = new ListNode(1);  
    ListNode* second = new ListNode(2);  
    ListNode* third = new ListNode(3);  

    //Assign the links
    head->next = second;
    second->next = third;
    third->next = NULL;
    
    //Insert a node at the start of the linked list
    insertNodeAtHead(head, 0);
    insertNodeAtHead(head, 1);
    insertNodeAtHead(head, 1);
    insertNodeAtHead(head, 1);

    //Insert a node in between
    insertAfterGivenNode(second, 5);

    //Insert a node at the end
    insertNodeAtEnd(head, 10);

    // printLinkedList(head);


    //Delete a node with a given value
    deleteGivenNode(head, 10);

    // printLinkedList(head);

    //Delete at given position
    deleteNodeAtGivenPosition(head, 2);

    //Delete the list
    // deleteLinkedList(head);

    //Get the length of the list
    int lengthOfList = getLength(head);
    int recursiveLength = getLengthRecursive(head);
    
    //Check if element is present in a linked list
    cout << isPresentInList(head, 5) << endl;

    //Get the nth Node in a linked list
    cout << getNthNode(head,2) << endl;
    cout << getNthNodeRecursive(head,3) << endl;

    //Get the middle element of the linked list
    cout << getMiddleOfLinkedList(head) << endl;

    //Number of occurences of 1 in list
    cout << countNumberOfOccurences(head, 1) << endl;


    cout << getNthNodeValueFromLast(head, 3) << endl;

    //Print the list
    printLinkedList(head);
    
    reverseList(head);
    printLinkedList(head);

    return 0;
}