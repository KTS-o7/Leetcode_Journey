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
    int findBottomLeftValue(TreeNode* root) {
        int last=0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            int count=q.size();
            for(int i=0;i<count;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                if(i==0)
                    last=curr->val;     
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return last;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Code logic explained :
// We will use breadth first search
// We will use a queue to store the nodes of the tree
// We will start from the root node and push it into the queue
// We will then pop the front node from the queue and check if it is the first node of the level
// If it is the first node of the level, we will store its value in the last variable
// We will then push the left and right child of the node into the queue
// We will repeat the process until the queue is empty
// At the end, we will return the value stored in the last variable