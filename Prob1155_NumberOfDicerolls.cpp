class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        const int MOD = 1000000007;

        
        if (n * k < target) {
            return 0;
        }

        
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));

        
        dp[0][0] = 1;

        
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= min(i * k, target); j++) {
                for (int temp = 1; temp <= min(k, j); temp++) {
                  
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - temp])%MOD ;
                }
            }
        }

        return static_cast<int>(dp[n][target]);
    }
};

// Time Complexity: O(N*K*target), where N is the number of dice, K is the number of faces per die, and target is the target sum.

// Space Complexity: O(N*target), as we use a 2D array dp of size N*target to store the intermediate results.

/*Constants:

const int MOD = 1000000007;: A constant to represent the modulo value, used to avoid integer overflow.
Base Case Check:

if (n * k < target): If the maximum possible sum of all rolls is less than the target, there's no way to achieve the target. Return 0.
Dynamic Programming Initialization:

vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));: Create a 2D vector dp to store the number of ways to achieve each sum with a certain number of dice.
Base Case Initialization:

dp[0][0] = 1;: There is 1 way to get a sum of 0 with 0 dice.
Dynamic Programming Loop:

Use a triple loop to iterate through the number of dice, the possible sums, and the faces of each die.
dp[i][j] = (dp[i][j] + dp[i - 1][j - temp]) % MOD;: Update the number of ways to get the current sum based on previous results.
Result:

return static_cast<int>(dp[n][target]);: Return the result, which is the number of ways to get the target sum using n dice. Cast it to an integer.

*/