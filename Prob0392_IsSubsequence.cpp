class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(!s.size())
            return true;
        int ptr = 0;
        for(int i = 0 ;i<t.size();i++)
        {
            if(t[i] == s[ptr])
                ++ptr;
            if( ptr  == s.size())
                return true;
            
        }
        return false;
        
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Code explained :
// 1. We will iterate through the string t.
// 2. If the current character of t is equal to the current character of s, we will increment the pointer of s.
// 3. If the pointer of s is equal to the size of s, we will return true.
// 4. If we have iterated through the whole string t and the pointer of s is not equal to the size of s, we will return false.
// 5. If the size of s is 0, we will return true.
// 6. We will return false at the end of the function. This is because we have iterated through the whole string t and the pointer of s is not equal to the size of s. This means that the string s is not a subsequence of the string t.
