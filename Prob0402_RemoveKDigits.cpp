
class Solution {
public:
    string removeKdigits(string nums, int k) {
        std::ios::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(nums.size() == k || nums.size() == 0)
            return "0";
        string  ans = "";
        stack<char> st;
        int idx;
        for(int i = 0; i < nums.size(); i++) {
            if(k==0)
            {
                idx = i; // this is to reduce number of push operations
                break;
            }
            while( !st.empty() && nums[i] < st.top() && k > 0) {
                st.pop();
                k--; 
            }
            st.push(nums[i]);
        }
        while(k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        for(int i = nums.size()-1;i>=idx;i--)
            ans+=nums[i];

        while(!st.empty()) {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
       
        while(!ans.empty() && ans.front() == '0') {
            ans.erase(ans.begin());
        }
        
        if(ans.empty())
            return "0";
        return ans;
    }
};

// Time Complexity: O(n)
// Space Complexity: O(n)

// Logic explained :
// 1. We will use stack to solve this problem.
// 2. We will iterate through the string and check if the current element is less than the top element of the stack.
// 3. If it is less, we will pop the top element of the stack and decrement k.
// 4. We will repeat the above step until the current element is greater than the top element of the stack.
// 5. We will push the current element to the stack.
// 6. We will repeat the above steps until k becomes 0.
// 7. If k is still greater than 0, we will pop the elements from the stack until k becomes 0.
// 8. We will reverse the string and remove the leading zeros.
// 9. If the string is empty, we will return "0".

/*The intuition behind using a monotonic stack in the provided code is to maintain a stack that represents the smallest possible number that can be formed by removing `k` digits from the input number `nums`. The key to understanding this is to recognize that the stack is used to ensure that the digits in the stack are in a non-decreasing order (monotonically increasing). This property is crucial for constructing the smallest possible number.

Here's a breakdown of how the monotonic stack is used in the code:

1. **Initialization**: The stack `st` is initialized as empty. This stack will be used to store the digits of the number in a way that ensures the smallest possible number is formed.

2. **Iterating through `nums`**: The code iterates through each character in `nums`. For each character, it checks if the stack is not empty, the current character is less than the top of the stack, and there are still digits to be removed (`k > 0`). If these conditions are met, it pops the top of the stack and decrements `k`. This ensures that the stack always contains the smallest possible number formed so far.

3. **Pushing the current character**: After the above check, the current character is pushed onto the stack. This ensures that the stack maintains its property of being in non-decreasing order.

4. **Handling remaining removals**: After iterating through all characters in `nums`, if there are still digits to be removed (`k > 0`), the code pops the top of the stack until `k` digits have been removed. This ensures that the final number is the smallest possible number after removing `k` digits.

5. **Constructing the result**: The code then constructs the result by appending the remaining characters in `nums` starting from the index `idx` (which is set to the current index when `k` becomes 0) and then appending the remaining characters in the stack. This ensures that the final number is the smallest possible number after removing `k` digits.

6. **Reversing and removing leading zeros**: Finally, the result is reversed to get the correct order, and any leading zeros are removed.

The intuition behind using a monotonic stack is that it allows the algorithm to efficiently maintain the smallest possible number by ensuring that the digits in the stack are always in non-decreasing order. This property is crucial for constructing the smallest possible number after removing `k` digits. By maintaining this property, the algorithm can efficiently remove the least significant digits that would result in a smaller number, ensuring that the final number is the smallest possible number.*/