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
      
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return false;
        targetSum -= root->val;
        if ( root->left == nullptr && root->right == nullptr && targetSum ==0)
            return true;
        
        return hasPathSum(root->left,targetSum) || hasPathSum(root->right,targetSum);
        
    }
};

// Time complexity: O(N)
// Space complexity: O(N)

// Explanation: We need to find if there is a path from the root to a leaf node in the binary tree such that the sum of the values of the nodes in the path is equal to the target sum. We can use a recursive approach to solve this problem.
/*
1. Check if the root is null. If it is, return false.
2. Subtract the value of the current node from the target sum.
3. Check if the current node is a leaf node and if the target sum is 0. If both conditions are met, return true.
4. Recursively call the function on the left and right children of the current node with the updated target sum.
*/