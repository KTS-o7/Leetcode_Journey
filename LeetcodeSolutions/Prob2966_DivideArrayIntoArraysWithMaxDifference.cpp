class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
       
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()/3;i++)
            {
                if(nums[3*i+2]-nums[3*i]>k)
                    return {};
                ans.push_back({nums[3*i],nums[3*i+1],nums[3*i+2]});
                    
            }
        return ans;
        
            
    }
};

//Time complexity: O(nlogn)
//Space complexity: O(1)

/*Code explained :
Sort the array as the order doesnt matter in this question.
-> Check groups of 3 numbers namely 3*i, 3*i+1 and 3*i+2 and run the loop from i = 0 to n/3 where n = nums.size()
The target is that the in the groups difference between any 2 numbers should be less than or equal to k.
Hence to take difference of 1st and 3rd items in the group if its less than k then difference between 2nd and 1st element is obviously less than k.

Make the group into a vector and push to answer.

Since condition is that all numbers of input array nums must be in atleast one group if any group violates this conditon of difference we return empty array saying its not possible to divide.*/