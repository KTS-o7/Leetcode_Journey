class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size()-1;i>=0;i--)
        {
            if(int(num[i]-'0')%2 != 0)
                return num.substr(0,i+1);
        }
        return "";
    }
};

// Time Complexity: O(N)
// Space Complexity: O(1)
// This code computes the largest odd number from the given string.