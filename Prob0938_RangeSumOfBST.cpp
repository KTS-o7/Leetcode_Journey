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

int dfs(TreeNode* root,int low, int high)
{
    if(root != NULL)
    {   
        if(low<= root->val && root->val <= high)
            return root->val + dfs(root->left,low,high) + dfs(root->right,low,high);
        else if(root->val>high)
            return dfs(root->left,low,high);
        else
            return dfs(root->right,low,high);
        
    }
    else
        return 0;
    
}
    int rangeSumBST(TreeNode* root, int low, int high) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        return dfs(root,low,high);
        
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Algorithm:
/*Here's the detailed algorithm:

Define a TreeNode structure that represents a node in the BST. Each node contains an integer value, and pointers to its left and right child nodes.

Define a class Solution with two public methods: dfs and rangeSumBST.

The dfs method is a helper function that performs a Depth-First Search (DFS) on the BST. It takes three parameters: a pointer to the root node of the BST, and two integers low and high that define the range. The function returns an integer that is the sum of all node values within the range.

If the root node is not null:
If the value of the root node is within the range, return the value of the root node plus the result of recursively calling dfs on the left and right child nodes.
If the value of the root node is greater than high, return the result of recursively calling dfs on the left child node (since all values in the right subtree will be greater than the root and hence out of range).
If the value of the root node is less than low, return the result of recursively calling dfs on the right child node (since all values in the left subtree will be less than the root and hence out of range).
If the root node is null, return 0 (base case for the recursion).
The rangeSumBST method is the main function that calculates the sum of all node values within the range in the BST. It takes three parameters: a pointer to the root node of the BST, and two integers low and high that define the range. The function returns an integer that is the sum of all node values within the range.

It first disables the synchronization of C++'s standard streams with their C counterparts and unties cin from cout for faster I/O operations.
It then calls the dfs method with the root node and the range as parameters, and returns its result.*/
