#include <bits/stdc++.h>
using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* left, *right;

        TreeNode(int val) {
            data = val;
            left = right = nullptr;
        }
};


//                  1    <- root 
//               /   \ 
//      left-> 2      3 <- right
//            /        \
//    left->4           5 <- right


TreeNode* createTree() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);
    return root;
}


//Left -> Root -> Right
void printInOrder(TreeNode* root) {
    if (root == nullptr) return; //Return if  any of the children are null or the root is leaf node (after the recursive call)

    printInOrder(root->left); //Call for the left Subtree
     
    cout << root->data << " "; //print the values at return time

    printInOrder(root->right); //Call for the right subtree

}

//Root -> Left -> Right
void printPreOrder(TreeNode* root) {
    if (root == nullptr) return; //Return if  any of the children are null or the root is leaf node (after the recursive call)

    cout << root->data << ' '; //print the values as soon as it is called

    printPreOrder(root->left); //Call for the left Subtree
    printPreOrder(root->right); //Call for the right Subtree

}

//Left -> Right -> Root
void printPostOrder(TreeNode* root) {
    if (root == nullptr) return; //Return if  any of the children are null or the root is leaf node (after the recursive call)

    printPostOrder(root->left); //Call for the left Subtree
    printPostOrder(root->right); //Call for the right Subtree

    cout << root->data << " "; //Print the node data
}

//Tree traversal using stack iterative (Inorder)

void inOrderStack(TreeNode* root) {
    stack<TreeNode*> st;     //Create a stack to push the elements
    TreeNode* current = root; //Traversal node

    //Run the loop until the stack is empty or if we get a Null node
    while(!st.empty() || current!= NULL) {
        
        //Push all the left nodes to the stack
        while(current != NULL) { 
            st.push(current);
            current = current->left;
        }

        current = st.top(); 
        st.pop();  //Pop the nodes from the stack

        cout << current->data << " "; //Print the data

        current = current->right; //Print out all the right nodes

    }

}







int main() {
    TreeNode* root = createTree();

    printInOrder(root);
    cout << endl;
    printPreOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    inOrderStack(root);
    cout << endl;
}