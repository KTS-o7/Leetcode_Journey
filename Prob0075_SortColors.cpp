class Solution {
public:
    void sortColors(vector<int>& nums) {
       // sort(nums.begin(),nums.end());
       for(int i = 0;i<nums.size();i++)
       {
           for(int j = i+1;j<nums.size();j++)
           {
               if(nums[i]>nums[j])
            {
                int temp = nums[i];
                nums[i]=nums[j];
                nums[j]=temp;
            }
           }
       }
    }
};

// Time complexity: O(n^2)
// Space complexity: O(1)
//Code explained : 
// Due to small input constraints I have used Bubble Sort.
// They wanted inplace sorting.