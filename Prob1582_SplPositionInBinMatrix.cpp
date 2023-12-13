// Two pass solution

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        int m = mat.size(), n= mat[0].size();
        vector<int>rowCnt(m,0);
        vector<int>colCnt(n,0);
        for(int i= 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    rowCnt[i]++;
                    colCnt[j]++;
                }
            }
        }
        int Ans = 0;
        for(int i= 0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==1)
                {
                    if(rowCnt[i]==1 && colCnt[j]==1)
                        Ans++;
                }
            }
        }
        return Ans;
        
    }
};



