class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>>v(grid.size(),vector<int>(grid[0].size()));

        if(grid.size()==1 && grid[0].size() ==1  )
            return grid[0][0];

        v[0][0] = grid[0][0];

        for(int i = 1;i<grid.size();i++)
            v[i][0]+=v[i-1][0]+grid[i][0];
            
        for(int i = 1;i<grid[0].size();i++)
            v[0][i]+=v[0][i-1]+grid[0][i];
        


        for(int i = 1;i<grid.size();i++)
            for(int j = 1; j<grid[0].size();j++)
                {
                    v[i][j] = grid[i][j]+min(v[i-1][j],v[i][j-1]);
                }

                
        return v[grid.size()-1][grid[0].size()-1];

        
    }
};
// Time complexity: O(n*m)
// Space complexity: O(n*m)
// Code explained :
// 1. We will create a dp array of the same size as the input array.
// 2. We will initialize the first element of the dp array with the first element of the input array.
// 3. The first row and the first column of the dp array will be initialized with the sum of the previous element and the current element. Because there is only one way to reach the first row and the first column. That is from the previous element. 
// 4. We will iterate through the input array from the second element.
// 5. We will update the dp array with the minimum of the current element and the sum of the previous element and the current element.
// 6. We will return the last element of the dp array. This will be the minimum path sum.
// 7. The dp array will store the minimum path sum to reach the current element.
