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
    void dfs(TreeNode* root, string str, string& smallest)
    {
        if(root == NULL)
            return;

        str+= char('a'+root->val);
        if(root->left == NULL && root->right == NULL)
        {
            reverse(str.begin(),str.end());
            if(smallest.empty() || str<smallest)
                smallest = str;
            reverse(str.begin(),str.end());
        }

        dfs(root->left,str,smallest);
        dfs(root->right,str,smallest);


    }
    string smallestFromLeaf(TreeNode* root) {
        string small;
        dfs(root,"",small);
        return small;
    }
};


// Time complexity : O(n)
// Space complexity : O(n)

// Logic explained :
// 1. We will do a DFS traversal of the tree.
// 2. We will keep a string str which will store the path from root to leaf.
// 3. If we reach a leaf node, we will reverse the string and check if it is smaller than the smallest string we have found till now.
// 4. If yes, we will update the smallest string.
// 5. We will do this for all the leaf nodes and return the smallest string.
// 6. We will do this recursively for all the nodes in the tree.
// 7. Finally, we will return the smallest string.