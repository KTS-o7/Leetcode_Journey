// Approach 1 :  with bitset
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        bitset<100002>check;
        int limit = nums.size();
        for(int i = 0;i<limit;i++)
        {
            if(nums[i]>0 && nums[i]<=limit)
                check.set(nums[i]);
        }

        
        for(int i = 1;i<=limit;i++)
        {
            if(!check.test(i))
                return i;
        }
        return limit+1;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// Logic explained :
// 1. Create a bitset of size 100002 and initialize all elements to 0.
// 2. Traverse through the input vector and set the bit at the index of the element if the element is greater than 0 and less than or equal to the size of the input vector.
// 3. Traverse through the bitset and if the bit is not set at the index i, return i.
// 4. If all the elements are present in the input vector, return the size of the input vector + 1.

// Approach 2 : with circular swapping
class Solution {
    public:
    int firstMissingPositive(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        int curr = 0;
        int limit = nums.size();
        for(int i = 0;i<limit;i++)
        {   curr = nums[i];
            while(curr>0 && curr<=limit && nums[curr-1]!=curr)
                swap(nums[curr-1],curr);
        }
        
        for(int i = 0;i<limit;i++)
        {
            if(nums[i]!=i+1)
                return i+1;
        }
        return limit+1;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// Logic explained :
// 1. Traverse through the input vector and swap the elements such that the element at index i is i+1.
// 2. Traverse through the input vector and if the element at index i is not i+1, return i+1.
// 3. If all the elements are present in the input vector, return the size of the input vector + 1.
