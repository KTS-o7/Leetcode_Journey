class Solution
{
public:
    // min max -> think of binary search
    int minimizeMax(vector<int> &nums, int p)
    {
        // sort the input first
        sort(nums.begin(), nums.end());
        // the possible difference ranges from 0 to the largest value - the smallest value
        int n = nums.size(), l = 0, r = nums.back() - nums.front();
        // binary search the min max diff
        while (l < r)
        {
            int m = l + (r - l) / 2, cnt = 0;
            for (int i = 1; i < n; i++)
            {
                // we can make a pair
                if (nums[i] - nums[i - 1] <= m)
                {
                    // increase the number of pairs
                    cnt += 1;
                    // increase i by 1
                    // since it is included in the pair already
                    i += 1;
                }
            }
            // not enough pairs, move l pointer excluding m
            if (cnt < p)
                l = m + 1;
            // too many pairs, move r to m
            else
                r = m;
        }
        return l;
    }
};