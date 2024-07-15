class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        bool fr=false,fc= false;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0) {
                    if(i == 0)
                        fr = true;
                    if(j == 0)
                        fc = true;
                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        for (int i = 1; i < rows; i++) {
            for (int j = 1; j < cols; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }

        if(fr) {
        for(int j = 0; j < cols; j++) 
            matrix[0][j] = 0;
        
        }
        if(fc) {
        for(int i = 0; i < rows; i++) 
            matrix[i][0] = 0;
            
        }
    }
};

// Time complexity: O(M*N)
// Space complexity: O(1)

// Explanation:
/*
1. Create two boolean variables fr and fc to keep track of whether the first row and first column of the matrix need to be zeroed out.
2. Iterate through the matrix and if a zero is found, set the corresponding elements in the first row and first column to zero.
3. Iterate through the matrix again, starting from the second row and second column, and if the corresponding element in the first row or first column is zero, set the current element to zero.
4. If fr is true, set all elements in the first row to zero.
5. If fc is true, set all elements in the first column to zero.
*/