class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        if(n == 1)return 0;
        if(nums[0] > nums[1])return 0;
        if(nums[n-1] > nums[n-2])return n-1;

        int left = 1,right = nums.size()-2;
        int mid;
        while(left<=right)
        {
            mid = left + (right-left)/2;
            if(nums[mid-1]<nums[mid] && nums[mid]>nums[mid+1])
                return mid;
            else if(nums[mid]<nums[mid+1])
                left = mid+1;
            else
                right = mid-1;
        }
        return mid;
    }
};

// Time Complexity: O(logn)
// Space Complexity: O(1)
// Logic explained:
// 1. We use binary search to find the peak element.
// 2. We check if the mid element is greater than its neighbours.
// 3. If it is, we return the mid element.
// 4. If not, we move to the left or right based on the comparison.

/*binary search has two important aspects.

A sorted array.
Splitting an array into two halves.
We do not have the first one here. Let us think about the second point.

This requires a little brainstroming.

If the mid element is the local maximum. Cool! Return.

But if it isn't, and no two adjacent elements are equal, then either of the elements (or maybe both of them) will be greater than our mid element.

Now whichever side has the greater element, we can go to that side and continue the same process.

Why, you ask ?

Let us say, the element at [mid+1] is greater.

If you are convinced that any array with the given properties will definitely have a local maximum, then the right array will behave exactly like the initial array. Both extremes have numbers smaller than the edge numbers - the right end is already given in the question, and the left end has just been checked by you. That means we can certainly find a local maximum in the right array.

Can we find it in the left array as well ? Of course! There are chances. But we do not need to find each local maximum. So we can safely continue with the right side.*/