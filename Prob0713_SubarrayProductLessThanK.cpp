class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int start= 0, end= 0, prod = 1, ans= 0;
        while(end< nums.size()) {
            prod *= nums[end];
            end++;
            while(start< end&& prod >= k) {
                prod /= nums[start];
                start++;
            }
            ans += end- start;
        }
        return ans;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Logic Explaine : 
// 1. We will use two pointer approach to solve this problem.
// 2. We will keep track of the product of the subarray from start to end.
// 3. If the product is greater than k, we will divide the product by the start element and increment the start pointer.
// 4. We will keep track of the number of subarrays whose product is less than k.
// 5. We will return the number of subarrays whose product is less than k.
// Why does end - start work?
// 1. The number of subarrays ending at end and starting at start is end - start.
// For example, if the array is [10, 5, 2, 6] and k = 100, the subarrays are [10], [10, 5], [5], [5, 2], [2], [2, 6], [6].
// Dry run for the above example :
// 1. start = 0, end = 0, prod = 10, ans = 1-0 = 1
// 2. start = 0, end = 1, prod = 50, ans = 1 + 1-0 = 2
// 3. start = 0, end = 2, prod = 100, ans = 2 + 2-1 = 3
// and so on.