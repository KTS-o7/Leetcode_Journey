class Solution {
public:
    void dfs(int i, int j, int& r1, int& c1, int& r2, int& c2,vector<vector<int>>& land){
        if(i < 0 || j < 0 || i >= land.size() || j >= land[0].size() || land[i][j] != 1)
                return;
        land[i][j] = 0;
        r1=min(r1, i), c1=min(c1, j), r2=max(r2, i), c2=max(c2, j);
            dfs(i+1,j, r1, c1, r2, c2, land);
            dfs(i,j+1, r1, c1, r2, c2, land);
            // No need to check top and left because it is given that it is always a rectangle.
            //dfs(i-1,j, r1, c1, r2, c2, land);
            //dfs(i,j-1, r1, c1, r2, c2, land);

    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        std::ios::sync_with_stdio(false);
        int n=land.size();
        int m=land[0].size();
        int r1,r2,c1,c2;
        vector<vector<int>> answer;
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++){
                if(land[i][j]==1){
                    r1=i, c1=j, r2=i, c2=j;
                    dfs(i, j, r1, c1, r2, c2, land);
                    answer.push_back({r1, c1, r2, c2});
                }
            }
        return answer;
    }
};

// Time complexity : O(n*m)
// Space complexity : O(n*m)

// Logic explained :
/*

1. We will use the DFS technique to find the farmland.
2. This is very similar to the number of islands problem. [Check it Out](https://kts-o7.github.io/posts/problem-number-of-islands/).
3. We will iterate over the matrix given only if the current cell is `1`.
4. In the `dfs` function, we will check if the current cell is in bounds and is `1`.
5. If it is, we will mark it as `0` and update the `r1`, `c1`, `r2`, `c2` values.
6. The `r1`, `c1` will be the minimum values of the current cell and the `r2`, `c2` will be the maximum values of the current cell.
7. `r1`, `c1` will be the top left corner and `r2`, `c2` will be the bottom right corner of the farmland.
8. We will call the `dfs` function recursively on the right and bottom cells.
9. We need not to check the top and left cells because it is given that the farmland is always a rectangle.
10. Once the `dfs` function is ended, we will push the `r1`, `c1`, `r2`, `c2` values to the answer array.
*/