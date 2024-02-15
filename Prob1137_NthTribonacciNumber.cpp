class Solution {
public:
    int tribonacci(int n) {
        if(!n)
            return 0;
        if(n==1)
            return 1;
        if(n==2)
            return 1;
        vector<int>dp(n+1);
        dp[0]= 0;
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++)
            dp[i]= dp[i-1]+dp[i-2]+dp[i-3];
        return dp[n];
    }
};

// Time complexity: O(n)
// Space complexity: O(n)
// Code explained :
// 1. If n is 0, return 0.
// 2. If n is 1, return 1.
// 3. If n is 2, return 1.
// 4. Create a dp array of size n+1 and initialize the first three elements with 0, 1, 1.
// 5. Now, we will iterate from 3 to n and update the dp array with the sum of previous three elements.
// 6. Finally, we will return the nth element of the dp array.
// 7. This is a bottom-up approach.
