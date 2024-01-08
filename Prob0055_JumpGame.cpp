class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto fastio=[]()  {
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        }();
    int numsSize = nums.size();
    if (numsSize ==1)
    return true;
    else
    {
        int i,jump,flag=0;
        for(i=0;i<numsSize;i++)
        {
           flag = max(nums[i] + i ,flag );
           if(flag <i+1)
           break;

        }
        return  flag >= numsSize-1;
    }
        
    }
};


// Time complexity: O(n)
// Space complexity: O(1)
// fast io code snippet is used to optimise input and output speed
// The above code snippet is a solution to find if the end of the array is reachable from the start of the array when the maximum number of steps that can be taken from a position is the value at that position.