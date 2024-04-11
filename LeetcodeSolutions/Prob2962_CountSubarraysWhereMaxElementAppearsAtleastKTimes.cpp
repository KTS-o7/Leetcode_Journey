class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int maxElement = *max_element(nums.begin(), nums.end());
        int freqOfMax = 0; 
        long long ans = 0; 
        int start = 0, end = 0; 

        while (end < nums.size()) {
            
            if (nums[end] == maxElement) {
                freqOfMax++;
            }

           
            while (freqOfMax >= k && start <= end) {
                ans += nums.size() - end; 
                if (nums[start] == maxElement) {
                    freqOfMax--; 
                }
                start++; 
            }

            end++; 
        }
        return ans;
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
// Logic explained :
// 1. We will keep track of the maximum element in the array and the frequency of the maximum element.
// 2. We will use two pointers start and end to keep track of the subarray.
// 3. We will keep on increasing the end pointer and keep track of the frequency of the maximum element.
// 4. If the frequency of the maximum element is greater than or equal to k, we will keep on increasing the start pointer and keep track of the number of subarrays that can be formed.
// 5. We will keep on increasing the end pointer until we reach the end of the array.
// The operation ans+=nums.size()-end will keep track of the number of subarrays that can be formed which begin at beginning and end at the end of the array.
// This is because if the maximum element is present at least k times in the subarray, then it will be present at least k times in all the subarrays that can be formed from that subarray.
/*Input: nums = [1,3,2,3,3], k = 2
Output: 6
Explanation: The subarrays that contain the element 3 at least 2 times are: [1,3,2,3], [1,3,2,3,3], [3,2,3], [3,2,3,3], [2,3,3] and [3,3].*/