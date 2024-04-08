class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return l; 
    }
};

// time complexity: O(logn)
// space complexity: O(1)

// Logic Explained :
// 1. We will use binary search to find the index of the target element.
// 2. If the target element is found, we will return the index.
// 3. If the target element is not found, we will return the index where the target element should be inserted.
// 4. We will keep track of the left and right pointers.
// 5. We will calculate the mid index.
// 6. If the mid element is equal to the target element, we will return the mid index.
// 7. If the mid element is less than the target element, we will update the left pointer to mid + 1.
// 8. If the mid element is greater than the target element, we will update the right pointer to mid - 1.
// 9. We will return the left pointer as the index where the target element should be inserted.
// 10. Left pointer will be the index where the target element should be inserted if the element is not found because the left pointer will be pointing to the element which is greater than the target element.