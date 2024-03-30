class Solution {
public:
    int func(vector<int>&nums,int k)
    {
        unordered_map<int, int> count;
        int left = 0, result = 0;

    for (int right = 0; right < nums.size(); right++) {
        
        count[nums[right]]++;

        
        while (count.size() > k) {
            count[nums[left]]--;
            if (count[nums[left]] == 0) {
                count.erase(nums[left]);
            }
            left++;
        }

        
        result += right - left + 1;
    }

    return result;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        return func(nums,k) - func(nums,k-1);
    }
};

// Time complexity: O(N)
// Space complexity: O(N)
// Logic explained :
// 1. We will use a sliding window approach to solve this problem.
// 2. We will keep track of the count of each element in the window.
// 3. We will keep track of the left and right pointer of the window.
// 4. We will keep track of the number of distinct elements in the window.
// 5. We will keep track of the result.
// 6. We will iterate over the array and keep track of the count of each element in the window.
// 7. We will increment the right pointer of the window.
// 8. We will check if the number of distinct elements in the window is greater than k.
// 9. If the number of distinct elements in the window is greater than k, we will increment the left pointer of the window and decrement the count of the element at the left pointer of the window.
// 10. If the count of the element at the left pointer of the window is 0, we will erase the element from the count.
// 11. We will update the result by adding the length of the window.
// result += right - left + 1; this is the number of subarrays that start at the left pointer of the window and end at the right pointer of the window.
// This will actually get us the number of subarrays with at most k distinct elements.
// to get the number of subarrays with exactly k elements we need to subtract the number of subarrays with at most k-1 distinct elements from the number of subarrays with at most k distinct elements.