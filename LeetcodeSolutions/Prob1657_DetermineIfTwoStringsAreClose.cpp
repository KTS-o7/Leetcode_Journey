class Solution {
public:
    // Function to determine if two words are close strings
    bool closeStrings(string word1, string word2) {
        // Disable synchronization with C standard streams for faster I/O
        std::ios::sync_with_stdio(false);

        // Untie cin and cout for faster input and output
        cin.tie(nullptr);
        cout.tie(nullptr);

        // Check if the lengths of the two words are different, if so, they cannot be close
        if (word1.size() != word2.size())
            return false;

        // Initialize maps to store the frequency of each character in both words
        map<char, int> w1, w2;

        // Iterate through each character in both words and update the frequency maps
        for (int i = 0; i < word1.size(); i++) {
            w1[word1[i]]++;
            w2[word2[i]]++;
        }

        // Initialize multisets to store the frequencies of characters in sorted order
        multiset<int> c1, c2;

        // Iterate through the lowercase English alphabet
        for (char i = 'a'; i <= 'z'; i++) {
            // Check conditions for dissimilarity in character frequencies
            if (w1[i] > 0 && w2[i] == 0)
                return false;
            if (w2[i] > 0 && w1[i] == 0)
                return false;

            // Add character frequencies to multisets
            c1.insert(w1[i]);
            c2.insert(w2[i]);
        }

        // Check if the multisets of frequencies are equal, indicating close strings
        if (c1 != c2)
            return false;

        // If all conditions are met, the words are close strings
        return true;
    }
}

// time complexity: O(n)
// space complexity: O(n)
/*Explained:
Intuition
The problem requires determining if two strings are considered "close" based on specific operations: swapping any two characters or transforming every occurrence of one character into another and vice versa. The intuition is that close strings should have the same set of characters with the same frequencies.

Approach
Length Check:

If the lengths of the two input strings, word1 and word2, are different, they cannot be close. In this case, return false.
Frequency Counting:

Initialize two maps, w1 and w2, to store the frequency of each character in both words.
Iterate through each character in both words and update the frequency maps.
Multiset Creation:

Initialize two multisets, c1 and c2, to store the frequencies of characters in sorted order.
Iterate through the lowercase English alphabet and perform the following:
Check for dissimilarity in character frequencies:
If a character is present in word1 but not in word2 or vice versa, return false.
Add the character frequencies to the corresponding multisets.
Check Multiset Equality:

Check if the multisets of frequencies, c1 and c2, are equal. If not, return false.
Result:

If all conditions are met, the words are considered close, and the function returns true.
Algorithm
Check if the lengths of word1 and word2 are different. If true, return false.
Initialize maps w1 and w2 for frequency counting.
Iterate through each character in both words and update the frequency maps.
Initialize multisets c1 and c2 for storing frequencies in sorted order.
Iterate through the lowercase English alphabet and check for dissimilarity in character frequencies. Add frequencies to multisets.
Check if c1 and c2 are equal. If not, return false.
If all conditions are met, return true.*/