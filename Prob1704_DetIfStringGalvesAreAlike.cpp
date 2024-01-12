lass Solution {
public:
    // Function to check if the first and second halves of the string have the same number of vowels
    bool halvesAreAlike(string s) {
        // Initialize variables to count vowels in the first and second halves
        int firstHalf = 0, secHalf = 0, size = s.size() / 2;

        // Disable synchronization with C standard streams for faster I/O
        std::ios::sync_with_stdio(false);

        // Untie cin from cout for faster input reading
        cin.tie(nullptr);

        // Loop through the first half of the string
        for (int i = 0; i < size; i++) {
            // Check if the current character is a vowel
            switch (s[i]) {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    // Increment the count for vowels in the first half
                    firstHalf += 1;
                    // No default case needed as there is no additional logic for non-vowel characters

            }

            // Switch to the second half of the string
            switch (s[i + size]) {
                // Check if the current character is a vowel
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                    // Increment the count for vowels in the second half
                    secHalf += 1;
                    // No default case needed as there is no additional logic for non-vowel characters

            }
        }

        // Check if the counts of vowels in the first and second halves are equal
        return firstHalf == secHalf;
    }
};


// Time complexity : O(n)
// Space complexity : O(1)

/*Explaination :
Intuition
The problem involves counting the number of vowels in two halves of a given string and checking if these counts are equal. The solution aims to iterate through the string, count vowels in each half, and then compare the counts.

Approach
Initialize variables firstHalf and secHalf to count vowels in the first and second halves, respectively.
Use two separate loops to iterate through each half of the string.
In each loop, use a switch statement to check if the current character is a vowel. If it is, increment the corresponding count.
After both loops, compare the counts of vowels in the first and second halves.
Return true if the counts are equal, indicating that both halves have the same number of vowels; otherwise, return false.
Complexity
Time complexity: O(n), where n is the length of the input string. The algorithm iterates through each character of the string once.
Space complexity: O(1), as the algorithm uses a constant amount of extra space regardless of the input size.*/