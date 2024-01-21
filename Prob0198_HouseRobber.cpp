#include <vector>

class Solution {
public:
    int rob(std::vector<int>& nums) {
        // Get the size of the input array
        int n = nums.size();

        // Create a dynamic programming array to store the maximum robbed amount
        std::vector<int> dp(n, 0);

        // Base case: If there is only one house, rob that house
        dp[0] = nums[0];
        if (n == 1)
            return dp[0];

        // Base case: If there are two houses, rob the one with more money
        dp[1] = std::max(nums[0], nums[1]);
        if (n == 2)
            return dp[1];

        // Iterate over the houses starting from the third one
        for (int i = 2; i < n; i++) {
            // For each house, choose whether to rob it or not
            // The maximum amount robbed at the current house is the maximum of:
            // 1. The amount robbed from the previous house (dp[i-1])
            // 2. The amount robbed two houses ago plus the money at the current house (dp[i-2] + nums[i])
            dp[i] = std::max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        // The final result is the maximum amount robbed after considering all houses
        return dp[n - 1];
    }
};

//Time complexity: O(n)
//Space complexity: O(n)

/* Logic Explained
The code uses a dynamic programming approach to find the maximum amount that can be robbed without alerting the police.

The dp array is used to store the maximum amount that can be robbed up to the i-th house.

Base cases are handled for the first and second houses.

The loop iterates through the houses starting from the third one, calculating the maximum amount robbed at each house.

The final result is the maximum amount robbed after considering all houses.

This approach ensures that the robber maximizes the total amount of money without robbing adjacent houses.





*/
