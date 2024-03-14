class Solution {
public:
    int binsrch(vector<int>& nums,int target)
    {
        int l =0,r= nums.size()-1;
        int mid = 0;
        while(l<=r)
        {
            mid = l+ (r-l)/2;
            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                l = mid+1;
            else
                r = mid-1;
        }
        return -1;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
                vector<int>ans={-1,-1};
                int prob = binsrch(nums,target);
                if(prob==-1)
                    return ans;
                    cout<<prob<<endl;
                int left=prob,right=prob;
        while(left > 0 && nums[left-1]==target)
        {
            left--;
        }
        while(right < nums.size()-1 && nums[right+1]==target)
        {
            right++;
        }
                ans[0]=left;
                ans[1]=right;
                return ans;
                      
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Logic explained:
// 1. We use binary search to find the first occurence of the target element.
// 2. Then we use two pointers to find the left and right most occurence of the target element.
// 3. We return the left and right most occurence of the target element.
// 4. If the target element is not found, we return {-1,-1}.
// 5. The time complexity is O(logn) and space complexity is O(1).