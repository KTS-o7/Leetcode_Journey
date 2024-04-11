class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        if(nums1[nums1.size()-1] <nums2[0] || nums1[0]>nums2[nums2.size()-1])
            return -1;
        int f=0,s =0;
        
        while(f<nums1.size() && s<nums2.size())
        {
            if(nums1[f]==nums2[s])
                return nums1[f];

            else if(nums1[f]<nums2[s])
            {
                f++;
            }
            else
                s++;
        }
        return -1;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// code explained :
// Note the input arrays are already sorted in ascending order.
// 1. If the last element of the first array is less than the first element of the second array or the first element of the first array is greater than the last element of the second array, return -1.
// 2. Initialize two pointers f and s to 0.
// 3. Iterate through the arrays using the pointers f and s.
// 4. If the elements at the pointers f and s are equal, return the element.
// 5. If the element at the pointer f is less than the element at the pointer s, increment the pointer f.
// 6. If the element at the pointer f is greater than the element at the pointer s, increment the pointer s.
// 7. Return -1 if no common element is found.