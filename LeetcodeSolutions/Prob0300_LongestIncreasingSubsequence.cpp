class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.empty())
            return 0;

        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int size= nums.size();
        vector<int>dp(size,1);
        
        for(int i=0;i<size;i++)
            for(int j=0;j<i;j++)
                if(nums[i]>nums[j])
                    dp[i]= std::max(dp[i],dp[j]+1);

        
        return * std::max_element(dp.begin(),dp.end());
        
    }
};

// time complexity: O(n^2)
// space complexity: O(n)
/*Explained
A subsequence is an array that can be derived from another array by deleting some or no elements without changing the order of the remaining elements.
For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].

Start: If the given list is empty, there can't be any increasing sequence, so return 0.

Initialization: Create a list dp of the same size as the input list nums. Each element dp[i] in this list represents the length of the longest increasing sequence ending at index i. Initially, set all elements in dp to 1. This initialization assumes that each number is a sequence by itself of length 1.

Calculate the length of increasing sequences: Iterate through the input list from the second element to the last.

For each element at index i, go through all elements before it (from index 0 to i-1).
If the current number (nums[i]) is greater than the number at a previous index (nums[j] where j goes from 0 to i-1), it means we can extend the increasing sequence ending at index i. Update dp[i] to be the maximum of its current value (dp[i]) and dp[j] + 1. This means that at index i, the length of the sequence becomes the maximum of its current length and the length of the sequence ending at index j plus one for the current element.
Find the maximum length: After updating all elements in the dp list, the answer (the length of the longest increasing sequence) is the maximum value in the dp list.

Return: Return the maximum value found in the dp list, which represents the length of the longest increasing sequence in the given input list nums.
*/