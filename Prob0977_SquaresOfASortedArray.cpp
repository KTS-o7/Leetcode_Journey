class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int>ans;
        for(auto it:nums)
            ans.push_back(it*it);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

// Time complexity : O(nlogn)
// Space complexity : O(n)
// Code explained :
// 1. We will iterate through the given array and will push the square of each element in the new array.
// 2. Then we will sort the new array and return it.


// Approach 2: Two pointer approach
class Solution{
    public:
    vector<int> sortedSquares(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n);
        int left = 0;
        int right = n-1;
        for(int i = n-1;i>=0;i--){
            if(abs(nums[left])>abs(nums[right])){
                ans[i] = nums[left]*nums[left];
                left++;
            }
            else{
                ans[i] = nums[right]*nums[right];
                right--;
            }
        }
        return ans;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)
// Code explained :
// 1. We will create a new array of size n.
// 2. We will use two pointers, left and right, and will iterate through the array from the end.
// 3. We will compare the absolute value of the left and right pointers and will push the square of the greater value in the new array.
// 4. We will keep on decrementing the pointer of the greater value.
// 5. We will return the new array.

// Approach 3:
// Using inbuilt power function

class Solution{
    public:
    vector<int> sortedSquares(vector<int>& nums){
        int n = nums.size();
        
        int left = 0;
        int right = n-1;
        vector<int>ans(n);
        for(int i = n-1;i>=0;i--){
            if(abs(nums[left])>=abs(nums[right])){
                ans[i] = pow(nums[left],2);
                left++;
            }
            else{
                ans[i] = pow(nums[right],2);
                right--;
            }
        }
        return ans;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)
// Code explained :
// 1. We will create a new array of size n.
// 2. We will use two pointers, left and right, and will iterate through the array from the end.
// 3. We will compare the absolute value of the left and right pointers and will push the square of the greater value in the new array.
// 4. We will keep on decrementing the pointer of the greater value.
// 5. We will return the new array.