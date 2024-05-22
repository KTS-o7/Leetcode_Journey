class Solution {
public:
    vector<vector<string>> partition(string s) {
        std::ios::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        vector<vector<string>> result;
        vector<string> path;
        backtrack(s, 0, path, result);
        return result;
    }

private:
    void backtrack(const string& s, int start, vector<string>& path, vector<vector<string>>& result) {
       
        if (start == s.length()) {
            result.push_back(path);
            return;
        }
 
        for (int end = start + 1; end <= s.length(); ++end) {
        
            if (isPalindrome(s, start, end - 1)) {
                path.push_back(s.substr(start, end - start));
            
                backtrack(s, end, path, result);
               
                path.pop_back();
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right) {
     
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }
};

// Time Complexity: O(n * 2^n)
// Space Complexity: O(n)

// Logic explained :
// 1. We are using backtracking to solve this problem.
// 2. We are iterating over the string and checking if the substring is palindrome or not.
// 3. We use a helper function isPalindrome to check if the substring is palindrome or not.
// 4. In the backtrack function first we check if the start is equal to the length of the string, if yes then we push the path into the result.
// 5. If not we generate all the possible substrings and check if they are palindrome or not.
// 6. This substring generation is done as follows
//   a. We start from the start index and keep on increasing the end index.
//   b. We check if the substring is palindrome or not.
//   c. If yes we push the substring into the path and call the backtrack function recursively.
//   d. If not we pop the substring from the path and continue with the next substring.
// 7. We keep on doing this until we reach the end of the string.
// 8. Finally we return the result.