class Solution {
public:
    int myAtoi(string s) {
        long long ans = 0;
        bool isNegative = false;
        int i = 0;
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);

        // Skip leading spaces
        while (i < s.size() && s[i] == ' ') {
            i++;
        }

        // Check for optional sign
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            isNegative = (s[i] == '-');
            i++;
        }

        // Process digits and build the number
        while (i < s.size() && isdigit(s[i])) {
            int digit = s[i] - '0';

            // Check for overflow
            if (ans > (INT_MAX - digit) / 10) {
                return isNegative ? INT_MIN : INT_MAX;
            }

            ans = ans * 10 + digit;
            i++;
        }

        return isNegative ? -ans : ans;
    }
};

// Time complexity : O(n)
// Space complexity : O(1)
// n is the length of the input string. We only use a few variables to store the result, so the space complexity is O(1).
// Code explained :
// 1. We start by discarding as many whitespace characters as necessary until the first non-whitespace character is found.
// 2. Once we have the first non-whitespace character, we need to check if it is a valid sign or if it is a digit. We can do this by checking if the character is either ‘+’ or ‘-‘, or if it is a digit. If it is a digit, we can continue with the next steps, otherwise, we should ascertain the sign of the number and continue with the next steps.
// 3. We then build the number and stop when we reach the end of the string or when we find a non-digit character. The number is then given by the digits we have processed and we need to account for the sign of the number.
// 4. While building the number check if it overflows. If it does, we return the maximum or minimum integer value.
// 5. Finally, we return the number with the correct sign.