// Brute force - Linear search - O(mn)
/*class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {


        int m = matrix.size(), n = matrix[0].size();
        for(int i =0;i<m;i++)
            for(int j = 0;j<n;j++)
                    if(matrix[i][j]==target)
                        return true;
        return false;
        }

};*/

// Time complexity O(log(mn))  Binary Search
// Optimised solution
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        if (matrix.empty())
            return false;
        int m = matrix.size(), n = matrix[0].size();
        int left = 0, right = m * n - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int mid_row = mid / n;
            int mid_col = mid % n;

            if (matrix[mid_row][mid_col] == target)
            {
                return true;
            }
            else if (matrix[mid_row][mid_col] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return false;
    }
};