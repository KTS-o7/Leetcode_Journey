class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
         auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>>trp(n,vector<int>(m));
        for(int i= 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                trp[j][i]=matrix[i][j];
            }
        }
        return trp;

        
    }
};

// T(n)=O(n^2) 