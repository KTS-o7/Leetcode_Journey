class Solution {
public:
void checkIsland(int row,int col,vector<vector<char>>& grid)
{
    if(row < 0 || col < 0 || row >= grid.size() || col >= grid[0].size() || grid[row][col] != '1')
                return;
            grid[row][col] = '0';
            checkIsland(row - 1, col,grid);
            checkIsland(row + 1, col,grid);
            checkIsland(row, col - 1,grid);
            checkIsland(row, col + 1,grid);
}
    int numIslands(vector<vector<char>>& grid) {
        std::ios::sync_with_stdio(false);
        if(grid.empty() || grid[0].empty())
            return 0;

        int rows = grid.size();
        int cols = grid[0].size();
        int islands = 0;
        for(int row = 0; row < rows; row++) {
            for(int col = 0; col < cols; col++) {
                if(grid[row][col] == '1') {
                    checkIsland(row, col,grid);
                    islands++;
                }
            }
        }

        return islands;
    }
};

// Time Complexity: O(m*n)
// Space Complexity: O(m*n)

// Logic explained :
// 1. We will iterate through the grid and whenever we find a '1' we will call the checkIsland function.
// 2. In the checkIsland function, we will check if the row and col are within the grid and the cell is '1'. 
// 3. If the cell is '1' we will change it to '0' and call the checkIsland function recursively for the 4 directions.
// 4. This way we will change all the connected '1's to '0's and increment the islands count.
// 5. Finally, we will return the islands count.