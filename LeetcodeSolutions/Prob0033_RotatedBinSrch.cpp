class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int mid, low = 0, high = nums.size() - 1, size = nums.size() - 1;
        while (low <= high)
        {
            mid = low + (high - low) / 2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] > nums[size])
            {
                if (target > nums[mid] || target < nums[0])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
            else
            {
                if (target < nums[mid] || target > nums[size])
                    high = mid - 1;
                else
                    low = mid + 1;
            }
        }

        return -1;
    }
};