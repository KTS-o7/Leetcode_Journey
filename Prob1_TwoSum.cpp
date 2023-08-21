/*
1. We will take a map to store the element and its index.
2. We will run a loop from i=0 to n, where n is the size of the array.
3. We will check if the difference of the target and the current element is in the map or not.
4. If it is not present, then we will insert the current element and its index in the map.
5. If it is present, then we will return an array of current index and the index of the difference of the target and the current element. \
*/
// Time Complexity: O(N)
// Space Complexity: O(N)


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        map<int, int> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            // if we don't get the difference, then add the index in map
            if (mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {i, mp[target - nums[i]]};
        }

        return {};
    }
};