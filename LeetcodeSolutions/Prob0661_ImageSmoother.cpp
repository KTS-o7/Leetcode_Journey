class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
            
        };
        int m = img.size() , n = img[0].size();
        vector<vector<int>>smoothImage(m,vector<int>(n,0));

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                int sum = 0;
                int cnt =0;

                for(int x=i-1;x<=i+1;x++)
                {
                    for(int y = j-1;y<=j+1;y++)
                    {
                        if(0<=x && x<m && y<n && 0<=y)
                        {
                            sum+=img[x][y];
                            cnt+=1;
                        }
                    }
                }
                smoothImage[i][j]= sum/cnt;
            }
        }


        return smoothImage;
        
    }
};