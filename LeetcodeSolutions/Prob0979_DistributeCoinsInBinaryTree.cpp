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
    int countSteps(TreeNode* root, int& step)
    {
        if( root == nullptr)
            return 0;
        int leftCoin = countSteps(root->left,step);
        int rightCoin = countSteps(root->right,step);
        step += abs(leftCoin) + abs(rightCoin);
        return (root->val -1) + leftCoin + rightCoin;
    }

public:
    int distributeCoins(TreeNode* root) {
        int ans = 0;
        countSteps(root,ans);
        return ans;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)

// Logic explained :
// The idea is to traverse the tree in postorder fashion and for each node, we calculate the number of coins that must be moved to or from this node.
// 1. If the node has 0 coins, then it must receive 1 coin from its parent.
// 2. If the node has more than 1 coin, then it must send the excess coins to its parent.
// 3. The number of coins that must be moved to or from the left and right subtrees are calculated recursively.
// 4. The total number of moves is the sum of the absolute values of the number of coins that must be moved to or from the left and right subtrees.
// 5. The number of coins that must be moved to or from the current node is the sum of the number of coins that must be moved to or from the left and right subtrees plus the number of coins in the current node minus 1.