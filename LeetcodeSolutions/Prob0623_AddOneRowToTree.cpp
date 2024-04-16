/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(NULL), right(NULL) {}
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root,int val,int currDepth,int depth)
    {
        if(root == NULL)
            return;
        if(currDepth == depth-1)
        {
            root->left = new TreeNode(val,root->left,NULL);
            root->right = new TreeNode(val,NULL,root->right);
            return;
        }

        dfs(root->left,val,currDepth+1,depth);
        dfs(root->right,val,currDepth+1,depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1)
            {
             return new TreeNode(val,root,NULL);
            }
        
        dfs(root,val,1,depth);
        return root;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Logic explained :
// 1.We will do a DFS traversal.
// 2. If the current depth is equal to the depth-1, then we will add the new node with value val as the left child of the current node and the right child of the current node.
// 3. If the current depth is not equal to the depth-1, then we will recursively call the left and right child of the current node with the current depth+1 and the depth.
// 4. Finally, we will return the root node.