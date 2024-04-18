class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        int row = grid.size(), col = grid[0].size();
        int peri = 0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]&1)
                {
                    peri+=4;
                    if(i>0 && (grid[i-1][j] & 1))
                        peri-=2;
                    if(j>0 && (grid[i][j-1] & 1))
                        peri-=2;
                }
            }
        }
        return peri;
    }
};

// Time complexity: O(n*m)
// Space complexity: O(1)

// Logic explained :
// 1. We iterate over the grid.
// 2. If the cell is land then add 4 to the perimeter.
// 3. Then we check the left and top of the cell.
// 4. If they are land then we subtract 2 from the perimeter each.
// 5. This is because when two lands are adjacent then they share a side and hence the perimeter is reduced by 2.
// 6. Finally return the perimeter.