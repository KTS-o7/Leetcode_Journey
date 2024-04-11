class Solution {
public:
    int maxLengthBetweenEqualCharacters(string& s) {
        auto fastio=[](){
            std::ios::sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
        return nullptr;
        };
        vector<int> alpha(26, -1);
        int n=s.size(), maxLen=-1;
         for (int i = 0; i < n; i++) {
            int idx = s[i]-'a';
            if (alpha[idx]!= -1){

                maxLen= max(maxLen, i-alpha[idx]-1);
            }
            else alpha[idx]=i;
        } 
        return maxLen;    
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
/*Initialization:

vector<int> alpha(26, -1);: Initialize a vector alpha of size 26, representing the English alphabet, where each element is initialized to -1. This vector will store the last index where each character was seen.
Loop Through the String:

for (int i = 0; i < n; i++) { ... }: Iterate through each character in the input string s, where n is the size of the string.
Character Index Calculation:

int idx = s[i] - 'a';: Calculate the index of the current character in the vector alpha. This assumes that the characters in the string are lowercase English letters.
Check if Character is Seen Before:

if (alpha[idx] != -1) { ... }: Check if the current character has been seen before. If yes, update the maximum length variable maxLen if the current substring (between the current index and the last index where the character was seen) is longer.
Update Last Index or Store Current Index:

alpha[idx] = i;: If the character is seen for the first time, store its index in the vector alpha.
Return Maximum Length:

return maxLen;: Return the maximum length between equal characters in the string.
*/