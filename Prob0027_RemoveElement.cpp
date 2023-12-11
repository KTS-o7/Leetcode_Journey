class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt =0 ;
        for(int i = 0;i<nums.size();i++)
        {
            if(nums[i]==val)
                {
                    nums[i] = 51;
                    
                }
            else
                cnt++;
        }
        sort(nums.begin(),nums.end());
      
        return cnt;
        
        
        
    }
};