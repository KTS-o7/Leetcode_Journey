#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Get the length of the input string
        int size = s.length();

        // If the string has only one character, return 1
        if (size == 1)
            return 1;

        // Initialize pointers for the last character and a temporary pointer
        int l = size - 1, r;

        // Move the last pointer to the last non-space character
        while (s[l] == ' ')
            l--;

        // Set the right pointer to the current position of the last pointer
        r = l;

        // Move the temporary pointer to the start of the last word
        while (s[r] != ' ' && 0 <= l) {
            // Move the temporary pointer to the left
            if (s[l] != ' ')
                l--;
            else
                break; // Break when a space is encountered
        }

        // Calculate and return the length of the last word
        return r - l;
    }
};


// Time Complexity: O(n)
// Space Complexity: O(1)
/*Algorithm:
The algorithm for finding the length of the last word in a string involves iterating through the string in reverse order. The goal is to skip trailing spaces, locate the last word, and determine its length.

Initialization:

Get the length of the input string (size).
If the string has only one character, return 1 (as it is the length of the last word).
Traversing in Reverse:

Initialize a pointer l to the last character of the string.
Move l to the last non-space character in the string.
Locating the Last Word:

Set a pointer r to the current position of l.
Finding the Start of the Last Word:

Move a temporary pointer l to the start of the last word by traversing characters to the left.
Break the loop when a space is encountered.
Calculating Length:

Calculate the length of the last word by subtracting the position of l from the position of r.
Return the calculated length.*/


/* Code explained :
Initialization:

The length of the input string is obtained (size).
Traversing in Reverse:

The pointer l is moved to the last non-space character in the string.
Locating the Last Word:

The pointer r is set to the current position of l.
Finding the Start of the Last Word:

The temporary pointer l is moved to the start of the last word by traversing characters to the left.
The loop breaks when a space is encountered.
Calculating Length:

The length of the last word is calculated by subtracting the position of l from the position of r.
The calculated length is then returned.z
*/