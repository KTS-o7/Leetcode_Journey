class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>m;
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = nums.size();
        for(int i = 0 ;i<n;i++)
            m[nums[i]]++;

        for(auto it:m)
            {
                if(it.second > n/2)
                    return it.first;
            }
        return 0;
        
    }
};
// Time complexity: O(n)
// Space complexity: O(n)
// Code explained :
// We will use a map to store the frequency of each element in the array. Then we will iterate through the map and check if the frequency of any element is greater than n/2, then we will return that element. If no such element is found, we will return 0.
// The time complexity of this approach is O(n) and the space complexity is O(n).

// Approach 2: Boyer-Moore Voting Algorithm
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int candidate = 0;
        for(int num:nums)
        {
            if(count == 0)
                candidate = num;
            if(num == candidate)
                count++;
            else
                count--;
        }
        return candidate;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Code explained
// We will use Boyer More voting algorithm
// We will iterate through the array and if the count is 0, we will update the candidate to the current element. If the current element is the same as the candidate, we will increase the count, else we will decrease the count. At the end, the candidate will be the majority element. The time complexity of this approach is O(n) and the space complexity is O(1).
