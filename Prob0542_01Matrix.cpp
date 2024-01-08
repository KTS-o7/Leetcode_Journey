class Solution
{
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> dp(n, vector<int>(m, INT_MAX - 2));
        // normal case so will go for top and left only
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (i > 0)
                        dp[i][j] = min(dp[i][j], dp[i - 1][j] + 1); // top
                    if (j > 0)
                        dp[i][j] = min(dp[i][j], dp[i][j - 1] + 1); // left
                }
            }
        }

        // reverse
        for (int i = n - 1; i >= 0; i--)
        {
            for (int j = m - 1; j >= 0; j--)
            {
                if (mat[i][j] == 0)
                    dp[i][j] = 0;
                else
                {
                    if (i < n - 1)
                        dp[i][j] = min(dp[i][j], dp[i + 1][j] + 1); // bottom
                    if (j < m - 1)
                        dp[i][j] = min(dp[i][j], dp[i][j + 1] + 1); // right
                }
            }
        }
        return dp;
    }
};