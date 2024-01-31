class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int>st;
        int size = temperatures.size();
        vector<int>ans(size);
        std::ios::sync_with_stdio(false);
        cin.tie(nullptr);       
         for(int i = 0; i < size; i++) {
            while(!st.empty() && temperatures[st.top()] < temperatures[i]) {
                int id = st.top();
                st.pop();
                ans[id] = i - id;
            }
            st.push(i);
        }
        return ans;
        
    }
};

// time complexity : O(n)
// space complexity : O(n)

/*Code explained :
The selected code is a C++ implementation of a solution to the problem of finding daily temperatures. Here's the algorithm in words:

1. Define a class `Solution` with a public method `dailyTemperatures` that takes a reference to a vector of integers (`temperatures`) as input and returns a vector of integers.

2. Inside the `dailyTemperatures` method, create an empty stack of integers (`st`), get the size of the `temperatures` vector (`size`), and create a vector of integers (`ans`) with the same size as `temperatures`.

3. Use `std::ios::sync_with_stdio(false)` and `cin.tie(nullptr)` to optimize input/output operations.

4. Iterate over the `temperatures` vector from the first element to the last. For each temperature (`temperatures[i]`):

   a. While the stack is not empty and the temperature at the top of the stack (`temperatures[st.top()]`) is less than the current temperature (`temperatures[i]`), do the following:

      i. Get the index at the top of the stack (`id = st.top()`).

      ii. Remove the top element from the stack (`st.pop()`).

      iii. Calculate the difference between the current index and the index at the top of the stack, and store it in the `ans` vector at the position corresponding to the index at the top of the stack (`ans[id] = i - id`).

   b. Push the current index (`i`) onto the stack (`st.push(i)`).

5. After the loop, return the `ans` vector.

This algorithm uses a stack to keep track of the indices of the decreasing temperatures. When a higher temperature is found, it calculates the number of days until a warmer temperature and stores it in the `ans` vector.*/
