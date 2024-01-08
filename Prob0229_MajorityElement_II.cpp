static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        for(auto i:nums){
            mp[i]++;
        }

        vector<int> ans;
        int x = floor(n/3);
        for(auto i:mp){
            if(i.second > x){
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};