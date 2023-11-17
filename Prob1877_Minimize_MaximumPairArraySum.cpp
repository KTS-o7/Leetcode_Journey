class Solution {
public:
    int minPairSum(vector<int>& nums) {
         auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
       
        
        sort(nums.begin(),nums.end());
        int l=0;
        int r = nums.size()-1;
        int maxSum = 0;
        while(l<r)
        {
            if(maxSum<(nums[l]+nums[r]))
            {
                maxSum = nums[l]+nums[r];
            }
            
            l++;
            r--;

        }
        return maxSum;
    }
};

// Time complexity: O(nlogn)
// Space complexity: O(1)
// The above code snippet calculates the maximum sum of pairs of an array.
// The array is sorted and the maximum sum of pairs is calculated by adding the first and last element of the array.
// The left pointer is incremented and the right pointer is decremented.
// The maximum sum of pairs is returned.
