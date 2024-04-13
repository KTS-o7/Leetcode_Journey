class Solution {
public:
    int scoreOfString(string s) {
        std::ios::sync_with_stdio(false);
        int score = 0;
        for(int i = 0;i<s.size()-1;i++)
        {
            score+= abs(s[i]-s[i+1]);
        }
        return score;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)
// Logic explained :
// 1. We will iterate over the string and calculate the absolute difference between the ascii values of the current character and the next character.
// 2. We will add the absolute difference to the score.
// 3. Finally we will return the score.