class Solution {
public:
    int maxOperations(vector<int>& nums) {
       
        int ans = 0;
        int prev = nums[0] + nums[1];
        
        while (nums.size() >= 2) {
            int a = nums[0];
            nums.erase(nums.begin());
            int b = nums[0];
            nums.erase(nums.begin());
            
            if (a + b == prev) {
                ans++;
            } else {
                break;
            }
        }
        return ans;
        
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic explained:
// 1. We keep removing the first two elements from the vector and check if their sum is equal to the previous sum.
// 2. If it is, we increment the answer.
// 3. If not, we break the loop.
// 4. We return the answer.