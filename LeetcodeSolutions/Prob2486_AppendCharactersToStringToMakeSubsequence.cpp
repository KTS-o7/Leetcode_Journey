class Solution {
public:
    int appendCharacters( string s, string t) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int tidx=0,sSize= s.size();
        for(int i=0; i<sSize; i++)
        {
            if(t[tidx] == s[i])
                ++tidx;
        }
        return t.size()-tidx;
        
        
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)

// Explanation:
// We need to find how many characters we need to append to the string s to make string t a subsequence of s.
/*
1. Initialize tidx to 0 and sSize to the size of string s.
2. Iterate through the string s.
3. If the character at index tidx of string t is equal to the character at index i of string s, increment tidx. ( it means we found a character in s that is present in t)
4. Once the loop ends we will have counted the number of characters in s that are present in t.
5. Return the difference between the size of string t and tidx.
*/