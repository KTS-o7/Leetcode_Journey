
// My solution
class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> ans;
        for (int i = 0; i < n + 1; i++)
            ans.push_back(__builtin_popcount(i));
        return ans;
    }
};

// Optimised solution

class Solution
{
public:
    vector<int> countBits(int n)
    {

        vector<int> ans(n + 1, 0);

        ans[0] = 0;

        for (int i = 1; i <= n; i++)
        {
            if (i & 1)
            {

                ans[i] = 1 + ans[i / 2];
            }
            else
            {

                ans[i] = ans[i / 2];
            }
        }

        return ans;
    }
};