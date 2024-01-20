/* QUESTION
You are given an array of integers nums of length n.

The cost of an array is the value of its first element. For example, the cost of [1,2,3] is 1 while the cost of [3,4,1] is 3.

You need to divide nums into 3 disjoint contiguous subarrays.

Return the minimum possible sum of the cost of these subarrays.

 

Example 1:

Input: nums = [1,2,3,12]
Output: 6
Explanation: The best possible way to form 3 subarrays is: [1], [2], and [3,12] at a total cost of 1 + 2 + 3 = 6.
The other possible ways to form 3 subarrays are:
- [1], [2,3], and [12] at a total cost of 1 + 2 + 12 = 15.
- [1,2], [3], and [12] at a total cost of 1 + 3 + 12 = 16.
Example 2:

Input: nums = [5,4,3]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [5], [4], and [3] at a total cost of 5 + 4 + 3 = 12.
It can be shown that 12 is the minimum cost achievable.
Example 3:

Input: nums = [10,3,1,1]
Output: 12
Explanation: The best possible way to form 3 subarrays is: [10,3], [1], and [1] at a total cost of 10 + 1 + 1 = 12.
It can be shown that 12 is the minimum cost achievable.
 

Constraints:

3 <= n <= 50
1 <= nums[i] <= 50
*/

// Solution 
class Solution {
public:
    int minimumCost(std::vector<int>& nums) {
        int n = nums.size();
        
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(4, INT_MAX));

        // Initialize base case
        dp[0][0] = 0;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= 3; ++j) {
                for (int k = j - 1; k < i; ++k) {
                    int currentCost = nums[k];

                    if (dp[k][j - 1] != INT_MAX) {
                        dp[i][j] = std::min(dp[i][j], dp[k][j - 1] + currentCost);
                    }
                }
            }
        }

        // Debug print statement
        //std::cout << "Final dp[n][3]: " << dp[n][3] << std::endl;

        return dp[n][3];
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(n^2)

/* Code Explained 
Problem Description:
Given an array nums of length n, the task is to divide it into three disjoint contiguous subarrays. The cost of an array is defined as the value of its first element. The goal is to minimize the sum of the costs of the three subarrays.

Dynamic Programming Approach:
The dynamic programming approach is used to find the minimum cost by considering subproblems and building up the solution incrementally.

Intuition:
The state dp[i][j] represents the minimum cost of dividing the first i elements into j disjoint contiguous subarrays.
The base case is dp[0][0] = 0, meaning there is no cost if there are no elements and no subarrays.
The recurrence relation is defined by iterating over possible positions to split the array and updating the minimum cost.
Algorithm:
Initialize a 2D array dp with dimensions (n + 1) x 4 and set all values to INT_MAX.
Set the base case dp[0][0] = 0.
Iterate over the array elements from i = 1 to n:
For each i, iterate over the possible number of disjoint subarrays j (from 1 to 3).
For each j, iterate over possible positions k to split the array (from j - 1 to i - 1).
Calculate the cost of the current subarray as nums[k].
Update dp[i][j] by taking the minimum of the current value and the sum of the cost and the minimum cost from the previous subproblem (dp[k][j - 1]).
The answer is stored in dp[n][3], representing the minimum cost of dividing the entire array into three subarrays.
Explanation:
The algorithm explores all possible ways of dividing the array into three disjoint contiguous subarrays and calculates the minimum cost for each configuration. The dynamic programming table (dp) is updated iteratively, considering the cost of the current subarray and the minimum cost from the previous subproblem.

This approach ensures that the algorithm finds the optimal way to divide the array while minimizing the sum of the first elements of the subarrays.

Uncommenting the debug print statement can help visualize the intermediate values in the dynamic programming table during execution.*/