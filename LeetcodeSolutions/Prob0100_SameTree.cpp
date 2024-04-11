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
class Solution
{
public:
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        if (p == NULL && q == NULL)
            return true;
        if (p == NULL && q != NULL)
            return false;
        if (p != NULL && q == NULL)
            return false;
        if (p->val != q->val)
            return false;
        if (isSameTree(p->left, q->left) &&
            isSameTree(p->right, q->right))
            return true;
        else
            return false;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Code explained :
// We are given two binary trees p and q.
// We have to check if they are the same or not.
// We will use recursion to solve this problem.
// We will check if both the trees are NULL, then we will return true.
// If one of the trees is NULL and the other is not, then we will return false.
// If the value of the nodes of the trees is not equal, then we will return false.
// If the left and right subtrees of the trees are the same, then we will return true.

// Approach: Modified for speed
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL && q==NULL)
            return true;
        else if(p == NULL || q==NULL)
            return false;
        else if(p->val != q->val)
            return false;
        else
        return (isSameTree(p->left,q->left)&&
        isSameTree(p->right,q->right));
        
        
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Modification explained :
// We have modified the code to check if one of the trees is NULL, then we will return false.
// If the value of the nodes of the trees is not equal, then we will return false.
// If the left and right subtrees of the trees are the same, then we will return true.