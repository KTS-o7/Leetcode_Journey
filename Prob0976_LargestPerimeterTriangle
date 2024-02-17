class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        sort(nums.begin(), nums.end());
        for (int i=nums.size()-3; i>=0; i--){
            if (nums[i] + nums[i+1]> nums[i+2])
                return nums[i] + nums[i+1] + nums[i+2];
        }
        return 0;
    }
};

// Time Complexity: O(nlogn)
// Space Complexity: O(1)
// Code explained :
// Note : any side of a triangle is less than the sum of the other two sides.
// 1. Sort the array in ascending order.
// 2. Start from the end of the array and check if the sum of the ith, i+1th element is greater than the i+2th element.
// 3. If yes, return the sum of the three elements.
// 4. If no, continue the loop and check for the next three elements.
// 5. If no such triplet is found, return 0.
