class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        vector<int> res(nums.size(),0);
        int odd = 0;
        int even = 1;
        for(auto i: nums){
            if(i>0){
                res[odd]=i;
                odd+=2;
            } else {
                res[even]=i;
                even+=2;
            }
        }
        return res;
    }
};
// Time complexity: O(n)
// Space complexity: O(n)
// Code explained :
// 1. We will create a vector of size n and initialize it with 0.
// 2. We will create two pointers odd and even and initialize them with 0 and 1.
// 3. We will iterate through the given array and if the number is positive we will put it at the odd index and increment the odd pointer by 2.
// 4. If the number is negative we will put it at the even index and increment the even pointer by 2.
// 5. Finally, we will return the resultant array.
  