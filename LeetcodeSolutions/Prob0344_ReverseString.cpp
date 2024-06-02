class Solution {
public:
    void reverseString(vector<char>& s) {
        int start = 0, end = s.size()-1;
        char ch;
        while(start<end)
        {
            ch = s[start];
            s[start] = s[end];
            s[end] = ch;
            ++start;
            --end;
        }
    }
};

// Time Complexity: O(n)
// Space Complexity: O(1)

// Logic explained :
// 1. We are given a vector of characters.
// 2. We need to reverse the string.
// 3. We can do this by swapping the characters from start to end.
// 4. We will keep a start and end pointer.
// 5. We will swap the characters at start and end.
// 6. We will increment the start pointer and decrement the end pointer.
// 7. We will repeat this process until start is less than end.