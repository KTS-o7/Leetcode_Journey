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
    int diameter;
    int count(TreeNode* root, int& diameter) {
        if (root == NULL) return 0;                         
        int left = count(root->left, diameter);            
        int right = count(root->right, diameter);   
        //cout<<diameter<<" "<<left<<" "<<right<<endl;      
        diameter = max(diameter, left + right);     
        //cout<<diameter<<endl;     
        return max(left, right) + 1;                    
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        std::ios::sync_with_stdio(false);
        diameter = 0;                            
        count(root, diameter);                       
        return diameter;                           
    }
};
// Time complexity: O(n)
// Space complexity: O(n)
// Code logic explained :
// Here we are using a recursive approach to solve the problem.
// We are using a helper function count to calculate the diameter of the tree.
// In the helper function, we are calculating the left and right height of the tree using recursion.
// We are then updating the diameter of the tree using the left and right height.
// We are then returning the maximum height of the left and right subtree + 1.
// Diameter of the leaf nodes will be 1.
// Diameter of the parents of leaf nodes will be sum of the heights of left and right leafnodes + 1.