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
    int dfs(TreeNode* root, int path)
    {
        if(root==nullptr)
            return 0;
        path = path*10 + root->val;
        if(root->left == nullptr && root->right == nullptr)
            return path;

        return dfs(root->left,path)+dfs(root->right,path);
    }
    int sumNumbers(TreeNode* root) {
        return dfs(root,0);
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Logic explained :
// 1. We are using a recursive approach to solve this problem.
// 2. We are defining a helper function dfs which takes the root node and the path as input.
// 3. If the root node is null, we return 0.
// 4. This handles the case where there is no left child or no right child but atleast one child is present.
// 5. We are calculating the path by multiplying the path by 10 and adding the value of the current node.
// 6. If the current node is a leaf node, we return the path.
// 7. Otherwise, we return the sum of the left subtree and the right subtree.
// 8. We call the dfs function with the root node and the path as 0.
// 9. We return the result.