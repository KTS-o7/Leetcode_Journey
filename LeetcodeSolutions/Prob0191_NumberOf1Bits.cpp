class Solution {
public:
    int hammingWeight(int n) {
        int set = 0;
        while(n>0)
        {
            if(n&1 == 1)
                set++;
            n = n>>1;
        }
        return set;
        
    }
};

// Time complexity: O(32)
// Space complexity: O(1)

// Explanation:
/*
1. Initialize a variable to count the set number of bits.
2. while n is greater than zero , if LSB is 1 increase count.
3. right shift the n.
4. Return answer.
*/