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
    // Helper function to perform a depth-first search on the binary tree
    void dfs(TreeNode* root, int minVal, int maxVal, int* maxDiff)
    {
        // Base case: if the node is null, return
        if(root == nullptr)
            return;
        
        // Update maxDiff to be the maximum of the current maxDiff and the absolute differences
        // between the current node's value and minVal and maxVal
        *maxDiff = std::max(*maxDiff, std::max(std::abs(root->val - minVal), std::abs(root->val - maxVal)));
        
        // Update minVal and maxVal for the next level of the tree
        minVal = std::min(minVal, root->val);
        maxVal = std::max(maxVal, root->val);
        
        // Recursive calls for the left and right children of the current node
        dfs(root->left, minVal, maxVal, maxDiff);
        dfs(root->right, minVal, maxVal, maxDiff);
    }

public:
    // Function to find the maximum difference between a node and its ancestor
    int maxAncestorDiff(TreeNode* root) {
        // Initialize max_diff to 0
        int max_diff = 0;
        
        // Optimize the program for large inputs
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
         
        // Call the dfs function on the root of the tree
        dfs(root, root->val, root->val, &max_diff);
        
        // Return the maximum difference
        return max_diff;
    }
};

// Time complexity: O(n) 
// Space complexity: O(n) Worst case
// Space complexity: O(log n) Average case

/*Explaination
Intuition
The problem is asking for the maximum absolute difference between a node and its ancestor in a binary tree. An intuitive approach is to traverse the tree and keep track of the minimum and maximum values on the path from the root to the current node. For each node, we calculate the absolute difference between the current node's value and the min and max values we've seen so far.

Approach
We use a Depth-First Search (DFS) approach to traverse the tree. We start at the root and recursively visit all nodes in the tree. For each node, we update our maxDiff to be the maximum of the current maxDiff and the absolute differences between the current node's value and minVal and maxVal. We also update minVal and maxVal for the next level of the tree. The DFS function is called on the root of the tree, passing root->val as both the minimum and maximum value, and the address of max_diff.

Complexity
Time complexity: The time complexity of this solution is O(n)O(n)O(n), where nnn is the number of nodes in the tree. This is because we visit each node exactly once.

Space complexity: The space complexity is O(h)O(h)O(h), where hhh is the height of the tree. This is the maximum depth of the recursive call stack.

In the worst case, the tree is skewed and the height is equal to the number of nodes, so the space complexity is O(n)O(n)O(n).

However, in the average case where the tree is balanced, the height is logarithmic in the number of nodes, so the space complexity is O(log⁡n)O(\log n)O(logn).
*/