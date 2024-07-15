class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones= 0;
        int one = 0;
        for(int it:nums){
            if(it == 1){
                one+=1;
            }
            else{
                one = 0;
            }
            ones = max(ones,one);
        }
        return ones;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Explanation:
/*
1. We need to find the maximum number of consecutive 1's in the given array.
2. We will iterate through the array and keep track of the number of consecutive 1's.
3. If we encounter a 1, we will increment the count of 1's.
4. If we encounter a 0, we will reset the count of 1's to 0.
5. We will keep track of the maximum number of consecutive 1's encountered so far.
6. Finally, we will return the maximum number of consecutive 1's.

*/