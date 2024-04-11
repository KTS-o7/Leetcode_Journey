class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.size() == 1)
            return nums[0];

        vector<int> dp(nums.size());
        dp[0] = nums[0];
        int max_sum = dp[0];

        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i], dp[i - 1] + nums[i]);
            max_sum = max(max_sum, dp[i]);
        }

        return max_sum;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Code explained :
// 1. We will create a dp array of the same size as the input array.
// 2. We will initialize the first element of the dp array with the first element of the input array.
// 3. We will initialize a variable max_sum with the first element of the input array.
// 4. We will iterate through the input array from the second element.
// 5. We will update the dp array with the maximum of the current element and the sum of the previous element and the current element.
// 6. We will update the max_sum with the maximum of the current max_sum and the current element of the dp array.
// 7. We will return the max_sum.
