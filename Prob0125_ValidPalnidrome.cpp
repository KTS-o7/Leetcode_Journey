// My solution

class Solution
{
public:
    bool isPalindrome(string s)
    {

        string temp = "";
        for (auto it : s)
        {
            if (isalnum(it))
                temp.push_back(tolower(it));
        }
        cout << temp << endl;
        int start = 0, end = temp.size() - 1;
        while (end > start)
        {
            if (temp[start] != temp[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
};