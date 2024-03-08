// Approach 1:
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>count;
        for(int it:nums)
        {
            count[it]++;
        }
        unordered_map<int,int>freq;
        for(auto it:count)
        {
            freq[it.second]+=it.second;
        }
        return (*max_element(freq.begin(),freq.end())).second;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// code explained :
// 1. Create a map count to store the frequency of each element in the array.
// 2. Create a map freq to store the frequency of each frequency.
// 3. Iterate through the count map and store the frequency of each frequency in the freq map.
// 4. Return the maximum frequency from the freq map.


// Approach 2 
class Solution {
public:
    int maxFrequencyElements(std::vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::sort(nums.begin(), nums.end());

        int maxFrequency = 1;
        int currentFrequency = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                currentFrequency++;
            } else {
                currentFrequency = 1;
            }
            maxFrequency = std::max(maxFrequency, currentFrequency);
        }
        if(maxFrequency==1) return nums.size();

        int count = 0;
        currentFrequency = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                currentFrequency++;
            } else {
                currentFrequency = 1;
            }
            if (currentFrequency == maxFrequency) {
                count+=currentFrequency;
            }
        }

        return count;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(1)
// code explained :
// 1. Sort the array.
// 2. Iterate through the array and find the maximum frequency.
// 3. Iterate through the array and find the count of elements with maximum frequency.
// 4. Return the count.