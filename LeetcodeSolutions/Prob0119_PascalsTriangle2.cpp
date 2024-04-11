class Solution {
public:
    vector<int> getRow(int n) {
    vector<vector<int>>dp(n+1,vector<int>(n+1,0));
    if(n == 0)
        return {1};
    if(n ==1)
        return {1,1};
    dp[0][0] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2;i<=n;i++)
       { 
        dp[i][0] = 1;
        
        for(int j = 1;j<=i;j++)
            dp[i][j] = dp[i-1][j-1]+dp[i-1][j];
       }
    return dp[n];

    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(n^2)
// Code explained:
// We are using a bottom up approach to solve this problem. We are using a 2D array dp to store the pascal's triangle. We are using a for loop to calculate the pascal's triangle from 0 to n. We are using the formula dp[i][j] = dp[i-1][j-1]+dp[i-1][j] to calculate the pascal's triangle. Finally we are returning the value of dp[n] which is the nth row of the pascal's triangle.
// when we are at the ith row, we are calculating the pascal's triangle for the ith row. We are using a for loop to calculate the pascal's triangle for the ith row. We are using the formula dp[i][j] = dp[i-1][j-1]+dp[i-1][j] to calculate the pascal's triangle. This way we are calculating the pascal's triangle for the ith row. Finally we are returning the value of dp[n] which is the nth row of the pascal's triangle.
