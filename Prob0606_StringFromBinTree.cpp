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
string ans;
    void preOrder(TreeNode* root)
    {
        if(!root)
            return;
        ans+=to_string(root->val);
        
        if(root->left)
        {
            ans.push_back('(');
            preOrder(root->left);
            ans.push_back(')');
        }
        if(root->right)
        {
            if(!root->left)
                ans+="()";
            ans.push_back('(');
            preOrder(root->right);
            ans.push_back(')');
        }

    }
    string tree2str(TreeNode* root) {
        preOrder(root);
        return ans;
    }
};

// Time complexity: O(N)
