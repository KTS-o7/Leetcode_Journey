class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
       int start=-1,ans= 0;
       unordered_map<int,int>freq;
         for (int end = 0; end < nums.size(); end++) {
            freq[nums[end]]++;
            while (freq[nums[end]] > k) {
                start++;
                freq[nums[start]]--;
                
            }
            ans = max(ans, end - start);
        }
        return ans;
    } 
        
};


// Time complexity : O(n)
// Space Complexity O(n)

// Logic explained :
// 1. Create a frequency hasmap to store the frequencies of the intgers in the current window.
// 2. We will keep track of the start of the window.
// 3. We will iterate over the array and increment the frequency of the current element.
// 4. If the frequency of the current element is greater than k, we will increment the start of the window and decrement the frequency of the start element.
// 5. This is to done to check if we have elemenated the element from the window whose frequency is greater than k.
// 6. We will keep track of the maximum length of the subarray whose frequency is less than k.
// 7. We will return the maximum length of the subarray whose frequency is less than k.