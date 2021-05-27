#include <bits/stdc++.h>
using namespace std;

class BSTNode {
    public:
        int data;
        BSTNode* left, *right;

        BSTNode(int val) {
            data = val;
            left = right = NULL;
        }
};




BSTNode* insertNode(BSTNode* &root, int data) {
    BSTNode *p;
    if (root == NULL) {

        p = new BSTNode(data);
        p->left = p->right = NULL;
        root = p;
        return root;
    }    

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;

}




void printInOrder(BSTNode* root) {
    if (root == NULL) return;

    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

BSTNode* search(BSTNode* root, int x) {
    if (root == NULL) return NULL;
    else if (root->data < x) return search(root->right, x);
    else if (root->data > x) return search(root->left, x);
    else return root;

}

BSTNode* findMin(BSTNode* root) {
    if (root == NULL) return NULL;
    if (root->left == NULL) return root;

    return findMin(root->left);
}


BSTNode* findMax(BSTNode* root) {
    if (root == NULL) return NULL;
    if (root->right == NULL) return root;

    return findMax(root->right);
}
int main() {
    BSTNode* root = NULL;

    insertNode(root, 1);
    insertNode(root, 5);
    insertNode(root, -1);
    insertNode(root, -7);
    insertNode(root, 10);
    insertNode(root, -5);


    printInOrder(root);
    cout << endl;

    BSTNode* el = search(root, -7);

    cout << el->data << endl;

    BSTNode* mini = findMin(root);
    cout << mini->data << endl;
    
    BSTNode* maxi = findMax(root);
    cout << maxi->data << endl;

    return 0;
}
