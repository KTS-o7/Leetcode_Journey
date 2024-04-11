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

// Other Solution
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        set<string>src;
        for(int i=0;i<paths.size();i++)
        {
            src.insert(paths[i][0]);
        }
         for(int i=0;i<paths.size();i++)
        {
            if(src.find(paths[i][1])==src.end())
                return paths[i][1];
        }
        return "";
    }
};