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

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;

        int left = maxDepth(root -> left);
        int right = maxDepth(root -> right);

        return 1 + max(left , right);
    }
};

// Time complexity: O(n)
// Space complexity: O(n) for the recursive stack

// Logic explained :
// 1. The maximum depth of a binary tree is the maximum depth of its left subtree and right subtree + 1
// 2. The base case is when the root is NULL, in which case the depth is 0
// 3. The recursive function returns the maximum depth of the left and right subtrees
// 4. The final answer is the maximum of the left and right subtree depths + 1