class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        set<int> s(nums.begin(), nums.end());
        nums.clear();
        for (auto it = s.begin(); it != s.end(); it++)
        {
            nums.push_back(*it);
        }

        cout << "\n"
             << nums.size() << endl;
        return nums.size();
    }
};