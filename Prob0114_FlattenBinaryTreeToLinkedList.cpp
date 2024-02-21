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
    vector<int>v;
    void preorder(TreeNode* root)
    {
        if(root!=nullptr)
        {
            v.push_back(root->val);
            preorder(root->left);
            preorder(root->right);
        }
    }
public:
    void flatten(TreeNode* root) {
    preorder(root);
    TreeNode* temp = root;
    while(!v.empty() && temp!=nullptr)
    {
        temp->val = *v.begin();
        v.erase(v.begin());
        temp->left = nullptr;
        if (!v.empty()) {
            temp->right = new TreeNode();
            temp = temp->right;
        } else {
            temp->right = nullptr;
        }
    }
}
};

// Time complexity  : O(n)
// Space complexity : O(n)
// Code explained :
// 1. We will do a preorder traversal of the tree and store the values in a vector.
// 2. Then we will traverse the tree again and replace the values of the nodes with the values from the vector.
// 3. We will also make the left child of the node as nullptr and right child as the next value in the vector.
// 4. We will keep doing this until the vector is empty.
// 5. At the end, we will make the right child of the last node as nullptr.
// 6. This will give us the required flattened tree.
// 7. This is a brute force approach and is not the best solution. We will discuss the best solution in the next approach.

// Approach 2:
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
    void flatten(TreeNode* root) {
        if(root == nullptr) return;
        TreeNode* ptr = root;
        while(ptr) {
            if(ptr->left) {
                TreeNode* tmp = ptr->left;
                while(tmp->right) {
                    tmp = tmp->right;
                }
                tmp->right = ptr->right;
                ptr->right = ptr->left;
                ptr->left = nullptr;
            }
            else {
                ptr = ptr->right;
            }
        }
    }
};

// Time complexity  : O(n)
// Space complexity : O(1)
// Code explained :
// 1. We will traverse the tree and if we find a left child, we will find the rightmost node of the left child.
// 2. We will make the right child of the rightmost node as the right child of the current node.
// 3. We will make the left child of the current node as the right child of the current node.
// 4. We will make the left child of the current node as nullptr.
// 5. We will keep doing this until we reach the end of the tree.
