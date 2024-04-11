class Solution {
public:
    string lastNonEmptyString(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);
        vector<int> freq(26, 0);
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        int max_freq = *max_element(freq.begin(), freq.end());

        string ans = "";
        for (int i = s.size() - 1; i >= 0; --i) {
            char ch = s[i];
            if (freq[ch - 'a'] == max_freq) {
                freq[ch - 'a'] = -1;
                ans = ch + ans;
            }
        }
        return ans;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)
// Logic explained:
// 1. We use a frequency array to store the frequency of each character.
// 2. We find the maximum frequency of a character.
// 3. We iterate through the string from the end and add the character to the answer if its frequency is equal to the maximum frequency.
// 4. If yes we will add the character infront of answer string.
// 5. We return the answer.