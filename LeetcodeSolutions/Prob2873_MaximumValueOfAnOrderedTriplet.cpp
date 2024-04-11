//  Approach 1 : Brute Force
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maximum = 0;
        long long temp;
        for(int i=0;i<nums.size();i++)
            for(int j=i+1;j<nums.size();j++)
                for(int k=j+1;k<nums.size();k++)
                {
                    temp = nums[i]-nums[j];
                    temp*=nums[k];
                    maximum = max(maximum,temp);
                }
        return maximum;
    }
};

// Time Complexity: O(n^3)
// Space Complexity: O(1)
// Code explained : 
// 1. We are given an array of integers.
// 2. We need to find the maximum value of a triplet (i, j, k) such that i < j < k  where value is (nums[i]-nums[j])*nums[k].
// 3. We can solve this problem using brute force approach.
// 4. We will use 3 nested loops to iterate through the array and find the maximum value of the triplet.
// 5. We will initialize a variable maximum to 0.
// 6. We will iterate through the array using 3 nested loops.
// 7. We will calculate the value of the triplet using the formula (nums[i]-nums[j])*nums[k].
// 8. We will update the maximum value if the value of the triplet is greater than the current maximum value.
// 9. Finally, we will return the maximum value of the triplet.

