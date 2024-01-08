// Just used for Faster IO

static const int fast_io = []()
{
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    return 0;
}();

// This is the actual solution
class Solution
{

public:
    bool isMonotonic(vector<int> &nums)
    {
        bool flagUP = true, flagDN = true;
        if (nums.size() == 1)
            return true;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i - 1] > nums[i])
            {
                flagUP = false;
                // flagDN =true;
            }
            if (nums[i - 1] < nums[i])
            {
                flagDN = false;
                // flagUP=true;
            }
        }
        if (flagUP || flagDN == true)
            return true;
        return false;
    }
};