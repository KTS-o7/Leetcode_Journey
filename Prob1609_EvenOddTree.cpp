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
    bool isEvenOddTree(TreeNode* root) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(root == NULL)
            return false;
        //bool flag = true;
        int cnt = 0;
        queue<TreeNode*>q;
        TreeNode* temp;
        q.push(root);
        while(!q.empty())
        {
            int size = q.size();
            vector<int>odd;
            vector<int>even;
            for(int i = 0;i<size;i++)
            {
                //cout<<size<<endl;
                temp = q.front();
                q.pop();

                if((temp->val%2) == (cnt%2))
                    return false;
                
                if(temp->val%2)
                    odd.push_back(temp->val);
                else
                    even.push_back(temp->val);
                
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
            //cout<<cnt<<endl;
            cnt++;
            //cout<<cnt<<endl;
            if (!odd.empty()) {
                for (auto i = 0; i < odd.size() - 1; i++)
                    if (odd[i] >= odd[i + 1])
                        return false;
            }
            if (!even.empty()) {
                for (auto i = 0; i < even.size() - 1; i++)
                    if (even[i] <= even[i + 1])
                        return false;
            }
            
            //for(auto s:odd)
              //  cout<<s<<" odd "<<endl;
            //for(auto s:even)
              //  cout<<s<<" even "<<endl;
            
            odd.clear();
            even.clear();
        }
        return true;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Algorithm explained :
// 1. We will use a queue to store the nodes of the tree level by level.
// 2. We will use a cnt variable to keep track of the level of the tree.
// 3. We will use two vectors odd and even to store the values of the nodes at each level.
// 4. We use a for loop inside the while loop so that in one iteration we access only the nodes of the same level.
// 5. If the value of node is odd and level is also odd OR value of node is even and level is also even - we return false.
// 6. If the value of node is odd and level is even OR value of node is even and level is odd - we add the value of the node to the respective vector.
// 7. We check if the odd vector is not empty - if yes we check if the vector is strictly ascending.
// 8. We check if the even vector is not empty - if yes we check if the vector is strictly descending.
// 9. If any of the above conditions are not met - we return false.
// 10. If all the conditions are met - we return true. 