class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
      std::ios::sync_with_stdio(false);
      cin.tie(nullptr);
      cout.tie(nullptr);
      vector<int>mp(nums.size()+1,0);
      vector<int>ans;
      for(int it:nums)
      {
        mp[it]++;
      }

      for(int i = 0;i<mp.size();i++)
      {
        if(mp[i]==2)
            ans.push_back(i);
      }
      return ans;
        
    }
};

// Time complexity : O(n)
// Space complexity : O(n)
// Logic explained :
// 1. Create a vector mp of size n+1 and initialize all elements to 0.
// 2. Traverse through the input vector and increment the count of the element in the mp vector.
// 3. Traverse through the mp vector and if the count of the element is 2, push the element into the answer vector.
// 4. Return the answer vector.