// Approach 1 : Using vectors
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>prefix(nums.size());
        prefix[0]=1;
        vector<int>suffix(nums.size());
        suffix[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++)
            prefix[i]=nums[i-1]*prefix[i-1];

        for(int i= nums.size()-2;i>=0;i--)
            suffix[i]=suffix[i+1]*nums[i+1];

        vector<int>ans(nums.size(),0);
        for(int i = 0;i<nums.size();i++)
            ans[i] = prefix[i]*suffix[i];

        return ans;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Logic explained :
// 1. Create a prefix array and a suffix array.
// 2. Prefix array will store the product of all the elements to the left of the current element.
// 3. Suffix array will store the product of all the elements to the right of the current element.
// 4. Multiply the prefix and suffix arrays to get the answer.


// Approach 2 : Using 2 pointers
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(),1);
        int left = 1;
        int right = 1;
        for(int i = 0;i<nums.size();i++)
        {
            ans[i]*=left;
            left*=nums[i];
        }
        for(int i = nums.size()-1;i>=0;i--)
        {
            ans[i]*=right;
            right*=nums[i];
        }
        return ans;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Logic explained :
// 1. Create a vector to store the answer.
// 2. Create a left variable and a right variable.
// 3. Multiply the left variable with the current element and store it in the answer array.
// 4. Multiply the right variable with the current element and store it in the answer array.
// 5. Return the answer array.
