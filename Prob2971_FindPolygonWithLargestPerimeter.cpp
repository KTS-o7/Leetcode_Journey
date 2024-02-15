class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        sort(nums.begin(), nums.end());
        int n=nums.size();
        long long perimeter=0, sum=nums[0]+nums[1];
        for(int i=2; i<n; i++){
            if (sum>nums[i])
                perimeter=sum+nums[i];
            sum+=nums[i];
        }
        return perimeter==0?-1:perimeter;
    }
};


// Time complexity: O(nlogn)
// Space complexity: O(1)
// Code explained :
// 1. Sort the array in ascending order.
// 2. Now we will check if sum of previous two elements is greater than the current element, then we will add the current element to the sum and update the perimeter.
// 3. If the sum of previous two elements is not greater than the current element, then we will update the sum with the current element.
// 4. Finally, we will return the perimeter if it is greater than 0, else we will return -1.
// Not updating the perimeter shows that that side cant form a polygon