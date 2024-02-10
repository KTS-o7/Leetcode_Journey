class Solution {
public:
    int countSubstrings(string s) {
        int count = 0;
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        for(int i = 0;i<s.size();i++)
        {
            int even = palindromecount(s,i,i+1);
            int odd = palindromecount(s,i,i);
            count += even + odd;
        }
        return count;
    }
private:
    int palindromecount(const string& s,int l,int r)
    {
        int count = 0;
        while(l>=0 && r<s.size() && s[l] == s[r])
        {
            count++;
            l--;
            r++;
        }
        return count;
    }
};

// Time complexity : O(n^2)
// Space complexity : O(1)
// Code explained :
// We are using the concept of expanding around the center. We are iterating through the string and for each character we are checking for the even and odd length palindromes.
// For even length palindromes we are checking for the characters at i and i+1 and for odd length palindromes we are checking for the characters at i and i.
// We are using a helper function to count the number of palindromes for each character. The helper function is taking the string and the left and right index as the input and returning the count of palindromes for that character.  
// The helper function is using the concept of expanding around the center. It is checking for the characters at the left and right index and if they are equal then it is incrementing the count and moving the left and right index to the left and right respectively.
// The helper function is returning the count of palindromes for that character.
// The main function is adding the count of even and odd length palindromes for each character and returning the total count of palindromes.
