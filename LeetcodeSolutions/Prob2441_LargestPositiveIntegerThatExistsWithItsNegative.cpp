class Solution {
public:
    int findMaxK(vector<int>& nums) {
      int res = -1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : numSet) {
            if (numSet.find(-num) != numSet.end()) {
                res = max(res, num);
            }
        }
        return res;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(N)

// Explanation:
// 1. Create a set to store the unique elements of the input array.
// 2. Iterate through the set and check if the negative of the current element is present in the set.
// 3. If it is present, update the result with the maximum of the current element and the result.
// 4. Return the result.