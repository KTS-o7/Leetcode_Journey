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
    bool evaluateTree(TreeNode* root) {
        if(root->left == nullptr && root->right == nullptr)
            return root->val;

        else
        {
            if(root->val == 2)
                return evaluateTree(root->left) || evaluateTree(root->right);
            else 
                return  evaluateTree(root->left) && evaluateTree(root->right);
        }
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Logic explained :
// 1. If the root is a leaf node, return the value of the node.
// 2. If the root is not a leaf node, then check if the value of the root is 2.
// 3. If the value of the root is 2, then return the logical OR of the left and right subtree.
// 4. If the value of the root is 3, then return the logical AND of the left and right subtree.