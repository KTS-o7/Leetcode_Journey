// Own solution in two pointer method
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto fastio =[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        int i =0, j= nums.size()-1;
        int max = INT_MIN;
        while(i<j)
        {
            if ((nums[i]-1)*(nums[j]-1)>max)
            {
                max = (nums[i]-1)*(nums[j]-1);
            }
            else if (nums[i]<nums[j])
            {
                i++;
            }
            else 
            {
                j--;
            }
        }
        return max;
        
    }
};

// Prebuilt solution

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        auto fastio =[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            return nullptr;
        };
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1]-1)*(nums[nums.size()-2]-1);  
    }
};