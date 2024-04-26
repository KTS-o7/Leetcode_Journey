class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& grid) {
        std::ios::sync_with_stdio(false);
        vector<vector<int>>dp(grid.size(),vector<int>(grid[0].size(),-1));
        int rows = grid.size(), cols = grid[0].size();
        int result = INT_MAX,temp;

        for(int j =0;j<cols;j++)
            dp[0][j] = grid[0][j];

        for(int i = 1;i<rows;i++)
        {
            for(int j = 0;j<cols;j++)
            {
                temp = INT_MAX;

                for(int k = 0;k<cols;k++)
                {
                    if(k!=j)
                    {
                        temp = min(temp, grid[i][j]+dp[i-1][k]);
                    }
                }
                dp[i][j] = temp;
            }
        } 

        for(int j = 0;j<cols;j++)
            result = min(result,dp[rows-1][j]);
        
        return result;
    }
};

// Time complexity: O(m*n^2)
// Space complexity: O(m*n)
// m = number of rows, n = number of columns

// Logic explained 
// 1. Create a dp array of size m*n
// 2. Initialize the first row of dp array with the values of the first row of the grid
// 3. The dp array will store the minimum sum of the path till that cell
// 4. For each cell in the dp array, calculate the minimum sum of the path till that cell by considering the minimum sum of the path till the previous row and the current cell
// 5. So for the subsequent rows, We find the minimum value in previous row and add the current cell value to it, but the minimum value must not to be from the same column
// 6. The answer will be minimum value of dp matrix in its final row.
