class Solution {
    const vector<pair<int,int>>direc = {{1,0},{-1,0},{0,-1},{0,1}};
     
    int checkIfAllNonZeros(vector<vector<int>>& grid){
        int count = 0;
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j] != 0) 
                    count += grid[i][j];
                else 
                    return 0;
            }
        }

        return count;
    }

    int dfs(vector<vector<int>>& grid, int x, int y, const int& row, const int& col)
    {
        if(x<0 || y<0 || x>=row || y>= col || grid[x][y] == 0)
            return 0;
        
        int val = grid[x][y];
        grid[x][y] = 0;
        int localMax = val;
        for(const pair<int,int>& it:direc)
        {
            localMax = max(localMax, val + dfs(grid,x + it.first,y + it.second,row,col));
        }

        grid[x][y] = val;

        return localMax;
    }

public:
    int getMaximumGold(vector<vector<int>>& grid) {
        
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int row = grid.size(), col = grid[0].size();
        int maxVal = 0;

        int count = checkIfAllNonZeros(grid);
        if(count) {
            return count; 
        }
        

        for(int i = 0; i<row; i++)
        {
            for(int j = 0; j<col; j++)
            {
                if(grid[i][j] != 0)
                    maxVal = max(maxVal, dfs(grid,i,j,row,col));
            }
        }

        return maxVal;
        
    }
};

// Time Complexity: O(4^N)
// Space Complexity: O(N)
// Time complexity is O(4^N) because we are exploring all the 4 directions for each cell in the grid.
// Space complexity is O(N) because of the recursive stack space used by the dfs function.

//Logic explained :
// 1. We will first check if all the cells in the grid are non-zero. If yes, then we will return the sum of all the cells.
// 2. We will iterate over all the cells in the grid and for each cell, we will perform a dfs to find the maximum gold that can be collected starting from that cell.
// 3. In the dfs function, we will first check if the cell is out of bounds or if the cell is empty. If yes, then we will return 0.
// 4. We will store the value of the cell in a variable and then set the value of the cell to 0 to mark it as visited.
// 5. We will then iterate over all the 4 directions and for each direction, we will recursively call the dfs function to find the maximum gold that can be collected starting from that cell.
// 6. We will then restore the value of the cell and return the maximum gold that can be collected starting from that cell.
// 7. We will keep track of the maximum gold that can be collected starting from all the cells and return the maximum of all the values.
