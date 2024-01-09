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
    // Helper function to get the leaf nodes of a binary tree and store in a vector
    void getLeaf(TreeNode* root, vector<int>& v) {
        // Check if the node is not null
        if (root) {
            // Traverse the left subtree
            getLeaf(root->left, v);
            
            // If the node is a leaf node, add its value to the vector
            if (root->left == nullptr && root->right == nullptr)
                v.push_back(root->val);
            
            // Traverse the right subtree
            getLeaf(root->right, v);
        }
        // If the node is null, return
        else 
            return;
    }

public:
    // Main function to check if leaf sequences of two binary trees are similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Disable synchronization with C I/O for faster input/output
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // Initialize vectors to store leaf sequences of both trees
        vector<int> v1, v2;

        // Get leaf sequence for the first tree
        getLeaf(root1, v1);

        // Get leaf sequence for the second tree
        getLeaf(root2, v2);

        // Check if the leaf sequences of the two trees are equal
        return v1 == v2;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
/*Algorithm :
getLeaf Helper Function:

This is a recursive function that traverses a binary tree in an in-order manner.
It collects the values of leaf nodes in a vector (v).
The function starts at the root of the tree and traverses the left subtree, then the right subtree.
If a node is a leaf node (both left and right children are null), its value is added to the vector.
leafSimilar Main Function:

This function checks if the leaf sequences of two given binary trees (root1 and root2) are similar.
It uses the getLeaf helper function to obtain the leaf sequences for both trees.
The leaf sequences are stored in vectors (v1 and v2).
The function then checks if the vectors are equal, indicating that the leaf sequences are similar.
*/

/*Code Explained:
getLeaf Helper Function:

The function uses recursive calls to traverse the binary tree and collect leaf nodes' values in the vector v.
It checks if the current node is not null. If not, it traverses the left subtree, adds the value to v if it's a leaf node, and then traverses the right subtree.
If the node is null, the function returns.
leafSimilar Main Function:

It initializes two vectors (v1 and v2) to store the leaf sequences of the two trees.
Calls getLeaf for each tree to populate the leaf sequences in the respective vectors.
Compares the vectors to check if the leaf sequences are equal.
Returns true if the leaf sequences are equal and false otherwise.*/