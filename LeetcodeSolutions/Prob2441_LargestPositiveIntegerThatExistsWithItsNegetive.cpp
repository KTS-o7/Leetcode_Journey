class Solution {
public:
    int findMaxK(vector<int>& nums) {
      int res = -1;
        unordered_set<int> numSet(nums.begin(), nums.end());
        for (int num : numSet) {
            if (numSet.find(-num) != numSet.end()) {
                res = max(res, num);
            }
        }
        return res;
    }
};