class Solution {
public:
    string reversePrefix(string word, char ch) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        int prefixIndex = INT_MIN;

        for(int i = 0;i<word.size();i++)
        {
            if(word[i]==ch)
            {
                prefixIndex = i;
                break;
            }
        }
        if(prefixIndex == INT_MIN)\
            return word;
        string ans = "";
        for(int i = prefixIndex;i>=0;i--)
            ans += word[i];

        for(int i = prefixIndex+1;i<word.size();i++)
            ans += word[i];

        return ans;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)

// Logic explained :
// 1. Find the index of the character in the string.
// 2. If the character is not present in the string, return the string as it is.
// 3. If the character is present, reverse the string from 0 to the index of the character.
// 4. Append the remaining string as it is.
// 5. Return the final string.