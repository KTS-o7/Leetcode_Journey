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
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr && t2 == nullptr) return true;
        if (t1 == nullptr || t2 == nullptr) return false;
        return (t1->val == t2->val)
            && isMirror(t1->right, t2->left)
            && isMirror(t1->left, t2->right);
    }

    bool isSymmetric(TreeNode* root) {
       
        return isMirror(root, root);
    }
};
 // Time complexity : O(N)
 // Space complexity : O(N)

 /*Code explained :
 Define a helper function isMirror: This function takes two tree nodes as input, t1 and t2. It checks whether the trees rooted at t1 and t2 are mirror images of each other.
Base cases in isMirror: If both t1 and t2 are null, it returns true because two empty trees are mirror images of each other. If only one of t1 or t2 is null, it returns false because a tree with nodes cannot be a mirror image of an empty tree.
Recursive step in isMirror: If both t1 and t2 are not null, it checks three conditions:
t1’s value equals t2’s value.
The right subtree of t1 is a mirror image of the left subtree of t2.
The left subtree of t1 is a mirror image of the right subtree of t2. If all three conditions are true, t1 and t2 are mirror images of each other.
Check symmetry in the main function: The main function isSymmetric checks whether the tree rooted at root is symmetric. It does this by checking whether the left and right subtrees of root are mirror images of each other, using the isMirror function.
This algorithm effectively checks the symmetry of a binary tree by comparing pairs of nodes in a top-down, depth-first manner. It stops as soon as it finds a pair of nodes that are not mirror images, which makes it efficient. If the tree is symmetric, it visits every node once, so its time complexity is O(n), where n is the number of nodes in the tree. Its space complexity is also O(n) in the worst case due to the space required for the recursion stack in a skewed tree. In the best case (a balanced tree), the space complexity is O(log n).*/