class Solution {
public:
    // Function to calculate the minimum number of steps to make two strings anagrams
    int minSteps(string s, string t) {
        // Initialize two vectors to store the frequency of each character in strings s and t
        vector<int> s1(26, 0), t1(26, 0);

        // Disable synchronization with C standard streams for faster I/O
        std::ios::sync_with_stdio(false);

        // Untie cin from cout for faster input reading
        cin.tie(nullptr);

        // Iterate through the characters of string s and t
        for (int i = 0; i < s.size(); i++) {
            // Increment the frequency count for the current character in s
            s1[s[i] - 'a']++;
            
            // Increment the frequency count for the current character in t
            t1[t[i] - 'a']++;
        }

        // Initialize a variable to count the mismatched frequencies between s and t
        int match = 0;

        // Iterate through each character in the alphabet (26 letters)
        for (int i = 0; i < 26; i++) {
            // Check if the frequency of the current character in s is greater than in t
            if (s1[i] > t1[i]) {
                // Increment the match count by the difference in frequencies
                match += (s1[i] - t1[i]);
            }
        }

        // Return the total number of steps needed to make s and t anagrams
        return match;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)
/*Code explained :
Initialize Frequency Vectors:

Two vectors, s1 and t1, of size 26 (representing the 26 lowercase letters of the alphabet) are initialized with zeros. These vectors will be used to store the frequency of each character in strings s and t, respectively.
Disable Stream Synchronization (Optional):

The code includes optional lines to disable synchronization with C standard streams (std::ios::sync_with_stdio(false)) and untie cin from cout (cin.tie(nullptr)). These lines are included for faster input/output, but they are not critical to the algorithm.
Character Frequency Counting:

Iterate through each character in strings s and t.
Increment the corresponding position in the frequency vectors (s1 and t1) based on the ASCII value of the character. The subtraction of 'a' ensures that the index corresponds to the position of the character in the alphabet.
Count Mismatched Frequencies:

Initialize a variable match to count the mismatched frequencies between s and t.
Iterate through each character in the alphabet (26 letters).
If the frequency of a character in s is greater than the frequency in t, calculate the difference (s1[i] - t1[i]) and add it to the match count.
Return Result:

The function returns the total count of mismatched frequencies, which represents the minimum number of steps needed to make strings s and t anagrams.
*/