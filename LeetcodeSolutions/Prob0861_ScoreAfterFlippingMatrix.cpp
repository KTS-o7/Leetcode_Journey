class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {

        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        for(int row =0; row<grid.size(); row++)
        {   
            if(grid[row][0] == 0)
            {
                for(int col = 0; col<grid[0].size(); col++)
                {
                    grid[row][col] = !grid[row][col];
                }
            }
        }

        int zero = 0, one = 0;
        
        for(int col=0; col<grid[0].size(); col++)
        {
            for(int row=0; row<grid.size(); row++)
            {
                if(grid[row][col] == 0)
                    zero++;
                else
                    one++;
            }
 vector<int>zeroCnt(grid[0].size(),0);
        vector<int>oneCnt(grid[0].size(),0);
            if(zero > one )
            {
                for(int row=0; row<grid.size(); row++)
                {
                    grid[row][col] = !grid[row][col];
                }
            }
            one = 0;
            zero = 0;
        }

        int answer = 0;
        int temp,base;
         for(int row = 0; row<grid.size(); row++)
         {
            temp = 0;
            base = 0;
            for(int col = grid[0].size()-1;  col>=0; col--)
            {
                if(grid[row][col])
                {
                    temp+= (int)pow(2,base);
                }
                base++;
            }
            answer+= temp;
         }
         return answer;

        
    }
};

// Time Complexity: O(n^2)
// Space Complexity: O(1)
// Logic Explained :
// 1. We first iterate over each row of the matrix and flip the row if the first element of the row is 0.
// 2. This will ensure that the number is maximized as the first element of each row will be 1.
// 3. Next, we iterate over each column of the matrix and count the number of 0s and 1s in each column.
// 4. If the number of 0s in a column is greater than the number of 1s, we flip the column.
// 5. This will ensure that the number is maximized as the number of 1s in each column will be greater than the number of 0s.