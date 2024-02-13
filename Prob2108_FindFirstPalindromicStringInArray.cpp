class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        int n = words.size(),l,r;
        bool flag;
        for(int i = 0;i<n;++i)
        {
            flag = true;
            l = 0; 
            r = words[i].size()-1;
            while(l<r)
            {
                if(words[i][l] != words[i][r])
                    {
                        flag = false;
                        break;
                    }
                ++l;
                --r;
            }
            if(flag)
                return words[i];

        }
        return "";
        
    }
};

// Time Complexity: O(n*m) where n is the number of words and m is the length of the longest word
// Space Complexity: O(1) as we are not using any extra space
// Code explained :
// Input is a vector of strings
// We are iterating through the vector of strings and checking if the string is palindrome or not
// If the string is palindrome we are returning the string
// If no string is palindrome we are returning an empty string
// We are using two pointers to check if the string is palindrome or not
// We are using a flag to check if the string is palindrome or not
