class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {

        int cnt = 0, size = nums.size() - 1;
        vector<int> ans(size + 1);

        for (int i = 0; cnt < size + 1; i++)
        {
            if ((nums[i] & 0x01) == 0)
            {
                ans[cnt] = nums[i];
                cnt++;
            }
            else
            {
                ans[size] = nums[i];
                size--;
            }
        }
        return ans;
    }
};