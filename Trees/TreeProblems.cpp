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

// TreeNode* createTree() {
    
//     return root;
// }



bool isSameTree(TreeNode* p, TreeNode* q) {


    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    // if ((p == nullptr && q != nullptr) || (p != nullptr && q == nullptr)) return false; 

    bool left = isSameTree(p->left, q->left); 
    bool right = isSameTree(p->right, q->right); 


    return (left && right && (p->data == q->data));

}

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    
    if (root->left == nullptr && root->right ==nullptr) return 1;

    int left = maxDepth(root->left) + 1;
    int right = maxDepth(root->right) + 1;

    return max(left, right);

}

int minDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int right = 0, left = 0;
    if (root->left == nullptr)  return minDepth(root->right) + 1;
    if (root->right == nullptr) return minDepth(root->left) + 1;

    return fmin(minDepth(root->left), minDepth(root->right)) + 1;

}


bool hasPathSum(TreeNode* root, int targetSum) {
    if (root == nullptr) return false;

    if (root->left == nullptr && root->right == nullptr && root->data - targetSum == 0) return true;
    else if ((root->left == nullptr && root->right == nullptr) && root->data - targetSum != 0) return false;

    return hasPathSum(root->left, targetSum - root->data) || hasPathSum(root->right, targetSum - root->data);
    
    

}


//https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/
TreeNode* getBST(vector<int> nums, int low, int high) {
    if (low > high) return nullptr;

    int mid = (low + high) / 2;

    TreeNode* root = new TreeNode(nums[mid]);
    
    root->left = getBST(nums,low, mid -1);
    root->right = getBST(nums,mid + 1, high);


    return root;
}

TreeNode* sortedArrayToBST(vector<int> nums) {
    int n = nums.size() -1;

    return getBST(nums, 0, n);
}




//https://leetcode.com/problems/symmetric-tree/
bool isSymmetricHelper(TreeNode* left, TreeNode* right) {
    if (left == NULL && right == NULL) return 1;
    if (left == NULL || right == NULL) return 0;

    if (left->data != right->data) return 0;

    return isSymmetricHelper(left->left, right->right) && isSymmetricHelper(left->right, right->left);


}
bool isSymmetric(TreeNode* root) {
    if (root == NULL) return 1;
    return isSymmetricHelper(root->left, root->right);
}









int main() {
    // TreeNode* root = createTree();
    // TreeNode* root2 = createTree();

    // TreeNode* root3 = new TreeNode(1);
    // root3->left = new TreeNode(2);
    // root3->right = new TreeNode(3);
    // // root3->left->left = new TreeNode(4);
    // // root3->left->right = new TreeNode(5);
    // // root3->right->left = new TreeNode(6);

    // cout << isSameTree(root, root2) << endl;
    // cout << isSameTree(root3, root2) << endl;

    // cout << minDepth(root3);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    // bool ans = isSymmetric(root);
    // cout << ans;



    return 0;
}