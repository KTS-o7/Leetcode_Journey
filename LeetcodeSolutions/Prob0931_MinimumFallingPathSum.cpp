class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m,vector<int> (n));
        // Initialize a 2D vector 'res' to store minimum path sums
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(i == 0) {
                    // For the first row, directly assign the values from the input matrix
                    res[i][j] = matrix[i][j];
                }
                else if(j == 0) {
                    // For the first column, calculate the minimum path sum from the above row
                    res[i][j] = min(res[i-1][j] + matrix[i][j], res[i-1][j+1] + matrix[i][j]);
                }
                else if(j == n-1) {
                    // For the last column, calculate the minimum path sum from the above row
                    res[i][j] = min(res[i-1][j] + matrix[i][j], res[i-1][j-1] + matrix[i][j]);
                }
                else {
                    // For other columns, calculate the minimum path sum considering the above-left, above, and above-right cells
                    int a = min(res[i-1][j-1] + matrix[i][j], res[i-1][j] + matrix[i][j]);
                    res[i][j] = min(a, res[i-1][j+1] + matrix[i][j]);
                }
            }
        }
        // Return the minimum element from the last row of 'res'
        return *min_element(res[m-1].begin(), res[m-1].end());
    }
};


// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

/*Code explained :
Explanation:
Initialization:

m and n represent the number of rows and columns in the matrix, respectively.
res is a 2D vector used to store the minimum falling path sums for each cell in the matrix.
Dynamic Programming Loop:

The nested loops iterate through each cell in the matrix.
For each cell, the algorithm calculates the minimum falling path sum based on the values from the above row and the adjacent cells.
Boundary Conditions:

Special conditions are handled for the first row, first column, and last column separately.
For the first row, the values are directly assigned from the input matrix.
For the first and last columns, the algorithm considers only two adjacent cells.
Minimum Path Sum Calculation:

The minimum falling path sum is calculated for each cell by considering the values from the above-left, above, and above-right cells.
The minimum value is stored in the res matrix.
Result:

After the dynamic programming loop completes, the minimum element from the last row of the res matrix is returned as the final result.
*/