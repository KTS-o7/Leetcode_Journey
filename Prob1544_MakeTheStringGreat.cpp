class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (char c : s) {
            if (!st.empty() && abs(st.top() - c) == 32) {
                st.pop();
            } else {
                st.push(c);
            }
        }
        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};

// Time complexity : O(n)
// Space complexity : O(n)

// Logic explained :
// 1. We use a stack here to keep track of elements.
// 2. We iterate through the string and check if the stack is not empty and the absolute difference between the top element of the stack and the current element is 32.
// 3. If it is, we pop the top element of the stack. 
// 4. This is to discard both the capital and lowercase letter.
// 5. If not, we push the current element into the stack.
// 6. We prefix all characters to the answer string to get the final answer in order
// 7. Return the answer string.
