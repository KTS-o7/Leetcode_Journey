/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int value(TreeNode* root, bool flag)
    {
        if(root==NULL)
            return 0;
        if(root->left == NULL && root->right == NULL && flag)
            return root->val;
        
        return value(root->left,true) + value(root->right,false);

    }
    int sumOfLeftLeaves(TreeNode* root) {
        return value(root,false);  
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Logic Explained :
// 1. We will recursively traverse the tree and check if the node is a left leaf node or not.
// 2. If the node is a left leaf node, we will add the value of the node to the sum.
// 3. We will recursively call the left child of the node with flag as true and right child of the node with flag as false.
// 4. If the node is not a left leaf node, we will recursively call the left child of the node with flag as true and right child of the node with flag as false.
// 5. We will return the sum of left leaf nodes.