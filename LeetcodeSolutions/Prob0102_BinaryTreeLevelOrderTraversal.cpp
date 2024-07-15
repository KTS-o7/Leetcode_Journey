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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr)
            return {};
        TreeNode* temp;
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        
        q.push(root);

        while(!q.empty()){
            vector<int>t;

            for(int i = q.size(); i>0; i--)
            {   
                temp = q.front();
                q.pop();
                t.push_back(temp->val);
                if(temp->left){
                    q.push(temp->left);
                }
                if(temp->right){
                    q.push(temp->right);
                }
                
            }
            ans.push_back(t);            
        }
        return ans;
        
        
    }
};

// Time complexity: O(N)
// Space complexity: O(N)

// Explanation:
/*
1. Create a queue to store the nodes of the binary tree.
2. Push the root node into the queue.
3. While the queue is not empty, create a vector to store the values of the nodes at the current level.
4. Iterate over the nodes at the current level and add their values to the vector.
5. If the nodes have left and right children, push them into the queue.
6. Add the vector to the result vector.
7. Return the result vector. 
*/