class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        map<string,int>ans;
        for(int i=0;i<paths.size();i++)
        {
            ans[paths[i][0]]--;
            ans[paths[i][1]]++;
        }
        string dest;
        int max = INT_MIN;
        for(auto it:ans)
        {
            if(it.second>max)
            {
                max = it.second;
                dest = it.first;
            }
        }
        //cout<<ans.size()<<endl;
        return dest;
    }
};

// Time complexity  : O(n)
// Space complexity : O(n)
