class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(),nums.end());
        vector<vector<int>>dp(nums.size());
        vector<int>res;
        for(int i=0;i<nums.size();i++)
        {
            for(int j= 0;j<i;j++)
            {
                if(nums[i]%nums[j] == 0 && dp[i].size()<dp[j].size())
                    dp[i] = dp[j];
            }
            dp[i].push_back(nums[i]);
            if(res.size()<dp[i].size())
                res = dp[i];
        }
        return res;
    }
};
// Time complexity: O(n^2)
// Space complexity: O(n^2)

/*
Code explained and dry run for the input `[1, 2, 3]`.

## Code Explanation

This code is designed to find the largest divisible subset in an array of integers. Here's a step-by-step breakdown:

1. **Sort the array**: The `sort(nums.begin(),nums.end());` line sorts the array in ascending order. This is important because a number can only be divisible by a number that is smaller than or equal to it.

2. **Initialize the dynamic programming (DP) array**: The `vector<vector<int>>dp(nums.size());` line initializes a 2D vector `dp` with the same size as the input array. Each element of `dp` is a vector that will eventually hold a divisible subset of `nums`.

3. **Iterate over the array**: The outer loop `for(int i=0;i<nums.size();i++)` iterates over each number in the sorted array.

4. **Find divisible numbers**: The inner loop `for(int j= 0;j<i;j++)` iterates over each number that comes before the current number in the sorted array. If the current number `nums[i]` is divisible by a previous number `nums[j]` and the size of `dp[j]` is greater than the size of `dp[i]`, then `dp[i]` is updated to `dp[j]`. This is because `dp[j]` represents the largest divisible subset that `nums[i]` can be added to.

5. **Add the current number to its subset**: The `dp[i].push_back(nums[i]);` line adds the current number to its largest divisible subset.

6. **Update the largest divisible subset**: The `if(res.size()<dp[i].size()) res = dp[i];` line updates the largest divisible subset `res` if the size of `dp[i]` is greater than the size of `res`.

7. **Return the largest divisible subset**: The `return res;` line returns the largest divisible subset.

This algorithm works by building up the solution incrementally. It starts with the smallest numbers and finds the largest divisible subsets for them. Then it uses these subsets to find the largest divisible subsets for larger numbers. This is a classic example of dynamic programming.

## Dry Run

Let's dry run the code with the input `nums = [1, 2, 3]`.

Here's a step-by-step walkthrough:

1. **Sort the array**: After sorting, `nums = [1, 2, 3]`.

2. **Initialize the dynamic programming (DP) array**: `dp = [[], [], []]`.

3. **Iterate over the array**:

   - For `i = 0` (num = 1):
     - No `j < i`, so skip the inner loop.
     - `dp[0].push_back(1)`, so `dp[0] = [1]`.
     - `res = [1]` because `res.size() < dp[0].size()`.

   - For `i = 1` (num = 2):
     - For `j = 0` (num = 1), `2 % 1 == 0` and `dp[1].size() < dp[0].size()`, so `dp[1] = dp[0] = [1]`.
     - `dp[1].push_back(2)`, so `dp[1] = [1, 2]`.
     - `res = [1, 2]` because `res.size() < dp[1].size()`.

   - For `i = 2` (num = 3):
     - For `j = 0` (num = 1), `3 % 1 == 0` and `dp[2].size() < dp[0].size()`, so `dp[2] = dp[0] = [1]`.
     - For `j = 1` (num = 2), `3 % 2 != 0`, so skip.
     - `dp[2].push_back(3)`, so `dp[2] = [1, 3]`.
     - `res` remains `[1, 2]` because `res.size() >= dp[2].size()`.

4. **Return the largest divisible subset**: `return res;` returns `[1, 2]`.

*/