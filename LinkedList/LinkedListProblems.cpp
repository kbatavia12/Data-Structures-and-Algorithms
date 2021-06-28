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

ListNode* removeElements(ListNode* head, int target) {
        if(head==NULL) return head;
        
        while(head!=NULL && head->data==target) head=head->next;
        
        ListNode *temp = head;
        while(temp!=NULL and temp->next!=NULL)
        {
            if(temp->next->data==target)
            {
                temp->next=temp->next->next;
            }
           else  temp=temp->next;
        }
        return head;
    }

void printLinkedList(ListNode* head) {
    //Iterate from start to the end of the linked list
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }

    cout << endl;
}

ListNode* swapNodes(ListNode* head, int k) {
    ListNode* temp = head;
    int count = 1;

    for (temp = head; temp != NULL; temp = temp->next) {
        count++;
    }

    temp = head;
    int i , j;
    for (i = 1, j = 1; i <= k, j <= count - k; i++, j++) {

    }

    cout << i << ' ' <<  j;

    return head;

}



bool isPalindrome(ListNode* head) {
    string checker = "";
    ListNode *temp = head;

    while(temp != NULL) {
        checker += temp->data + '0';
        temp = temp->next;
    }

    int left = 0, right = checker.size() - 1;
    while(left <= right) {
        if (checker[left] != checker[right]) return 0;
        left++;
        right--;
    }

    return 1;

}





int main() {
    ListNode* head = new ListNode(1);  
    ListNode* second = new ListNode(2);  
    ListNode* third = new ListNode(2);  
    ListNode* fourth = new ListNode(1);  
    // ListNode* fifth = new ListNode(3);  
    
    //Assign the links
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;
    // fifth->next = NULL;

    // printLinkedList(head);

    // ListNode* ans = removeElements(head, 2);

    // printLinkedList(ans);

    // swapNodes(head, 5);

    cout << isPalindrome(head) << endl;




}