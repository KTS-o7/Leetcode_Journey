class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> m;
        m[0] = -1;
        int maxlen = 0, count = 0;
        for (int i = 0; i < nums.size(); i++) 
        {
            count = count + (nums[i] == 1 ? 1 : -1);
            if (m.count(count)) 
            {
                maxlen = max(maxlen, i - m[count]);
            } 
            else 
            {
                m[count] = i;
            }
        }
        return maxlen;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Logic explained:
// 1. Create a map to store the count and the index.
// 2. Initialize the count to 0 and the max length to 0.
// 3. Iterate through the array.
// 4. If the current element is 1, increment the count by 1. Else, decrement the count by 1.
// 5. If the count is already present in the map, update the max length by taking the difference between the current index and the index stored in the map.
// 6. Else, store the count and the index in the map.
// 7. Return the max length.

// Dry Run for an example:
// nums = [0,1,0,1]
// m = {0: -1}
// maxlen = 0, count = 0
// i = 0
// count = 0
// m = {0: -1}
// i = 1
// count = 1
// m = {0: -1, 1: 0}
// i = 2
// count = 0
// maxlen = 2